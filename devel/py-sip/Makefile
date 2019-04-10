# Created by: nbm
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator

USES=		python pyqt:sip
USE_PYTHON=	concurrent py3kplist flavors
USE_PYQT=	#

CONFIGURE_ARGS=	-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-e ${PYTHONPREFIX_INCLUDEDIR} -v ${DATADIR} \
		--sipdir ${PYQT_SIPDIR} \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}" LINK_SHLIB="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INCDIR="${LOCALBASE}/include" LIBDIR="${LOCALBASE}/lib"

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS DEBUG
DEBUG_CONFIGURE_ON=	--debug

# From upstreams site:
# When building PyQt5 v5.11 or later you must configure SIP to create a
# private copy of the sip module using a command line similar to the following:
#  > python configure.py --sip-module PyQt5.sip --no-tools
# As this port is already flavored we cannot add further Qt4/Qt5 flavoring.
CONFIGURE_WRKSRC=	${WRKSRC}/default
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}

do-configure:
	# The default sip 'flavor'
	${MKDIR} ${CONFIGURE_WRKSRC} &&  \
		cd ${CONFIGURE_WRKSRC} && \
		${PYTHON_CMD} ${WRKSRC}/configure.py ${CONFIGURE_ARGS} && \
		${REINPLACE_CMD} -e '/sip_bin.:/s|'\'',$$|-${PYTHON_VER}'\'',|'  ${CONFIGURE_WRKSRC}/sipconfig.py
	# The now needed version for 5.11 (which will be the default from 2019-03-16).
	${MKDIR} ${WRKSRC}/sip_qt5 && \
		cd ${WRKSRC}/sip_qt5 && \
		${PYTHON_CMD} ${WRKSRC}/configure.py ${CONFIGURE_ARGS} --sip-module PyQt5.sip --no-tools  && \
		${REINPLACE_CMD} -e '/sip_bin.:/s|'\'',$$|-${PYTHON_VER}'\'',|'  ${WRKSRC}/sip_qt5/sipconfig.py

post-build:
	cd ${WRKSRC}/sip_qt5 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && cd ${WRKSRC}/doc/html && \
		${COPYTREE_SHARE} \. ${STAGEDIR}${DOCSDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/sip
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/sip.so

	cd ${WRKSRC}/sip_qt5 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/PyQt5/sip.so

.include <bsd.port.mk>
