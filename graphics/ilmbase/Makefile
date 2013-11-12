# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.0.1
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	ilmbase-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD

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

PLIST_SUB=	MAJORVER=2_0

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-patch:
	@${REINPLACE_CMD} -e 's|Iex/libIex.la|Iex/libIex.la $(PTHREAD_LIBS)|' \
		${WRKSRC}/IlmThread/Makefile.am
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure

post-install:
.for e in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/Half/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
