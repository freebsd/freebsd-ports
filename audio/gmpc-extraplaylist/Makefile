# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-extraplaylist
PORTVERSION=	0.20.0
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Favorites plugin for gmpc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

GNU_CONFIGURE=	yes
USES=		gnome libtool pkgconfig
USE_GNOME=	glib20 gtk20 libglade2 libxml2
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/gmpc/plugins/libextraplaylist.so

.include <bsd.port.mk>
