# Created by: lyngbol@candid.dk
# $FreeBSD$

PORTNAME=	xpenguins
PORTVERSION=	2.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://xpenguins.seul.org/:xp \
		http://www.chrisburkert.de/download/unix/:ch
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xp \
		xpenguins-daemon-1.2.tar.gz:ch
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Cute little penguins that walk along the tops of your windows

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

post-install:
	/usr/bin/umask 0222 && \
	${TAR} zx --no-same-owner -f ${DISTDIR}/xpenguins-daemon-1.2.tar.gz -C ${STAGEDIR}${DATADIR}/themes

.include <bsd.port.mk>
