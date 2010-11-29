# New ports collection makefile for: ros-laser_pipeline
# Date created:	2010-11-27
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ros-laser_pipeline
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTNAME=	laser_pipeline-${PORTVERSION}
DIST_SUBDIR=	ros

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - laser data processing utilities

LICENSE=	BSD

STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common/stack.xml:${PORTSDIR}/devel/ros-common \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/geometry \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common/stack.xml:${PORTSDIR}/devel/ros-common \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		${LOCALBASE}/ros/stacks/geometry/stack.xml:${PORTSDIR}/math/geometry
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
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common:${LOCALBASE}/ros/stacks/common_msgs:${LOCALBASE}/ros/stacks/geometry:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in laser_assembler laser_filters laser_geometry
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
#strip binaries and make them executable
.for f in laser_assembler/bin/laser_scan_assembler \
    laser_assembler/bin/laser_scan_assembler_srv \
    laser_assembler/bin/merge_clouds laser_assembler/bin/point_cloud_assembler \
    laser_assembler/bin/point_cloud_assembler_srv \
    laser_assembler/examples/periodic_snapshotter \
    laser_assembler/test/dummy_scan_producer \
    laser_assembler/test/test_assembler \
    laser_filters/bin/generic_laser_filter_node \
    laser_filters/bin/scan_to_cloud_filter_chain \
    laser_filters/bin/scan_to_scan_filter_chain
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
#strip and symlink ELF libaries
.for f in laser_filters/lib/liblaser_scan_filters.so \
    laser_filters/lib/libpointcloud_filters.so \
    laser_geometry/lib/liblaser_geometry.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
#make scripts executable
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/laser_filters/test/fake_laser.py

.include <bsd.port.mk>
