# Created by: nbm
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP} ${MASTER_SITE_LOCAL}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator

USE_PYTHON=	yes

DATADIR=	${PREFIX}/share/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
ARGS=		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-e ${PYTHONPREFIX_INCLUDEDIR} -v ${DATADIR} \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}" LINK_SHLIB="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INCDIR="${LOCALBASE}/include" LIBDIR="${LOCALBASE}/lib"

PORTDOCS=	*

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && cd ${WRKSRC}/doc/html && \
		${COPYTREE_SHARE} \. ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${DATADIR} &&\
		cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} &&\
		${PYTHON_CMD} -c "import sipconfig" &&\
		${PYTHON_CMD} -O -c "import sipconfig" &&\
		${PYTHON_CMD} -c "import sipdistutils" &&\
		${PYTHON_CMD} -O -c "import sipdistutils"

.include <bsd.port.mk>
