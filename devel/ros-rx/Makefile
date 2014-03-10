# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-rx
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/:rel \
		http://pr.willowgarage.com/downloads/:pr
DISTFILES=	rx-${PORTVERSION}.tar.bz2:rel SWIG-1.3.29-wx.tar.gz:pr
DIST_SUBDIR=	ros
EXTRACT_ONLY=	rx-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - GUI related tools

#LICENSE=	BSD LGPL* CreativeCommons WxWindows

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28
STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}-${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include
BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		chrpath:${PORTSDIR}/devel/chrpath
RUN_DEPENDS=	rosrun:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		dot:${PORTSDIR}/graphics/graphviz
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_WX=		2.8
WX_COMPS=	python:build python:run
USE_BZIP2=	yes
USE_LDCONFIG=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		EXTRA_CMAKE_FLAGS="-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}" \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/ros_comm:${WRKSRC} \
		ROS_BOOST_ROOT=${LOCALBASE}
MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
post-extract:
	# move 3rdparty distfiles into place
	${MKDIR} ${WRKSRC}/wxswig/build
	${CP} ${_DISTDIR}/SWIG-1.3.29-wx.tar.gz ${WRKSRC}/wxswig/build

post-patch:
	# fix path to the wx configure tool
	${REINPLACE_CMD} -E -e "s|wx-config|${WX_CONFIG}|" \
	    ${WRKSRC}/wxswig/manifest.xml

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}

.for f in CMakeLists.txt Makefile stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in rxbag rxdeps rxgraph rxtools test_rxdeps test_rxplot \
    wxPython_swig_interface wxswig xdot
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
# strip and symlink libraries to PREFIX/lib
.for f in rxtools/lib/librxtools.so rxtools/lib/_rxtoolscpp.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# strip ELF binaries and make them executable
.for f in rxtools/bin/rxconsole rxtools/bin/rxloggerlevel wxswig/bin/swig-real
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
# make scripts executable
.for f in rxbag/scripts/rxbag rxgraph/nodes/rxgraph rxtools/nodes/rxplot \
    rxtools/lib/rxtoolscpp.py test_rxdeps/test/test_rxdeps.py \
    test_rxplot/test/test_rxplot_command_offline.py \
    wxswig/swig-wrap wxswig/bin/swig xdot/dot_viewer.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
