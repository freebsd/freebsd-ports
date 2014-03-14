# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-common_msgs
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/common_msgs/common_msgs-${PORTVERSION}/
DISTNAME=	common_msgs-${PORTVERSION}
DIST_SUBDIR=	ros

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - common messages

LICENSE=	BSD

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28
STACKNAME=	${PORTNAME:S/ros-//}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
 		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
 		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm

USES=		shebangfix
USE_PYTHON=	2
USE_BZIP2=	yes
USE_LDCONFIG=	yes

python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	actionlib_msgs/genaction.py \
		stereo_msgs/migration_rules/split_rawstereo.py \
		test_common_msgs/test/test_common_msgs_migration.py

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/ros_comm:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in actionlib_msgs diagnostic_msgs geometry_msgs nav_msgs sensor_msgs \
    stereo_msgs test_common_msgs trajectory_msgs visualization_msgs
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
#strip and symlink ELF libraries
.for f in sensor_msgs/lib/libsensor_msgs.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# make scripts executable
.for f in actionlib_msgs/genaction.py \
    stereo_msgs/migration_rules/split_rawstereo.py \
    test_common_msgs/test/test_common_msgs_migration.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
