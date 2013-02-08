# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-common
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/:rel \
		http://pr.willowgarage.com/downloads/:pr \
		SF/smc/smc/6_0_1/:sf
MASTER_SITE_SUBDIR=	smc
DISTFILES=	common-${PORTVERSION}.tar.bz2:rel bfl-31655.tar.gz:pr \
		yaml-cpp-0.2.5.tar.gz:pr \
		smc_6_0_1.tgz:sf
DIST_SUBDIR=	ros
EXTRACT_ONLY=	common-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - common utilities

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		does not compile

#LICENSE_COMB=	multi
#LICENSE=	BSD Zlib MIT LGPL Poco MPL11 #which?

STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}-${PORTVERSION}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs \
		chrpath:${PORTSDIR}/devel/chrpath \
		${LOCALBASE}/include/uuid/uuid.h:${PORTSDIR}/misc/e2fsprogs-libuuid
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_SDL=	sdl image

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

#CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common_msgs:${LOCALBASE}/ros/stacks/ros_comm:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

post-extract:
	${MKDIR} ${WRKSRC}/bfl/build
	${CP} ${_DISTDIR}/bfl-31655.tar.gz ${WRKSRC}/bfl/build
	${MKDIR} ${WRKSRC}/yaml_cpp/build
	${CP} ${_DISTDIR}/yaml-cpp-0.2.5.tar.gz ${WRKSRC}/yaml_cpp/build
	${MKDIR} ${WRKSRC}/smclib/build
	${CP} ${_DISTDIR}/smc_6_0_1.tgz ${WRKSRC}/smclib/build

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
.for d in actionlib bfl bond bondcpp bondpy bondtest filters nodelet \
    nodelet_topic_tools pluginlib smclib test_bond \
    test_nodelet tinyxml xacro yaml_cpp
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -or -name \*.md5sum -or -name installed -type f \
	    -or -name wiped -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# strip ELF programs and make them executable
.for f in actionlib/bin/add_two_ints_client \
    actionlib/bin/add_two_ints_server \
    actionlib/bin/ref_server \
    actionlib/bin/simple_execute_ref_server \
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
    bondcpp/lib/libbondcpp.so filters/lib/libincrement.so \
    filters/lib/libmean.so filters/lib/libmedian.so filters/lib/libparams.so \
    filters/lib/libtransfer_function.so nodelet/lib/libnodeletlib.so \
    pluginlib/lib/libboost_fs_wrapper.so pluginlib/lib/libpoco_lite.so \
    pluginlib/lib/libtest_plugins.so \
    test_nodelet/lib/libtest_nodelet.so tinyxml/libtinyxml.so \
    yaml_cpp/yaml-cpp/lib/libyaml-cpp.so.0.2.5
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
.for f in actionlib/test/exercise_simple_client.py \
    actionlib/test/test_imports.py actionlib/test/mock_simple_server.py \
    actionlib/test/test_ref_action_server.py actionlib/test/ref_server.py \
    actionlib/test/test_ref_simple_action_server.py \
    actionlib/test/ref_simple_server.py \
    actionlib/test/test_server_components.py \
    actionlib/test/simple_python_client_test.py \
    actionlib/tools/axclient.py \
    actionlib/tools/axserver.py actionlib/tools/dynamic_action.py \
    nodelet/scripts/list_nodelets \
    test_nodelet/test/plus_local.py \
    test_nodelet/test/test_loader.py \
    xacro/test/test_xacro.py xacro/xacro.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
