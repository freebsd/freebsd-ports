# Created by: jedgar@FreeBSD.org
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	6.1.0
PORTEPOCH=	1
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Cartographic Projections library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	proj5-5.[0-9]*.[0-9]*

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		compiler:c++11-lang gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

DATUM_GRID_FILES=	proj-datumgrid-1.8.zip \
			proj-datumgrid-europe-1.3.zip \
			proj-datumgrid-north-america-1.2.zip \
			proj-datumgrid-oceania-1.0.zip \
			proj-datumgrid-world-1.0.zip

FMAN1=	cs2cs.1 geod.1 proj.1
FMAN3=	geodesic.3 pj_init.3

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-extract:
	${MKDIR} ${WRKSRC}/datum
.for f in ${DATUM_GRID_FILES}
	@${TAR} -xf ${DISTDIR}/${f} -C ${WRKSRC}/datum
.endfor

post-install:
.for m in 1 3
	(cd ${STAGEDIR}${MANPREFIX}/man/man${m} && ${GZIP_CMD} ${FMAN${m}})
.endfor

	cd ${WRKSRC}/datum && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
