# Created by: gahr
# $FreeBSD$

PORTNAME=	bitlbee-facebook
PORTVERSION=	20151227
CATEGORIES=	irc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Facebook plugin for bitlbee

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
BUILD_DEPENDS=	bitlbee:irc/bitlbee

USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gahr
GH_TAGNAME=	20151224

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/facebook.so

.include <bsd.port.mk>
