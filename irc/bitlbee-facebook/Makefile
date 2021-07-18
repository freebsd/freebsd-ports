# Created by: gahr

PORTNAME=	bitlbee-facebook
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=v
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	irc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Facebook plugin for bitlbee

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
BUILD_DEPENDS=	bitlbee:irc/bitlbee

USES=		autoreconf gettext-runtime gnome libtool pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-plugindir=${PREFIX}/lib/bitlbee

USE_GITHUB=	yes
GH_ACCOUNT=	bitlbee

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/facebook.so

.include <bsd.port.mk>
