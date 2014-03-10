# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros_tutorials
PORTVERSION=	0.2.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
DIST_SUBDIR=	ros

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - tutorials

LICENSE=	BSD

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm
USE_WX=		2.8
USE_PYTHON=	yes
USE_BZIP2=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		EXTRA_CMAKE_FLAGS="-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}" \
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
	${MKDIR} ${PREFIX}/ros/stacks/${PORTNAME}
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in roscpp_tutorials rospy_tutorials turtlesim
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${PORTNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${PORTNAME}
.endfor
#strip ELF binaries and make them executable
.for f in roscpp_tutorials/bin/add_two_ints_client \
    roscpp_tutorials/bin/add_two_ints_server \
    roscpp_tutorials/bin/add_two_ints_server_class \
    roscpp_tutorials/bin/anonymous_listener roscpp_tutorials/bin/babbler \
    roscpp_tutorials/bin/custom_callback_processing \
    roscpp_tutorials/bin/listener roscpp_tutorials/bin/listener_async_spin \
    roscpp_tutorials/bin/listener_class roscpp_tutorials/bin/listener_multiple \
    roscpp_tutorials/bin/listener_threaded_spin \
    roscpp_tutorials/bin/listener_unreliable \
    roscpp_tutorials/bin/listener_with_tracked_object \
    roscpp_tutorials/bin/listener_with_userdata \
    roscpp_tutorials/bin/node_handle_namespaces \
    roscpp_tutorials/bin/notify_connect roscpp_tutorials/bin/parameters \
    roscpp_tutorials/bin/sleep roscpp_tutorials/bin/talker \
    roscpp_tutorials/bin/timers turtlesim/bin/draw_square turtlesim/bin/mimic \
    turtlesim/bin/turtle_teleop_key turtlesim/bin/turtlesim_node
	${STRIP_CMD} ${PREFIX}/ros/stacks/${PORTNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor
#make scripts executable
.for f in rospy_tutorials/001_talker_listener/listener.py \
    rospy_tutorials/001_talker_listener/talker.py \
    rospy_tutorials/002_headers/listener_header.py \
    rospy_tutorials/002_headers/talker_header.py \
    rospy_tutorials/003_listener_with_user_data/listener_with_user_data.py \
    rospy_tutorials/004_listener_subscribe_notify/listener_subscribe_notify.py \
    rospy_tutorials/005_add_two_ints/add_two_ints_client \
    rospy_tutorials/005_add_two_ints/add_two_ints_server \
    rospy_tutorials/006_parameters/param_talker.py \
    rospy_tutorials/007_connection_header/client_connection_header.py \
    rospy_tutorials/007_connection_header/listener_connection_header.py \
    rospy_tutorials/007_connection_header/server_connection_header.py \
    rospy_tutorials/007_connection_header/talker_connection_header.py \
    rospy_tutorials/008_on_shutdown/publish_on_shutdown.py \
    rospy_tutorials/009_advanced_publish/advanced_publish.py \
    rospy_tutorials/test/publish_on_shutdown_test_node.py \
    rospy_tutorials/test/talker_listener_test.py \
    rospy_tutorials/test/test_add_two_ints.py \
    rospy_tutorials/test/test_client_connection_header.py \
    rospy_tutorials/test/test_listener_connection_header.py \
    rospy_tutorials/test/test_on_shutdown.py \
    rospy_tutorials/test/test_peer_subscribe_notify.py \
    rospy_tutorials/test/test_server_connection_header.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${PORTNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${PORTNAME}/

.include <bsd.port.mk>
