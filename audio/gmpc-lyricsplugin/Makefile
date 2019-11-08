# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-lyricsplugin
PORTVERSION=	0.20.0
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fetch lyrics gmpc plugin

LICENSE=	GPLv2+

LIB_DEPENDS=	libmpd.so:audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

GNU_CONFIGURE=	yes
USE_GNOME=	intltool glib20 gtk20 libxml2
USES=		gettext gmake gnome libtool pkgconfig
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/gmpc/plugins/lyricspluginplugin.so

.include <bsd.port.mk>
