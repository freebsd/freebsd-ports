# Created by: jedgar@FreeBSD.org
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.9.3
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cartographic Projections library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

DATUM_GRID_FILES=	proj-datumgrid-1.6.zip

GNU_CONFIGURE=	yes
USES=		compiler gmake libtool pathfix
USE_LDCONFIG=	yes

FMAN1=	cs2cs.1 geod.1 proj.1
FMAN3=	geodesic.3 pj_init.3

INSTALL_TARGET=	install-strip

post-extract:
	@${TAR} -xf ${DISTDIR}/${DATUM_GRID_FILES} -C ${WRKSRC}/nad

pre-configure:
	@${REINPLACE_CMD} -e 's|gcc|${COMPILER_TYPE}|' \
		${WRKSRC}/cmake/Proj4SystemInfo.cmake

post-install:
.for m in 1 3
	(cd ${STAGEDIR}${MANPREFIX}/man/man${m} && ${GZIP_CMD} ${FMAN${m}})
.endfor

.include <bsd.port.mk>
