# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdasm
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Simple x86 disassembly library

LICENSE=	BSD2CLAUSE

BROKEN=		Unfetchable (google code has gone away)

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${STAGEDIR}${PREFIX}"
USE_LDCONFIG=	yes

PORTDOCS=	HISTORY.txt README.txt
PORTEXAMPLES=	README.txt das.c simple.c

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

post-patch:
	@${REINPLACE_CMD} 's,libdasm.so.1.0,libdasm.so.1,g; \
			   s,cp ,${INSTALL_DATA} ,g; \
			   /cd examples/d' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
