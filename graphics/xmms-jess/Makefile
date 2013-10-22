# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-jess
PORTVERSION=	2.9.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://arquier.free.fr/
DISTNAME=	JESS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS visualization plugin that uses SDL

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_SDL=	sdl
GNU_CONFIGURE=	yes
PLIST_FILES=	lib/xmms/Visualization/libjess.so lib/xmms/Visualization/libjess.la
USE_GNOME=	glib12
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
