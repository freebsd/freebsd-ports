# New ports collection makefile for:	xpenguins
# Date created:				24 January 2001
# Whom:					lyngbol@candid.dk
#
# $FreeBSD$
#

PORTNAME=	xpenguins
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://xpenguins.seul.org/:xp \
		http://www.chrisburkert.de/download/unix/:ch
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xp \
		xpenguins-daemon-1.2.tar.gz:ch
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Cute little penguins that walk along the tops of your windows

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

MAN1=		xpenguins.1

post-install:
	/usr/bin/umask 0222 && \
	${TAR} zx --no-same-owner -f ${DISTDIR}/xpenguins-daemon-1.2.tar.gz -C ${DATADIR}/themes

.include <bsd.port.mk>
