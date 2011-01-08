# New ports collection makefile for: common
# Date created:	2010-11-25
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ros-common
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTFILES=	common-${PORTVERSION}.tar.bz2 bfl-31655.tar.gz \
		yaml-cpp-0.2.2.tar.gz
DIST_SUBDIR=	ros
EXTRACT_ONLY=	common-${PORTVERSION}.tar.bz2

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - common utilities

#LICENSE_COMB=	multi
#LICENSE=	BSD Zlib MIT LGPL #which?

STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_SDL=	sdl image

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common_msgs:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

post-extract:
	${MKDIR} ${WRKSRC}/bfl/build
	${CP} ${_DISTDIR}/bfl-31655.tar.gz ${WRKSRC}/bfl/build
	${MKDIR} ${WRKSRC}/yaml_cpp/build
	${CP} ${_DISTDIR}/yaml-cpp-0.2.2.tar.gz ${WRKSRC}/yaml_cpp/build

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# update and install .pc files
.for f in bfl/bfl-boost/lib/pkgconfig/orocos-bfl.pc \
    yaml_cpp/yaml-cpp/lib/pkgconfig/yaml-cpp.pc
	${REINPLACE_CMD} -E -e "s|${WRKSRC}|${PREFIX}/ros/stacks/${STACKNAME}|" \
	    ${WRKSRC}/${f}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/pkgconfig
	${RM} ${WRKSRC}/${f}
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in actionlib bfl filters nodelet nodelet_topic_tools \
    nodelet_tutorial_math pluginlib test_nodelet tinyxml xacro yaml_cpp
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# strip ELF programs and make them executable
.for f in actionlib/bin/server_goal_handle_destruction \
    actionlib/bin/simple_client_allocator_test \
    actionlib/bin/action_client_destruction_test \
    actionlib/bin/simple_client_test actionlib/bin/simple_client_wait_test \
    actionlib/bin/simple_execute_ref_server actionlib/bin/ref_server \
    bfl/bfl-boost/bin/bfl/test_compare_filters \
    bfl/bfl-boost/bin/bfl/test_discrete_filter \
    bfl/bfl-boost/bin/bfl/test_linear_kalman \
    bfl/bfl-boost/bin/bfl/test_kalman_smoother \
    bfl/bfl-boost/bin/bfl/test_nonlinear_kalman \
    bfl/bfl-boost/bin/bfl/test_nonlinear_particle nodelet/bin/nodelet
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
# strip and symlink ELF libaries
.for f in actionlib/lib/libactionlib.so bfl/bfl-boost/lib/liborocos-bfl.so \
    filters/lib/libincrement.so filters/lib/libmean.so \
    filters/lib/libmedian.so filters/lib/libparams.so \
    filters/lib/libtransfer_function.so nodelet/lib/libnodeletlib.so \
    nodelet_tutorial_math/lib/libnodelet_math.so \
    pluginlib/lib/libboost_fs_wrapper.so pluginlib/lib/libpoco_lite.so \
    test_nodelet/lib/libtest_nodelet.so tinyxml/libtinyxml.so \
    yaml_cpp/yaml-cpp/lib/libyaml-cpp.so.0.2.2
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# copy symbolic links to libaries
.for f in yaml_cpp/yaml-cpp/lib/libyaml-cpp.so.0.2 \
    yaml_cpp/yaml-cpp/lib/libyaml-cpp.so
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# make scripts executable
.for f in actionlib/genaction.py \
    actionlib/test/test_imports.py actionlib/test/test_ref_action_server.py \
    actionlib/test/ref_server.py actionlib/test/ref_simple_server.py \
    actionlib/test/simple_python_client_test.py \
    actionlib/test/test_ref_simple_action_server.py \
    actionlib/test/test_server_components.py actionlib/tools/axclient.py \
    actionlib/tools/axserver.py actionlib/tools/dynamic_action.py \
    nodelet/scripts/list_nodelets \
    test_nodelet/test/plus_local.py \
    test_nodelet/test/test_loader.py \
    xacro/test/test_xacro.py xacro/xacro.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

.include <bsd.port.mk>
