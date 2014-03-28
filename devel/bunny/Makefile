# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bunny
PORTVERSION=	0.93
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Closed loop, high-performance, general purpose protocol-blind fuzzer

PROJECTHOST=	bunny-the-fuzzer
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/bunny-trace bin/bunny-gcc bin/bunny-flow bin/bunny-exec \
		bin/bunny-main

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Fails to compile: invokes i386 asm

OPTIONS_DEFINE=DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
.for f in ${PLIST_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f:C/bin\///} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
