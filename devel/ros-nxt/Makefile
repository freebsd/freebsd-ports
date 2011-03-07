# New ports collection makefile for: nxt-ros
# Date created:	2010-11-27
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ros-nxt
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTFILES=	nxt-${PORTVERSION}.tar.bz2 nxt-python-1.1.2.zip
DIST_SUBDIR=	ros
EXTRACT_ONLY=	nxt-${PORTVERSION}.tar.bz2

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - LEGO NXT interface

LICENSE_COMB=	multi
LICENSE=	BSD GPLv3

STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}

# TODO port python-bluez for secondary bluetooth interface (no bluetooth here)

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/geometry \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/geometry \
		${PYTHON_SITELIBDIR}/usb.so:${PORTSDIR}/devel/py-usb
USE_PYTHON=	yes
USE_BZIP2=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common_msgs:${LOCALBASE}/ros/stacks/geometry:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		USB stack cannot locate NXT
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

post-extract:
	${MKDIR} ${WRKSRC}/nxt_python/build
	${CP} ${_DISTDIR}/nxt-python-1.1.2.zip ${WRKSRC}/nxt_python/build
	# already extract and mark as such because we have to patch it
	(cd ${WRKSRC}/nxt_python/build ; \
	 ${LOCALBASE}/bin/unzip -q nxt-python-1.1.2.zip ; \
	 ${TOUCH} nxt-python-1.1.2/unpacked)
	# remove nxt_rviz_plugin, it is unbuildable right now
	# and keeping it here breaks rospack
	${RM} -rf ${WRKSRC}/nxt_rviz_plugin

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in nxt_controllers nxt_description nxt_lxf2urdf nxt_msgs nxt_python \
    nxt_ros #nxt_rviz_plugin
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
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

.include <bsd.port.post.mk>
