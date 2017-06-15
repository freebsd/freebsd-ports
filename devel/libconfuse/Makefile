# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	libconfuse
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/confuse
DISTNAME=	confuse-${PORTVERSION}

MAINTAINER=	otis@freebsd.sk
COMMENT=	Configuration file parsing library

LICENSE=	ISCL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --enable-shared
INSTALL_TARGET=	install-strip
USES=		iconv pathfix pkgconfig libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
