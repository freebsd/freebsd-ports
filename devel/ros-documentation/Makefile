# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-documentation
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/
DISTNAME=	documentation-${PORTVERSION}
DIST_SUBDIR=	ros

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - documentation utilities

LICENSE=	BSD

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28
STACKNAME=	${PORTNAME:S/ros-//}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros
RUN_DEPENDS=	rosrun:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		doxygen:${PORTSDIR}/devel/doxygen \
		epydoc:${PORTSDIR}/devel/epydoc
USE_PYTHON=	2
USE_BZIP2=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src \
		ROS_BOOST_ROOT=${LOCALBASE} \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/ros_comm:${WRKSRC}
MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
post-patch:
	@${GREP} -l -r "^#\!/usr/bin/env python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|#!/usr/bin/env python|#!/usr/bin/env python2|"
	# fix path to bash
	${GREP} -l -r "^#\! /bin/bash" ${WRKSRC} | ${XARGS} \
	    ${REINPLACE_CMD} -E -e "s|#! /bin/bash|#!${LOCALBASE}/bin/bash|"
	${GREP} -l -r "^#\!/bin/bash" ${WRKSRC} | ${XARGS} \
	    ${REINPLACE_CMD} -E -e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}

.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in rosdoc
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
# make scripts executable
.for f in rosdoc/scripts/upload rosdoc/rosdoc
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
