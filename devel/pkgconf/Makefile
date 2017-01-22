# $FreeBSD$

PORTNAME=	pkgconf
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://distfiles.dereferenced.org/pkgconf/ \
		http://files.etoilebsd.net/pkgconf/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to help to configure compiler and linker flags

LICENSE=	ISCL

USES=		tar:xz libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/libdata/pkgconfig:/usr/libdata/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include
MAKE_ARGS=	MANDIR="${MAN1PREFIX}/man/man1"

post-install:
	${LN} -sf pkgconf ${STAGEDIR}${PREFIX}/bin/pkg-config

.include <bsd.port.mk>
