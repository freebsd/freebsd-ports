PORTNAME=	libtexlua
PORTVERSION=	5.3.6
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Lua library for TeXLive

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/LICENSE.MIT

USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_TEX=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux libs/lua53
WRKSRC=		${WRKDIR}/${DISTNAME}/libs/lua53

post-extract:
	${SED} -e '/\*\ Copyright/,/\*\//!d;s/^\*//;/^\*\*/d' \
	    ${WRKSRC}/lua53-src/src/lua.h > ${WRKDIR}/LICENSE.MIT

.include <bsd.port.mk>
