PORTNAME=	argp-standalone
DISTVERSION=	1.5.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/argp-standalone/argp-standalone/commit/
PATCHFILES=	e4b42480f6fd63a117e1d8a3d90fb69434133c28.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

LICENSE=	LGPL20+ PD
LICENSE_COMB=	multi

USES=		gettext-runtime localbase:ldflags meson
USE_CSTD=	gnu89
USE_GITHUB=	yes
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=both

PLIST_FILES=	lib/libargp.a \
		lib/libargp.so lib/libargp.so.0 lib/libargp.so.0.0.0 \
		include/argp.h

.include <bsd.port.mk>
