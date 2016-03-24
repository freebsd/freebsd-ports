# Created by: gahr
# $FreeBSD$

PORTNAME=	bitlbee-facebook
PORTVERSION=	1.0.0
PORTEPOCH=	1
DISTVERSIONPREFIX=v
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
GH_ACCOUNT=	jgeboski

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/facebook.so

.include <bsd.port.mk>
