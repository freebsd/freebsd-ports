# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	xdx
PORTVERSION=	2.4
PORTREVISION=	7
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.chronos.org.uk/download/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio DX cluster monitor

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	cairo gtk20 gdkpixbuf2

GNU_CONFIGURE=	yes

#post-patch:
#	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
#		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
