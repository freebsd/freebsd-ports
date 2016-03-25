# Created by: Satoshi Asami <asami@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xgalaga
PORTVERSION=	2.1.1.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Clone of the classic game Galaga for X11

LICENSE=	GPLv2

USES=		gmake
USE_XORG=	xpm xmu
HAS_CONFIGURE=	yes

# xgalaga has a very strange usage of these variables...
CONFIGURE_ARGS=	--prefix=${LOCALBASE}/lib/X11/xgalaga \
		--mandir=${LOCALBASE}/man \
		--exec_prefix=${LOCALBASE}/bin

OPTIONS_DEFINE=	SOUND
OPTIONS_DEFAULT=	SOUND
OPTIONS_SUB=	yes

SOUND_CONFIGURE_OFF=	--without-sound

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xgalaga

.include <bsd.port.mk>
