# $FreeBSD$

PORTNAME=	tesseract
DISTVERSION=	2014_05_12
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_first_edition_linux
PKGNAMESUFFIX=	-game-data

MAINTAINER=	operator@myrechenzentrum.net
COMMENT=	Data files for Tesseract first-person shooter

LICENSE=	DejaVu OTHER
LICENSE_COMB=	multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_FILE_DejaVu=	${WRKSRC}/media/interface/font/default.txt
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_OTHER=	Various licenses for textures, sounds, etc.
LICENSE_TEXT_OTHER=	See info.txt files under media/ directory
LICENSE_PERMS_OTHER=	dist-mirror pkg-mirror auto-accept

USES=		tar:xz
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDATA=	config media screenshot
PLIST_FILES=	"@dir %%DATADIR%%/media/prefab" \
		"@dir %%DATADIR%%/screenshot"

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
