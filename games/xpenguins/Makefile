# New ports collection makefile for:	xpenguins
# Date created:				24 January 2001
# Whom:					lyngbol@candid.dk
#
# $FreeBSD$
#

PORTNAME=	xpenguins
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://xpenguins.seul.org/ \
		http://www.chrisburkert.de/download/unix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xpenguins-daemon-1.0.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Cute little penguins that walk along the tops of your windows

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

MAN1=		xpenguins.1

post-install:
	/usr/bin/umask 0222 && \
	${TAR} zx --no-same-owner -f ${DISTDIR}/xpenguins-daemon-1.0.tar.gz -C ${DATADIR}/themes

.include <bsd.port.mk>
