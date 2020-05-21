# $FreeBSD$

PORTNAME=	guile-cairo
DISTVERSION=	1.11.1
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Wrapper for using the Cairo graphics library from Guile

LICENSE=	LGPL3+

LIB_DEPENDS=	libguile-2.2.so:lang/guile2				\
		libgc-threaded.so:devel/boehm-gc-threaded
BUILD_DEPENDS=	guile2>=2.2:lang/guile2

USES=		gmake gnome libtool pkgconfig
USE_CSTD=	c99
USE_GNOME=	cairo
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INFO=		guile-cairo

INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
