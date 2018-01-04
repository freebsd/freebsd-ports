# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.2.1
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	ilmbase-${PORTVERSION}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD3CLAUSE

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=		DOCS

OPTIONS_SUB=	yes

THREAD_CONFIGURE_ENABLE=	threading

MAJORVER=	2_2
VER=		23

PLIST_SUB=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

HALF_BIN=	eLut toFloat

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHalf.so.${VER}
	${RM} ${STAGEDIR}${PREFIX}/lib/*.la
.for l in libIex libIexMath libImath libIlmThread
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${MAJORVER}.so.${VER}
	${LN} -s ${l}-${MAJORVER}.so.${VER} ${STAGEDIR}${PREFIX}/lib/${l}.so || :
.endfor

.for e in ${HALF_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/Half/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
