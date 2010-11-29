# New ports collection makefile for: common_msgs
# Date created:	2010-11-22
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	common_msgs
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DIST_SUBDIR=	ros

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - common messages

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros
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
		ROS_PACKAGE_PATH=${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${PORTNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in actionlib_msgs diagnostic_msgs geometry_msgs nav_msgs sensor_msgs \
    test_common_msgs
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${PORTNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${PORTNAME}
.endfor
#strip and symlink ELF libraries
	${STRIP_CMD} ${PREFIX}/ros/stacks/${PORTNAME}/sensor_msgs/lib/libsensor_msgs.so
	${LN} -s ${PREFIX}/ros/stacks/${PORTNAME}/sensor_msgs/lib/libsensor_msgs.so \
	    ${PREFIX}/lib
# make scripts executable
.for f in actionlib_msgs/genaction.py \
    test_common_msgs/test/test_common_msgs_migration.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor

.include <bsd.port.mk>
