# New ports collection makefile for:    funktrackergold
# Date created:                 Apr 1, 2001
# Whom:                         Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	funktrackergold
PORTVERSION=	1.5.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE} http://lothar.arafura.net.au/~jsno/rel/unix_projects/
MASTER_SITE_SUBDIR=	apps/sound/players
DISTNAME=	funktrackergold-1.5-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	markp@FreeBSD.org

WRKSRC=		${WRKDIR}/funkgold
MAKE_ARGS=	EXTRA_CFLAGS="${PTHREAD_CFLAGS}" \
		EXTRA_LDFLAGS="${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funkgold ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/${PORTNAME}/README
.endif

.include <bsd.port.mk>
