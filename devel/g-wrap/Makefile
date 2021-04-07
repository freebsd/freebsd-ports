PORTNAME=	g-wrap
DISTVERSION=	1.9.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Tool for generating function wrappers for Guile

LICENSE=	LGPL21+

LIB_DEPENDS=	libffi.so:devel/libffi					\
		libguile-2.2.so:lang/guile2				\
		libgc-threaded.so:devel/boehm-gc-threaded
BUILD_DEPENDS=	guile2>=2.2:lang/guile2

USES=		gmake gnome libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-Werror

INFO=		g-wrap

INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
