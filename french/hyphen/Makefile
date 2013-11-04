# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	3.0
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hyph-fr-v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	French hyphenation rules

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_fr.dic
PLIST_DIRSTRY=	%%DATADIR%%

FRALIASES=	fr_FR fr_BE fr_CA fr_CH fr_LU
.for ALIAS in ${FRALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_fr.dic ${STAGEDIR}${DATADIR}/
.for ALIAS in ${FRALIASES}
	${LN} -s hyph_fr.dic ${STAGEDIR}${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
