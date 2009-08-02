# New ports collection makefile for:	xmms-goom
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	goom
PORTVERSION=	2.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-2k4-0-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cool XMMS visualization

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms \
		nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_AUTOTOOLS=	libtool:22
USE_XORG=	x11
USE_GNOME+=	gdkpixbuf gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/goom2k4-0

post-patch:
	@${CHMOD} -R og+rx ${WRKSRC}
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${BUILD_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
