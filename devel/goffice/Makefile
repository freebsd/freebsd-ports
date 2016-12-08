# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/goffice/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goffice
PORTVERSION=	0.8.17
PORTREVISION=	9
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	08

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	ignore:1

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack gtk20 libgsf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION=${PORTVERSION} \
		SHORT_VER=0.8

OPTIONS_DEFINE=	GCONF
OPTIONS_DEFAULT=GCONF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
.else
CONFIGURE_ARGS+=--with-config-backend=keyfile
.endif

.include <bsd.port.mk>
