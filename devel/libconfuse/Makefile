# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	libconfuse
DISTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	devel

USE_GITHUB=	yes
GH_ACCOUNT=	martinh
GH_PROJECT=	libconfuse
GH_TAGNAME=	v3.2.1

MAINTAINER=	otis@freebsd.sk
COMMENT=	Configuration file parsing library

LICENSE=	ISCL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --enable-shared
INSTALL_TARGET=	install-strip
USES=		autoreconf gettext-tools iconv pathfix pkgconfig libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
