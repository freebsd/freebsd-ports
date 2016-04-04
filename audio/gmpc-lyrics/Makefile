# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-lyrics
PORTVERSION=	11.8.16
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lyrics Provider plugin for gmpc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

GNU_CONFIGURE=	yes
USE_GNOME=	intltool glib20 gtk20 libxml2
USES=		gettext gmake libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/gmpc/plugins/lyricsplugin.so

.include <bsd.port.mk>
