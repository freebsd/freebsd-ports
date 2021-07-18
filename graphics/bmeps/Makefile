PORTNAME=	bmpp
DISTVERSION=	4.30.10
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gmake jpeg localbase:ldflags

GNU_CONFIGURE=	yes
# We do not want to include sys/termios.h even if it exists, and we do not want
# to depend on BDB for db.h (it is used by other parts of dktools).
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no\
		ac_cv_header_db_h=no
ALL_TARGET=	bmpp
CONFLICTS_INSTALL=	dktools[0-9]*

PLIST_FILES=	bin/bmpp man/man1/bmpp.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmpp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man/man1/bmpp.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
