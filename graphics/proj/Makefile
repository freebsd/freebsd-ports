# Created by: jedgar@FreeBSD.org
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	7.1.1
PORTEPOCH=	1
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Cartographic Projections library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake libtool pathfix pkgconfig sqlite
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	proj5-5.[0-9]*.[0-9]*

DATUM_GRID_FILES=	proj-datumgrid-1.8.zip \
			proj-datumgrid-europe-1.3.zip \
			proj-datumgrid-north-america-1.2.zip \
			proj-datumgrid-oceania-1.0.zip \
			proj-datumgrid-world-1.0.zip

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-extract:
	${MKDIR} ${WRKSRC}/datum
.for f in ${DATUM_GRID_FILES}
	@${TAR} -xf ${DISTDIR}/${f} -C ${WRKSRC}/datum
.endfor
post-extract-DATA-on:
	${MKDIR} ${WRKSRC}/proj_data
	@${TAR} -xf ${DISTDIR}/${DATA_DISTFILES} -C ${WRKSRC}/proj_data

post-install:
	cd ${WRKSRC}/datum && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}

post-install-DATA-on:
	cd ${WRKSRC}/proj_data && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
