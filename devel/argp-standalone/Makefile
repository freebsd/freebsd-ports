PORTNAME=	argp-standalone
DISTVERSION=	1.5.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/argp-standalone/argp-standalone/commit/
PATCHFILES=	e4b42480f6fd63a117e1d8a3d90fb69434133c28.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

LICENSE=	LGPL21+

USES=		gettext-runtime localbase:ldflags meson

MESON_ARGS=	-Ddefault_library=both
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

USE_GITHUB=	yes

.include <bsd.port.mk>
