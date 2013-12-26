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

NO_CHECKSUM=	true
NO_BUILD=	true
USE_ZIP=	true

MYDATADIR=	${PREFIX}/share/daimonin

EXTRACT_BEFORE_ARGS=	-aqo

do-install:
	${MKDIR} ${STAGEDIR}${MYDATADIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} media ${STAGEDIR}${MYDATADIR}/

.include <bsd.port.mk>
