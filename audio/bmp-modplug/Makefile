# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	modplug
PORTVERSION=	2.0.5
PORTREVISION=	10
CATEGORIES?=	audio
MASTER_SITES=	ftp://ftp.osuosl.org/pub/FreeBSD/distfiles/ \
		http://ftp.osuosl.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.dvo.ru/pub/distfiles/ \
		ftp://ftp.mtu.ru/pub/FreeBSD/distfiles/ \
		ftp://ftp.chg.ru/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PORTNAME}${PKGNAMEPREFIX}2.05

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ModPlug-based plugin for beep-media-player

LIB_DEPENDS=	libeep.so:${PORTSDIR}/multimedia/beep-media-player \
		libmodplug.so:${PORTSDIR}/audio/libmodplug

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/bmp/Input
PLIST_FILES=	${PLUGDIR}/libmodplugbmp.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/modplugbmp/.libs/libmodplugbmp.so \
		${STAGEDIR}${PREFIX}/${PLUGDIR}

.include <bsd.port.mk>
