# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libboard
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Vector graphics C++ library

LICENSE=	LGPL3

BUILD_DEPENDS=	doxygen:devel/doxygen

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	CXX=${CXX}

USES=		gmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.$//}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
CXXFLAGS+=	-fPIC
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-O3|${CXXFLAGS}|' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libboard.so ${STAGEDIR}${PREFIX}/lib/libboard.so.0
	${LN} -sf libboard.so.0 ${STAGEDIR}${PREFIX}/lib/libboard.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${RM} -rf ${STAGEDIR}${DOCSDIR}/.svn
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR}/
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}/.svn
.endif

regression-test:
	(cd ${WRKDIR} && ${WRKSRC}/bin/arithmetic bec)
.for ex in 1 2 3
	(cd ${WRKDIR} && ${WRKSRC}/bin/example${ex})
.endfor
	${LS} -l ${WRKDIR}/arithm* ${WRKDIR}/draw*

.include <bsd.port.post.mk>
