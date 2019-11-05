# Created by: eivind
# $FreeBSD$

PORTNAME=	xscavenger
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/scavenger/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lode Runner clone for X11

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../copyright

WRKSRC_SUBDIR=	src

USES=		imake tar:tgz xorg
USE_XORG=	x11 xext

CFLAGS+=	-Wno-return-type -Wno-pointer-sign

DESKTOP_ENTRIES="XScavenger" "" "" "scavenger" "" ""

OPTIONS_DEFINE=		ALSA
OPTIONS_DEFAULT=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CFLAGS_OFF=	-DNO_ALSA

post-patch-ALSA-off:
	@${REINPLACE_CMD} -e \
		's|-lasound||' ${WRKSRC}/Imakefile

pre-configure:
	@${LN} -sf scavenger.6 ${WRKSRC}/scavenger.man
	@${ECHO_CMD} "MANSUFFIX=6" >> ${WRKSRC}/Imakefile

.include <bsd.port.mk>
