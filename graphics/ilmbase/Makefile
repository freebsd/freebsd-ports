# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.1.0
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	ilmbase-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD3CLAUSE

USES=		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README

BIN=	eLut toFloat

OPTIONS_DEFINE=		DOCS THREAD
OPTIONS_DEFAULT=	THREAD
THREAD_DESC=		Enable multithreaded file I/O support

OPTIONS_SUB=	yes

THREAD_CONFIGURE_ENABLE=	threading

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREAD}
CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif

MAJORVER=	2_1
VER=	11

PLIST_SUB=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-patch:
	@${REINPLACE_CMD} -e 's|Iex/libIex.la|Iex/libIex.la $(PTHREAD_LIBS)|' \
		${WRKSRC}/IlmThread/Makefile.am
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHalf.so.${VER}
.for l in libIex libIexMath libImath libIlmThread
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${MAJORVER}.so.${VER}
.endfor

.for e in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/Half/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
