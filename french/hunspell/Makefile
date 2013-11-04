# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	4.6
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hunspell-fr-moderne-v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Modern French hunspell dictionaries

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/fr_FR.aff \
		%%DATADIR%%/fr_FR.dic
PLIST_DIRSTRY=	%%DATADIR%%

FRALIASES=	fr_BE fr_CA fr_CH fr_LU
.for ALIAS in ${FRALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/fr-moderne.aff ${STAGEDIR}${DATADIR}/fr_FR.aff
	${INSTALL_DATA} ${WRKSRC}/fr-moderne.dic ${STAGEDIR}${DATADIR}/fr_FR.dic
.for ALIAS in ${FRALIASES}
	${LN} -sf fr_FR.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -sf fr_FR.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
