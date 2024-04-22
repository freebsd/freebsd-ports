PORTNAME=	g-wrap
DISTVERSION=	1.9.15
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Tool for generating function wrappers for Guile
WWW=		https://www.nongnu.org/g-wrap/

LICENSE=	LGPL21+

LIB_DEPENDS+=	libffi.so:devel/libffi

USES=		gmake gnome guile:2.2 libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--disable-Werror

MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	install-strip

INFO=		g-wrap

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

.include <bsd.port.mk>
