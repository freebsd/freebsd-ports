# New ports collection makefile for: common_msgs
# Date created:	2010-11-22
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	common_msgs
PORTVERSION=	1.2.2
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
		ROS_PACKAGE_PATH=${WRKDIR} \
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
#move and strip ELF libaries
	${MV} ${PREFIX}/ros/stacks/${PORTNAME}/sensor_msgs/lib/libsensor_msgs.so \
	    ${PREFIX}/lib
	${STRIP_CMD} ${PREFIX}/lib/libsensor_msgs.so
#make scripts executable
.for f in actionlib_msgs/genaction.py \
    actionlib_msgs/src/actionlib_msgs/msg/_GoalID.py \
    actionlib_msgs/src/actionlib_msgs/msg/_GoalStatus.py \
    actionlib_msgs/src/actionlib_msgs/msg/_GoalStatusArray.py \
    diagnostic_msgs/src/diagnostic_msgs/msg/_DiagnosticArray.py \
    diagnostic_msgs/src/diagnostic_msgs/msg/_DiagnosticStatus.py \
    diagnostic_msgs/src/diagnostic_msgs/msg/_KeyValue.py \
    diagnostic_msgs/src/diagnostic_msgs/srv/_SelfTest.py \
    geometry_msgs/src/geometry_msgs/msg/_Point.py \
    geometry_msgs/src/geometry_msgs/msg/_Point32.py \
    geometry_msgs/src/geometry_msgs/msg/_PointStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Polygon.py \
    geometry_msgs/src/geometry_msgs/msg/_PolygonStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Pose.py \
    geometry_msgs/src/geometry_msgs/msg/_Pose2D.py \
    geometry_msgs/src/geometry_msgs/msg/_PoseArray.py \
    geometry_msgs/src/geometry_msgs/msg/_PoseStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_PoseWithCovariance.py \
    geometry_msgs/src/geometry_msgs/msg/_PoseWithCovarianceStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Quaternion.py \
    geometry_msgs/src/geometry_msgs/msg/_QuaternionStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Transform.py \
    geometry_msgs/src/geometry_msgs/msg/_TransformStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Twist.py \
    geometry_msgs/src/geometry_msgs/msg/_TwistStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_TwistWithCovariance.py \
    geometry_msgs/src/geometry_msgs/msg/_TwistWithCovarianceStamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Vector3.py \
    geometry_msgs/src/geometry_msgs/msg/_Vector3Stamped.py \
    geometry_msgs/src/geometry_msgs/msg/_Wrench.py \
    geometry_msgs/src/geometry_msgs/msg/_WrenchStamped.py \
    nav_msgs/src/nav_msgs/msg/_GridCells.py \
    nav_msgs/src/nav_msgs/msg/_MapMetaData.py \
    nav_msgs/src/nav_msgs/msg/_OccupancyGrid.py \
    nav_msgs/src/nav_msgs/msg/_Odometry.py nav_msgs/src/nav_msgs/msg/_Path.py \
    nav_msgs/src/nav_msgs/srv/_GetMap.py nav_msgs/src/nav_msgs/srv/_GetPlan.py \
    sensor_msgs/src/sensor_msgs/msg/_CameraInfo.py \
    sensor_msgs/src/sensor_msgs/msg/_ChannelFloat32.py \
    sensor_msgs/src/sensor_msgs/msg/_CompressedImage.py \
    sensor_msgs/src/sensor_msgs/msg/_Image.py \
    sensor_msgs/src/sensor_msgs/msg/_Imu.py \
    sensor_msgs/src/sensor_msgs/msg/_JointState.py \
    sensor_msgs/src/sensor_msgs/msg/_LaserScan.py \
    sensor_msgs/src/sensor_msgs/msg/_PointCloud.py \
    sensor_msgs/src/sensor_msgs/msg/_PointCloud2.py \
    sensor_msgs/src/sensor_msgs/msg/_PointField.py \
    sensor_msgs/src/sensor_msgs/msg/_RegionOfInterest.py \
    sensor_msgs/src/sensor_msgs/srv/_SetCameraInfo.py \
    test_common_msgs/test/test_common_msgs_migration.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor

.include <bsd.port.mk>
