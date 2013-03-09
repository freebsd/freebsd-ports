# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdasm
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Simple x86 disassembly library

USE_LDCONFIG=	yes

PORTDOCS=	HISTORY.txt README.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS|PREFIX).*=,\1 ?=,; \
			      s,libdasm.so.1.0,libdasm.so.1,g; \
			      s,cp ,${INSTALL_DATA} ,g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/examples/Makefile

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README.txt ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/das.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/simple.c ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCSDIR}; \
	 done
.endif

.include <bsd.port.mk>
