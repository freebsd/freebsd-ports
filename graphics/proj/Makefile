# Created by: jedgar@FreeBSD.org
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.8.0
PORTREVISION=	2
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/proj/ \
		http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cartographic Projections library

CONFLICTS=	proj4-[0-9]*

DATUM_GRID_FILES=	proj-datumgrid-1.5.zip

GNU_CONFIGURE=	yes
USES=		gmake zip:infozip
USE_LDCONFIG=	yes

post-extract:
	@${UNZIP_CMD} -q ${DISTDIR}/${DATUM_GRID_FILES} -d ${WRKSRC}/nad

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/projects.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
