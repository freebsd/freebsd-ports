# Created by: jedgar@FreeBSD.org
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.9.1
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/proj/ \
		http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cartographic Projections library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

DATUM_GRID_FILES=	proj-datumgrid-1.6RC1.zip

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix
USE_LDCONFIG=	yes

post-extract:
	@${UNZIP_CMD} -q ${DISTDIR}/${DATUM_GRID_FILES} -d ${WRKSRC}/nad

.include <bsd.port.mk>
