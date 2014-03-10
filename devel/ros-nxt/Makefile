# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-nxt
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/:rel \
		${MASTER_SITE_GOOGLE_CODE}:gc \
		http://foote-ros-pkg.googlecode.com/files/:foote
DISTFILES=	nxt-${PORTVERSION}.tar.bz2:rel nxt-python-1.1.2.zip:gc \
		nxt_description.parts.tar.gz:foote
DIST_SUBDIR=	ros
EXTRACT_ONLY=	nxt-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - LEGO NXT interface

PROJECTHOST=	nxt-python
LICENSE_COMB=	multi
LICENSE=	BSD GPLv3

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28
STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}-${PORTVERSION}

# TODO port python-bluez for secondary bluetooth interface (no bluetooth here)

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/ros-geometry \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/ros-geometry \
		${PYTHON_SITELIBDIR}/usb.so:${PORTSDIR}/devel/py-usb
USE_PYTHON=	2
USE_BZIP2=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/ros_comm:${LOCALBASE}/ros/stacks/common_msgs:${LOCALBASE}/ros/stacks/geometry:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	${CP} ${_DISTDIR}/nxt_description.parts.tar.gz ${WRKSRC}/nxt_description/meshes/nxt_description.tar.gz
	${MKDIR} ${WRKSRC}/nxt_python/build
	${CP} ${_DISTDIR}/nxt-python-1.1.2.zip ${WRKSRC}/nxt_python/build
	# already extract and mark as such because we have to patch it
	(cd ${WRKSRC}/nxt_python/build ; \
	 ${UNZIP_CMD} -q nxt-python-1.1.2.zip ; \
	 ${TOUCH} nxt-python-1.1.2/unpacked)
	# remove nxt_rviz_plugin, it is unbuildable right now
	# and keeping it here breaks rospack
	${RM} -rf ${WRKSRC}/nxt_rviz_plugin

post-patch:
	@${GREP} -l -r "^#\!/usr/bin/env python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|#!/usr/bin/env python|#!/usr/bin/env python2|"
	@${REINPLACE_CMD} -e 's|python setup.py|python2 setup.py|' \
		${WRKSRC}/nxt_python/Makefile

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# delete file already extracted
	${RM} ${WRKSRC}/nxt_description/meshes/nxt_description.tar.gz
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in nxt_controllers nxt_description nxt_lxf2urdf nxt_msgs nxt_python \
    nxt_ros #nxt_rviz_plugin
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -or -name installed -type f \
	    -or -name wiped -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# make scripts executable
.for f in nxt_controllers/scripts/base_controller.py \
    nxt_controllers/scripts/base_odometry.py \
    nxt_controllers/scripts/joint_position_controller.py \
    nxt_lxf2urdf/scripts/lxf2urdf.py nxt_lxf2urdf/scripts/transformations.py \
    nxt_python/bin/nxt_filer nxt_python/bin/nxt_push nxt_python/bin/nxt_test \
    nxt_python/sensor_tests/color_sensor_test.py \
    nxt_python/sensor_tests/touch_sensor_test.py nxt_python/test_sensors.py \
    nxt_ros/scripts/joint_states_aggregator.py nxt_ros/scripts/nxt_ros.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.post.mk>
