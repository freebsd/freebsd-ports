# New ports collection makefile for:   rio
# Date created:        29 April 1999
# Whom:                Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	rio
PORTVERSION=	1.07
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
DISTNAME=	rio007
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for transferring files to and from the Diamond Rio .mp3 player

WRKSRC=		${WRKDIR}/rio107
MAKEFILE=	makefile

BINOWN=		root
BINMODE=	4755

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin

.include <bsd.port.post.mk>
