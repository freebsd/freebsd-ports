# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	libconfuse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3
CATEGORIES=	devel

MAINTAINER=	juraj@lutter.sk
COMMENT=	Configuration file parsing library

LICENSE=	ISCL

USES=		autoreconf gettext-tools iconv pathfix pkgconfig libtool
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	martinh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --enable-shared
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
