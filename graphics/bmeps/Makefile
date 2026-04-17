PORTNAME=	bitmap2pp
DISTVERSION=	4.40.0
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${DISTVERSION}
DISTNAME=	dktools-${DISTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS
WWW=		https://sourceforge.net/p/dktools/wiki/bitmap2pp/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler jpeg localbase:ldflags
GNU_CONFIGURE=	yes
# We do not want to include sys/termios.h even if it exists, and we do not want
# to depend on BDB for db.h (it is used by other parts of dktools).
CONFIGURE_ENV=	ac_cv_header_db_h=no

ALL_TARGET=		${PORTNAME}
CONFLICTS_INSTALL=	dktools[0-9]*
PLIST_SUB=		SOVER=${DISTVERSION:R}

.include <bsd.port.pre.mk>

# GCC is assumed if "CC=cc" is set thus set CC accordingly if clang is used.
.if ${COMPILER_TYPE} == clang && !defined(USE_GCC) && ${CC} == cc
CC=	clang
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/libdk4*.so* ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
