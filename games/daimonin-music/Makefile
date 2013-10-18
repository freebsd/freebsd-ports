# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	daimonin-music
PORTVERSION=	20100827
CATEGORIES=	games
MASTER_SITES=	SF/daimonin/Addon%20packs/Music/
DISTFILES=	AllMusic.zip
DIST_SUBDIR=	${PORTNAME:S/-music//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music for daimonin client

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

NO_CHECKSUM=	true
NO_BUILD=	true
USE_ZIP=	true

BROKEN=		Does not install

MYDATADIR=	${DATADIR:S/-music//}

EXTRACT_BEFORE_ARGS=	-aqo

NO_STAGE=	yes
do-install:
	${MKDIR} ${MYDATADIR}/media
	${CP} -p ${WRKDIR}/* ${MYDATADIR}/media/

.include <bsd.port.mk>
