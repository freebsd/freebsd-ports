# New ports collection makefile for:    funktrackergold
# Date created:                 Apr 1, 2001
# Whom:                         Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	funktrackergold
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players
DISTNAME=	funktrackergold-1.5-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	A curses MOD/FNK music tracker

WRKSRC=		${WRKDIR}/funkgold
MAKE_ARGS=	EXTRA_CFLAGS="${PTHREAD_CFLAGS}" \
		EXTRA_LDFLAGS="${PTHREAD_LIBS}"

PORTDOCS=	INSTALL
PLIST_FILES=	bin/funkgold

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funkgold ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
