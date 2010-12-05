# New ports collection makefile for: ros
# Date created:	2010-08-01
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ros
PORTVERSION=	1.2.4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTFILES=	ros-${PORTVERSION}.tar.bz2 SWIG-1.3.29-wx.tar.gz \
		gtest-1.5.0.tar.gz
DIST_SUBDIR=	ros
EXTRACT_ONLY=	ros-${PORTVERSION}.tar.bz2

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - core utilities

LICENSE=	BSD

WRKSRC=		${WRKDIR}/ros

CFLAGS+=	-I${LOCALBASE}/include
LIB_DEPENDS=	log4cxx.10:${PORTSDIR}/devel/log4cxx \
		boost_python:${PORTSDIR}/devel/boost-python-libs
# we need cmake and gmake for the build, but the build is triggered by make
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		bash:${PORTSDIR}/shells/bash \
		chrpath:${PORTSDIR}/devel/chrpath \
		cmake:${PORTSDIR}/devel/cmake \
		gmake:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_SITELIBDIR}/paramiko/__init__.py:${PORTSDIR}/security/py-paramiko \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake \
		cppunit-config:${PORTSDIR}/devel/cppunit \
		doxygen:${PORTSDIR}/devel/doxygen \
		epydoc:${PORTSDIR}/devel/epydoc \
		f2py:${PORTSDIR}/math/py-numpy \
		gmake:${PORTSDIR}/devel/gmake \
		dot:${PORTSDIR}/graphics/graphviz \
		pilconvert.py:${PORTSDIR}/graphics/py-imaging \
		sudo:${PORTSDIR}/security/sudo \
		wget:${PORTSDIR}/ftp/wget
USE_GNOME=	pkgconfig pygtk2
USE_PYTHON=	yes
USE_WX=		2.8
WX_COMPS=	python:build python:run
USE_BZIP2=	yes
USE_LDCONFIG=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		EXTRA_CMAKE_FLAGS="-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}" \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		PATH=${PATH}:${WRKSRC}/bin \
		PYTHONPATH=${WRKSRC}/core/roslib/src \
		ROS_BOOST_ROOT=${LOCALBASE} \
		ROS_PACKAGE_PATH= \
		ROS_ROOT=${WRKSRC}
ALL_TARGET=

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} \
		PREFIX=${PREFIX} \
		WX_CONFIG=${WX_CONFIG}

PORTDOCS=	AUTHORS README

post-extract:
	# move 3rdparty distfiles into place
	${MKDIR} ${WRKSRC}/3rdparty/gtest/build
	${CP} ${_DISTDIR}/gtest-1.5.0.tar.gz ${WRKSRC}/3rdparty/gtest/build
	${MKDIR} ${WRKSRC}/3rdparty/wxswig/build
	${CP} ${_DISTDIR}/SWIG-1.3.29-wx.tar.gz ${WRKSRC}/3rdparty/wxswig/build

post-patch:
	# fix path to the wx configure tool and bash
	${REINPLACE_CMD} -E -e "s|wx-config|${WX_CONFIG}|" \
	    ${WRKSRC}/3rdparty/wxswig/manifest.xml
	${GREP} -l -r "^#\!/bin/bash" ${WRKSRC} | ${XARGS} \
	    ${REINPLACE_CMD} -E -e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"
	# temporarily alter how ROS is built for the port build
	${REINPLACE_CMD} -E -e "s|--rosdep-install|--no-rosdep -i --disable-logging|" \
	    ${WRKSRC}/Makefile

pre-build:
.if exists(${LOCALBASE}/lib/libgtest.so)
	# temporarily move libraries from devel/googletest out of the way
	${MKDIR} ${WRKSRC}/googletest_backup
.for f in .a .la .so .so.* _main.a _main.la _main.so _main.so.*
	${MV} ${LOCALBASE}/lib/libgtest${f} ${WRKSRC}/googletest_backup
.endfor
.endif

post-build:
.if exists(${WRKSRC}/googletest_backup/libgtest.so)
	# restore libraries from devel/googletest
.for f in .a .la .so .so.* _main.a _main.la _main.so _main.so.*
	${MV} ${WRKSRC}/googletest_backup/libgtest${f} ${LOCALBASE}/lib
.endfor
.endif
	# restore original ROS Makefile
	${MV} ${WRKSRC}/Makefile.bak ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/ros/ros/bin
	${MKDIR} ${PREFIX}/ros/stacks

.for f in rospack rosplay rosrecord rosstack rxconsole rxloggerlevel
	${LOCALBASE}/bin/chrpath -d ${WRKSRC}/bin/${f}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/ros/ros/bin
	${LN} -s ${PREFIX}/ros/ros/bin/${f} ${PREFIX}/bin/${f}
.endfor
.for f in rosbag rosboost-cfg rosclean rosconfig roscore roscreate-pkg \
    roscreate-stack rosdep rosgraph roslaunch roslaunch-deps roslaunch-logs \
    roslocate rosmake rosmaster rosmsg rosnode rosparam rosrebag rosrun \
    rosservice rossrv rostest rostopic rosversion roswtf rxbag rxdeps rxgraph \
    rxplot
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/ros/ros/bin
	${LN} -s ${PREFIX}/ros/ros/bin/${f} ${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/bin/rospack_nosubdirs ${PREFIX}/ros/ros/bin

.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/ros
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in 3rdparty config core std_msgs std_srvs test tools
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/ros)
.endfor
# strip and symlink libraries to PREFIX/lib (except gtest)
.for f in core/message_filters/lib/libmessage_filters.so \
    core/rosconsole/lib/librosconsole.so core/roscpp/lib/libros.so \
    core/roslib/lib/libroslib.so \
    test/performance/perf_roscpp/lib/libperf_roscpp.so \
    tools/rosbag/lib/librosbag.so tools/rospack/lib/librospack.so \
    tools/rospack/lib/librosstack.so tools/rosrecord/lib/librosrecorder.so \
    tools/rxtools/lib/librxtools.so tools/rxtools/lib/_rxtoolscpp.so \
    tools/topic_tools/lib/libtopic_tools.so 3rdparty/xmlrpcpp/lib/libXmlRpc.so
	${STRIP_CMD} ${PREFIX}/ros/ros/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/ros/${f}
	${LN} -s ${PREFIX}/ros/ros/${f} ${PREFIX}/lib
.endfor
# strip gtest libraries
.for f in 3rdparty/gtest/gtest/lib/libgtest.so.0 \
    3rdparty/gtest/gtest/lib/libgtest_main.so.0
	${STRIP_CMD} ${PREFIX}/ros/ros/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/ros/${f}
.endfor
# strip ELF binaries and make them executable
.for f in 3rdparty/wxswig/bin/swig-real core/genmsg_cpp/genmsg_java \
    core/genmsg_cpp/genmsg_lisp core/genmsg_cpp/genmsg_oct \
    core/genmsg_cpp/gensrv_java core/genmsg_cpp/gensrv_lisp \
    core/genmsg_cpp/gensrv_oct core/rosout/rosout \
    test/performance/perf_roscpp/bin/intra_suite \
    test/performance/test_roscpp_serialization_perf/pointcloud_serdes \
    test/test_roscpp/bin/check_master \
    test/test_roscpp/bin/get_master_information test/test_roscpp/bin/handles \
    test/test_roscpp/bin/incrementing_sequence test/test_roscpp/bin/inspection \
    test/test_roscpp/bin/intraprocess_subscriptions \
    test/test_roscpp/bin/latching_publisher  \
    test/test_roscpp/bin/loads_of_publishers \
    test/test_roscpp/bin/log test/test_roscpp/bin/multiple_init_fini \
    test/test_roscpp/bin/multiple_subscriptions \
    test/test_roscpp/bin/name_remapping \
    test/test_roscpp/bin/name_remapping_with_ns \
    test/test_roscpp/bin/namespaces \
    test/test_roscpp/bin/nonconst_subscriptions \
    test/test_roscpp/bin/param_update_test \
    test/test_roscpp/bin/parameter_validation test/test_roscpp/bin/params \
    test/test_roscpp/bin/pub_sub test/test_roscpp/bin/publish_constantly \
    test/test_roscpp/bin/publish_empty test/test_roscpp/bin/publish_n_fast \
    test/test_roscpp/bin/publish_onsub \
    test/test_roscpp/bin/publish_unadvertise \
    test/test_roscpp/bin/publisher_for_star_subscriber \
    test/test_roscpp/bin/real_time_test test/test_roscpp/bin/service_adv \
    test/test_roscpp/bin/service_adv_a \
    test/test_roscpp/bin/service_adv_multiple \
    test/test_roscpp/bin/service_adv_unadv test/test_roscpp/bin/service_call \
    test/test_roscpp/bin/service_call_expect_b \
    test/test_roscpp/bin/service_call_repeatedly \
    test/test_roscpp/bin/service_callback_types \
    test/test_roscpp/bin/service_wait_a_adv_b \
    test/test_roscpp/bin/sim_time_test test/test_roscpp/bin/sub_pub \
    test/test_roscpp/bin/subscribe_empty test/test_roscpp/bin/subscribe_n_fast \
    test/test_roscpp/bin/subscribe_resubscribe \
    test/test_roscpp/bin/subscribe_retry_tcp \
    test/test_roscpp/bin/subscribe_self test/test_roscpp/bin/subscribe_star \
    test/test_roscpp/bin/subscribe_unsubscribe \
    test/test_roscpp/bin/subscribe_unsubscribe_repeatedly \
    test/test_roscpp/bin/subscription_callback_types \
    test/test_roscpp/bin/timer_callbacks test/test_roscpp/bin/wait_for_message \
    test/test_roscpp_serialization/bin/builtin_types \
    test/test_roscpp_serialization/bin/pre_deserialize tools/rosbag/bin/play \
    tools/rosbag/bin/record tools/rosrecord/bin/rosplay \
    tools/rosrecord/bin/rosrecord tools/rxtools/bin/rxconsole \
    tools/rxtools/bin/rxloggerlevel tools/topic_tools/bin/drop \
    tools/topic_tools/bin/mux tools/topic_tools/bin/relay \
    tools/topic_tools/bin/switch_mux tools/topic_tools/bin/throttle \
    tools/topic_tools/test/test_shapeshifter
	${STRIP_CMD} ${PREFIX}/ros/ros/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/ros/${f}
	${CHMOD} 0555 ${PREFIX}/ros/ros/${f}
.endfor
# make scripts executable
.for f in 3rdparty/gtest/gtest/bin/gtest-config 3rdparty/wxswig/bin/swig \
    core/mk/make_pydev_project.py core/rosbuild/bin/check_same_directories.py \
    core/rosbuild/bin/checkout_latest_stable \
    core/rosbuild/bin/create_release.py core/rosbuild/bin/download_checkmd5.py \
    core/rosbuild/bin/makestackdist core/rosbuild/bin/package_source.py \
    core/rosbuild/bin/roscheck \
    core/rosbuild/bin/rosgcov core/rosbuild/bin/rosgcov_summarize \
    core/rosbuild/bin/rosmakeall core/rosbuild/bin/rosmakeall_osx \
    core/rosbuild/bin/rosmakeall_stackdist core/rosbuild/bin/rossvnignore \
    core/rosbuild/bin/rostar core/rosbuild/tests/count_cores.py \
    core/rosconsole/scripts/generate_macros.py \
    core/rosconsole/scripts/generate_speed_test.py \
    core/roscpp/scripts/genmsg_cpp.py core/roscpp/scripts/genmsgtest \
    core/roscpp/scripts/gensrv_cpp.py core/roslib/scripts/gendeps \
    core/roslib/scripts/pythontest core/roslisp/s-xml-rpc/test/test.b64 \
    core/roslisp/scripts/genmsg_lisp.py core/roslisp/scripts/make_node_exec \
    core/roslisp/scripts/make_roslisp_image core/rosout/rosout_agg_listener \
    core/rosout/rosout_talker core/rospy/scripts/genmsg_py.py \
    core/rospy/scripts/gensrv_py.py test/rostest/bin/catunit \
    test/rostest/bin/cleanunit test/rostest/bin/coverage-html \
    test/rostest/bin/roslaunch-check.py test/rostest/bin/rostest \
    test/rostest/bin/rostest-check-results test/rostest/bin/rostest-results \
    test/rostest/bin/test-results-dir test/rostest/nodes/hztest \
    test/rostest/test/time_limit_test.py \
    test/test_ros/nodes/add_two_ints_client \
    test/test_ros/nodes/add_two_ints_server \
    test/test_ros/nodes/fail_two_ints_server test/test_ros/nodes/listener.py \
    test/test_ros/nodes/talker.py test/test_ros/nodes/testAllCommonFlows \
    test/test_ros/nodes/testMaster test/test_ros/nodes/testSlave \
    test/test_ros/test/test_master_api.py test/test_ros/test/test_node_api.py \
    test/test_ros/test/test_ps_encapsulation.py \
    test/test_ros/test/test_ps_get_param.py \
    test/test_ros/test/test_ps_has_param.py \
    test/test_ros/test/test_ps_private_names.py \
    test/test_ros/test/test_ps_scope_down.py \
    test/test_ros/test/test_ps_scope_up.py \
    test/test_ros/test/test_ps_search_param.py \
    test/test_ros/test/test_ps_set_param.py \
    test/test_ros/test/test_ps_values.py test/test_ros/test/test_roslocate.py \
    test/test_rosbag/current test/test_rosbag/gen1 test/test_rosbag/gen2 \
    test/test_rosbag/gen3 test/test_rosbag/generate_data \
    test/test_rosbag/scripts/generate_data_1.py \
    test/test_rosbag/scripts/generate_data_2.py \
    test/test_rosbag/scripts/generate_data_3.py \
    test/test_rosbag/test/migrate_test.py test/test_rosbag/test/random_play.py \
    test/test_rosbag/test/random_record.py test/test_rosbagmigration/current \
    test/test_rosbagmigration/gen1 test/test_rosbagmigration/gen2 \
    test/test_rosbagmigration/gen3 test/test_rosbagmigration/generate_data \
    test/test_rosbagmigration/scripts/generate_data_1.py \
    test/test_rosbagmigration/scripts/generate_data_2.py \
    test/test_rosbagmigration/scripts/generate_data_3.py \
    test/test_rosbagmigration/test/migrate_test.py \
    test/test_rosgraph/test/test_rosgraph_masterapi_online.py \
    test/test_roslaunch/test/env.py test/test_roslaunch/test/params_basic.py \
    test/test_roslaunch/test/test_roslaunch_command_line_online.py \
    test/test_roslaunch/test/test_xmlloader.py \
    test/test_roslib/test/fake_node.py \
    test/test_roslib/test/test_roslib_masterapi_online.py \
    test/test_rosmake/test/test_parallel_build.py \
    test/test_rosnode/test/test_rosnode_command_online.py \
    test/test_rospack/test/rosbar/scripts/genmsg_bar \
    test/test_rospack/test/rosfoo/scripts/genmsg_foo \
    test/test_rospack/test/utest_rosstack.py \
    test/test_rosparam/test/test_rosparam.py \
    test/test_rosparam/test/test_rosparam_command_line_online.py \
    test/test_rospy/nodes/listener.py \
    test/test_rospy/nodes/publish_on_shutdown.py \
    test/test_rospy/nodes/talker.py test/test_rospy/test/listenerpublisher.py \
    test/test_rospy/test/listenerpublisher_embed.py \
    test/test_rospy/test/talker test/test_rospy/test/test_basic_services.py \
    test/test_rospy/test/test_client_param_api.py \
    test/test_rospy/test/test_client_param_server.py \
    test/test_rospy/test/test_deregister.py \
    test/test_rospy/test/test_embed_msg.py \
    test/test_rospy/test/test_empty_service.py \
    test/test_rospy/test/test_latch.py test/test_rospy/test/test_node.py \
    test/test_rospy/test/test_on_shutdown.py \
    test/test_rospy/test/test_pubsub_order.py \
    test/test_rospy/test/test_rospy_client_online.py \
    test/test_rospy/test/test_service_failure.py \
    test/test_rospy/test/test_service_order.py \
    test/test_rosrecord/scripts/generate_data.py \
    test/test_rosrecord/test/random_play.py \
    test/test_rosrecord/test/random_pub_node.py \
    test/test_rosrecord/test/random_record.py \
    test/test_rosrecord/test/rename_test.py \
    test/test_rosservice/test/test_rosservice.py \
    test/test_rosservice/test/test_rosservice_command_line_online.py \
    test/test_rostopic/test/test_rostopic.py \
    test/test_rostopic/test/test_rostopic_command_line_online.py \
    test/test_roswtf/test/test_roswtf_command_line_online.py \
    tools/rosbag/bin/rosbag tools/rosbag/scripts/bag2png.py \
    tools/rosbag/scripts/bagsort.py tools/rosbag/scripts/fastrebag.py \
    tools/rosbag/scripts/fix_md5sums.py \
    tools/rosbag/scripts/fix_moved_messages.py tools/rosbag/scripts/fixbag.py \
    tools/rosbag/scripts/fixbag_batch.py tools/rosbag/scripts/makerule.py \
    tools/rosbag/scripts/savemsg.py tools/rosbag/scripts/slash.py \
    tools/rosbag/scripts/topic_renamer.py tools/rosbag/test/latched_pub.py \
    tools/rosbag/test/latched_sub.py tools/rosbagmigration/scripts/checkbag.py \
    tools/rosbagmigration/scripts/fixbag.py \
    tools/rosbagmigration/scripts/fixbag_batch.py \
    tools/rosbagmigration/scripts/makerule.py \
    tools/rosbagmigration/scripts/savemsg.py \
    tools/rosdep/installers/preinstall.macports tools/rosdep/scripts/rosdep \
    tools/rosdoc/rosdoc tools/rosdoc/scripts/checkout.py \
    tools/rosdoc/scripts/upload tools/rosemacs/poll-rosnode \
    tools/rosemacs/poll-rostopic tools/rosgraph/nodes/rosgraph \
    tools/rosgraph/nodes/rxgraph tools/roslaunch/bin/roslaunch \
    tools/roslaunch/bin/roslaunch-console tools/rospack/markstack \
    tools/rospack/rosalldeps tools/rospack/rosallpkgs \
    tools/rospack/roscachesvncert tools/rospack/rospack_lite.py \
    tools/rospack/rossearch tools/rosrecord/scripts/bag2png.py \
    tools/rosrecord/scripts/bagsort.py tools/rosrecord/scripts/fastrebag.py \
    tools/rosrecord/scripts/fix_md5sums.py \
    tools/rosrecord/scripts/fix_moved_messages.py \
    tools/rosrecord/test/test_rosrecord_offline.py \
    tools/rosservice/bin/rosservice tools/rostopic/bin/rostopic \
    tools/roswtf/bin/roswtf tools/rxbag/scripts/rxbag \
    tools/rxtools/nodes/rxplot tools/topic_tools/demos/test_drop \
    tools/topic_tools/demos/test_mux tools/topic_tools/demos/test_relay \
    tools/topic_tools/demos/test_throttle tools/topic_tools/scripts/mux_add \
    tools/topic_tools/scripts/mux_delete tools/topic_tools/scripts/mux_list \
    tools/topic_tools/scripts/mux_select \
    tools/topic_tools/test/test_mux_delete_add.py \
    tools/topic_tools/test/test_mux_services.py tools/xdot/dot_viewer.py
	${CHMOD} 0555 ${PREFIX}/ros/ros/${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
