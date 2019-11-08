# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-mserver
PORTVERSION=	0.20.0
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lets you stream music files to your mpd that are not in your database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libtag.so:audio/taglib \
		libmicrohttpd.so:www/libmicrohttpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	glib20 gtk20 intltool libxml2
USES=		gettext gmake gnome libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
