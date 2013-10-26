# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros_comm
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/
DIST_SUBDIR=	ros

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - communication-related utilities

LICENSE=	BSD

STACKNAME=	${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include
LIB_DEPENDS=	log4cxx.10:${PORTSDIR}/devel/log4cxx
BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		f2py:${PORTSDIR}/math/py-numpy \
		pilconvert.py:${PORTSDIR}/graphics/py-imaging
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src \
		ROS_BOOST_ROOT=${LOCALBASE} \
		ROS_PACKAGE_PATH=${WRKSRC}
MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
post-patch:
	# fix path to bash
	${GREP} -l -r "^#\!/bin/bash" ${WRKSRC} | ${XARGS} \
	    ${REINPLACE_CMD} -E -e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}

.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in clients messages roscore_migration_rules test tools utilities
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})	
.endfor
# strip and symlink ELF libraries
.for f in clients/cpp/roscpp/lib/libros.so \
    clients/cpp/roscpp_serialization/lib/libroscpp_serialization.so \
    utilities/rostime/lib/librostime.so utilities/xmlrpcpp/lib/libXmlRpc.so \
    utilities/message_filters/lib/libmessage_filters.so \
    utilities/cpp_common/lib/libcpp_common.so tools/rosbag/lib/librosbag.so \
    tools/rosconsole/lib/librosconsole.so \
    tools/topic_tools/lib/libtopic_tools.so \
    tools/rosrecord/lib/librosrecorder.so \
    test/perf_roscpp/lib/libperf_roscpp.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# strip ELF binaries and make them executable
.for f in tools/rosbag/bin/play tools/rosbag/bin/record \
    tools/rosconsole/examples/example tools/topic_tools/bin/drop \
    tools/topic_tools/bin/mux tools/topic_tools/bin/relay \
    tools/topic_tools/bin/switch_mux tools/topic_tools/bin/throttle \
    tools/rosout/rosout tools/rosrecord/bin/rosplay \
    tools/rosrecord/bin/rosrecord test/perf_roscpp/bin/intra_suite \
    test/test_roscpp_serialization_perf/pointcloud_serdes
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
# make scripts executable
.for f in clients/cpp/roscpp/scripts/genmsgtest \
    clients/cpp/roscpp/scripts/gensrv_cpp.py \
    clients/cpp/roscpp/scripts/genmsg_cpp.py \
    clients/roslisp/scripts/make_node_exec \
    clients/roslisp/scripts/roslisp-sbcl-init \
    clients/roslisp/scripts/make_roslisp_image \
    clients/roslisp/scripts/test-genmsg-lisp \
    clients/roslisp/scripts/genmsg_lisp.py \
    clients/roslisp/scripts/test-gensrv-lisp \
    clients/roslisp/scripts/make-roslisp-exec.lisp \
    clients/rospy/scripts/genutil.py clients/rospy/scripts/gensrv_py.py \
    clients/rospy/scripts/genmsg_py.py utilities/roswtf/bin/roswtf \
    tools/rostest/bin/rostest tools/rostest/bin/roslaunch-check.py \
    tools/rostest/nodes/hztest tools/rostopic/bin/rostopic \
    tools/rosbag/bin/rosbag tools/rosbag/scripts/makerule.py \
    tools/rosbag/scripts/fixbag.py tools/rosbag/scripts/fixbag_batch.py \
    tools/rosbag/scripts/fix_msg_defs.py tools/rosbag/scripts/fix_md5sums.py \
    tools/rosbag/scripts/bag2png.py tools/rosbag/scripts/fastrebag.py \
    tools/rosbag/scripts/topic_renamer.py \
    tools/rosbag/scripts/fix_moved_messages.py tools/rosbag/scripts/savemsg.py \
    tools/rosbag/scripts/bagsort.py tools/rosbag/test/latched_sub.py \
    tools/rosbag/test/test_bag.py tools/rosbag/test/latched_pub.py \
    tools/rosconsole/scripts/generate_speed_test.py \
    tools/rosconsole/scripts/generate_macros.py \
    tools/topic_tools/scripts/mux_delete tools/topic_tools/scripts/mux_select \
    tools/topic_tools/scripts/mux_add tools/topic_tools/scripts/mux_list \
    tools/topic_tools/demos/test_throttle tools/topic_tools/demos/test_relay \
    tools/topic_tools/demos/test_mux tools/topic_tools/demos/test_drop \
    tools/roslaunch/bin/roslaunch-console tools/roslaunch/bin/roslaunch \
    tools/rosgraph/nodes/rxgraph tools/rosgraph/nodes/rosgraph \
    tools/rosrecord/scripts/fix_md5sums.py tools/rosrecord/scripts/bag2png.py \
    tools/rosrecord/scripts/fastrebag.py \
    tools/rosrecord/scripts/topic_renamer.py \
    tools/rosrecord/scripts/fix_moved_messages.py \
    tools/rosrecord/scripts/bagsort.py \
    tools/rosrecord/test/test_rosrecord_offline.py \
    tools/rosservice/bin/rosservice \
    test/test_rosmsg/test/test_rosmsg_command_line.py \
    test/test_rosmsg/test/test_rosmsg.py \
    test/test_roslaunch/test/test_roslaunch_remote.py \
    test/test_roslaunch/test/test_roslaunch_launch.py \
    test/test_roslaunch/test/test_xmlloader.py \
    test/test_roslaunch/test/test_roslaunch_dump_params.py \
    test/test_roslaunch/test/test_roslaunch_command_line_online.py \
    test/test_roslaunch/test/test_core.py \
    test/test_roslaunch/test/test_nodeprocess.py \
    test/test_roslaunch/test/env.py \
    test/test_roslaunch/test/test_roslaunch_rlutil.py \
    test/test_roslaunch/test/test_roslaunch_node_args.py \
    test/test_roslaunch/test/test_roslaunch_child.py \
    test/test_roslaunch/test/params_basic.py \
    test/test_roslaunch/test/test_version.py \
    test/test_roslaunch/test/test_roslaunch_server.py \
    test/test_roslaunch/test/test_roslaunch_pmon.py \
    test/test_roslaunch/test/test_roslaunch_parent.py \
    test/test_rospy/nodes/listener.py test/test_rospy/nodes/talker.py \
    test/test_rospy/nodes/publish_on_shutdown.py \
    test/test_rospy/test/listenerpublisher_embed.py \
    test/test_rospy/test/test_rospy_validators.py \
    test/test_rospy/test/test_deregister.py \
    test/test_rospy/test/test_rospy_transport.py \
    test/test_rospy/test/listenerpublisher.py \
    test/test_rospy/test/test_rospy_api.py \
    test/test_rospy/test/test_rospy_tcpros_service.py \
    test/test_rospy/test/test_rospy_rostime.py \
    test/test_rospy/test/test_on_shutdown.py \
    test/test_rospy/test/test_rospy_client.py \
    test/test_rospy/test/test_pubsub_order.py \
    test/test_rospy/test/test_empty_service.py \
    test/test_rospy/test/test_latch.py \
    test/test_rospy/test/test_rospy_names.py \
    test/test_rospy/test/test_embed_msg.py \
    test/test_rospy/test/test_rospy_paramserver.py \
    test/test_rospy/test/test_rospy_service.py \
    test/test_rospy/test/test_rospy_topics.py \
    test/test_rospy/test/test_rospy_numpy.py \
    test/test_rospy/test/test_client_param_server.py \
    test/test_rospy/test/test_gensrv_py.py \
    test/test_rospy/test/test_client_param_api.py \
    test/test_rospy/test/test_rospy_msnode.py \
    test/test_rospy/test/test_rospy_registration.py \
    test/test_rospy/test/test_node.py test/test_rospy/test/test_genmsg_py.py \
    test/test_rospy/test/test_rospy_client_online.py \
    test/test_rospy/test/test_rospy_core.py \
    test/test_rospy/test/test_rospy_exceptions.py \
    test/test_rospy/test/talker test/test_rospy/test/test_rospy_tcpros.py \
    test/test_rospy/test/test_rospy_tcpros_base.py \
    test/test_rospy/test/test_service_order.py \
    test/test_rospy/test/test_service_failure.py \
    test/test_rospy/test/test_rospy_tcpros_pubsub.py \
    test/test_rospy/test/test_basic_services.py \
    test/test_rospy/test/test_rospy_msg.py \
    test/test_rosparam/test/test_rosparam.py \
    test/test_rosparam/test/test_rosparam_command_line_offline.py \
    test/test_rosparam/test/test_rosparam_command_line_online.py \
    test/test_rostopic/test/test_rostopic_unit.py \
    test/test_rostopic/test/test_rostopic.py \
    test/test_rostopic/test/test_rostopic_command_line_online.py \
    test/test_rostopic/test/test_rostopic_command_line_offline.py \
    test/test_rosbag/gen3 test/test_rosbag/scripts/generate_data_3.py \
    test/test_rosbag/scripts/generate_data_2.py \
    test/test_rosbag/scripts/generate_data_1.py \
    test/test_rosbag/current test/test_rosbag/gen2 \
    test/test_rosbag/generate_data test/test_rosbag/gen1 \
    test/test_rosbag/test/migrate_test.py \
    test/test_rosbag/test/random_record.py \
    test/test_rosbag/test/random_play.py \
    test/test_rosgraph/test/test_rosgraph_command_offline.py \
    test/test_rosgraph/test/test_rosgraph_masterapi_online.py \
    test/test_rosnode/test/test_rosnode_command_online.py \
    test/test_rosnode/test/test_rosnode.py \
    test/test_rosnode/test/test_rosnode_command_offline.py \
    test/test_roslib_comm/test/test_roslib_genpy.py \
    test/test_roslib_comm/test/test_md5sums.py \
    test/test_roslib_comm/test/test_roslib_gentools.py \
    test/test_rosservice/nodes/header_echo_server.py \
    test/test_rosservice/test/test_rosservice.py \
    test/test_rosservice/test/test_rosservice_command_line_online.py \
    test/test_rosservice/test/test_rosservice_command_line_offline.py \
    test/test_rosmaster/test/test_rosmaster_validators.py \
    test/test_rosmaster/test/test_rosmaster_registrations.py \
    test/test_rosmaster/test/test_rosmaster_paramserver.py \
    test/test_rostest/test/test_clean_master.py \
    test/test_rostest/test/time_limit_test.py \
    test/test_roswtf/test/test_roswtf_command_line_online.py \
    test/test_roswtf/test/test_roswtf_command_line_offline.py \
    test/test_ros/nodes/fake_time.py test/test_ros/nodes/add_two_ints_server \
    test/test_ros/nodes/testAllCommonFlows \
    test/test_ros/nodes/testMaster test/test_ros/nodes/listener.py \
    test/test_ros/nodes/talker.py test/test_ros/nodes/fail_two_ints_server \
    test/test_ros/nodes/testSlave test/test_ros/nodes/add_two_ints_client \
    test/test_ros/test/test_ps_values.py \
    test/test_ros/test/test_ps_scope_down.py \
    test/test_ros/test/test_ps_get_param.py \
    test/test_ros/test/test_ps_set_param.py \
    test/test_ros/test/test_node_api.py test/test_ros/test/test_master_api.py \
    test/test_ros/test/test_ps_scope_up.py \
    test/test_ros/test/test_ps_private_names.py \
    test/test_ros/test/test_ps_has_param.py \
    test/test_ros/test/test_ps_search_param.py \
    test/test_ros/test/test_ps_encapsulation.py \
    test/test_topic_tools/test/test_mux_delete_add.py \
    test/test_topic_tools/test/test_mux_services.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
