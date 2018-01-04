# Created by: nbm
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
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
		CC="${CC}" CXX="${CXX}" LINK="${CXX}" LINK_SHLIB="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INCDIR="${LOCALBASE}/include" LIBDIR="${LOCALBASE}/lib"

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS DEBUG
DEBUG_CONFIGURE_ON=	--debug

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
	${REINPLACE_CMD} -e '/sip_bin.:/s|'\'',$$|-${PYTHON_VER}'\'',|' \
		${WRKSRC}/sipconfig.py

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

.include <bsd.port.mk>
