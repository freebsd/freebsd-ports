# New ports collection makefile for:	libdasm
# Date created:				28 March 2006
# Whom:					Antoine Brodin <antoine.brodin@laposte.net>
#
# $FreeBSD$
#

PORTNAME=	libdasm
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.klake.org/~jt/misc/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	A simple x86 disassembly library

USE_LDCONFIG=	yes

PORTDOCS=	HISTORY.txt README.txt

.if !defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.include <bsd.port.pre.mk>

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
.if !defined(WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README.txt ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/das.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/simple.c ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCSDIR}; \
	 done
.endif

.include <bsd.port.post.mk>
