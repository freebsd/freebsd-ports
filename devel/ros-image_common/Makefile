# New ports collection makefile for: ros-image_common
# Date created:	2010-11-27
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ros-image_common
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTNAME=	image_common-${PORTVERSION}
DIST_SUBDIR=	ros

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - common image routines

LICENSE=	BSD

STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common/stack.xml:${PORTSDIR}/devel/ros-common \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common/stack.xml:${PORTSDIR}/devel/ros-common \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common:${LOCALBASE}/ros/stacks/common_msgs:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in camera_calibration_parsers image_transport polled_camera
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# strip ELF programs and make them executable
.for f in camera_calibration_parsers/bin/convert \
    image_transport/bin/list_transports image_transport/bin/republish \
    polled_camera/bin/poller
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
# strip and symlink ELF libaries
.for f in camera_calibration_parsers/lib/libcamera_calibration_parsers.so \
    image_transport/lib/libimage_transport.so \
    polled_camera/lib/libpolled_camera.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor

.include <bsd.port.mk>
