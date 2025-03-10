PORTNAME=	argp-standalone
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

LICENSE=	LGPL21+

USES=		gettext-runtime localbase:ldflags meson

MESON_ARGS=	--default-library=both
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_TAGNAME=	8ded2bc

.include <bsd.port.mk>
