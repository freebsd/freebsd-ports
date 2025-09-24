PORTNAME=	bitmap2pp
DISTVERSION=	4.39.0
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${DISTVERSION}
DISTNAME=	dktools-${DISTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS
WWW=		https://sourceforge.net/p/dktools/wiki/bitmap2pp/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		jpeg localbase:ldflags
GNU_CONFIGURE=	yes
# We do not want to include sys/termios.h even if it exists, and we do not want
# to depend on BDB for db.h (it is used by other parts of dktools).
CONFIGURE_ENV=	ac_cv_header_db_h=no

ALL_TARGET=		${PORTNAME}
CONFLICTS_INSTALL=	dktools[0-9]*
PLIST_FILES=		bin/${PORTNAME} \
			share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man/man1/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
