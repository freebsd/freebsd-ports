# New ports collection makefile for:	bunny
# Date created:				28 Jan 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bunny
PORTVERSION=	0.92
CATEGORIES=	devel
MASTER_SITES=	http://bunny-the-fuzzer.googlecode.com/files/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Closed loop, high-performance, general purpose protocol-blind fuzzer

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/bunny-trace bin/bunny-gcc bin/bunny-flow bin/bunny-exec \
		bin/bunny-main

.include <bsd.port.pre.mk>

# attempt to fix build on sparc64
.if ${ARCH} == "sparc64"
CFLAGS+=	-O0
.endif

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

.include <bsd.port.post.mk>
