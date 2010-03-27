# New ports collection makefile for:	bunny
# Date created:				28 Jan 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bunny
PORTVERSION=	0.93
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Closed loop, high-performance, general purpose protocol-blind fuzzer

MAKE_JOBS_SAFE=	yes

PROJECTHOST=	bunny-the-fuzzer
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/bunny-trace bin/bunny-gcc bin/bunny-flow bin/bunny-exec \
		bin/bunny-main

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Fails to compile: invokes i386 asm

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
.for f in ${PLIST_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f:C/bin\///} ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
