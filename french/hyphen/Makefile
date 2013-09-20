# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	3.0
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hyph-fr-v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	French hyphenation rules

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_fr.dic
PLIST_DIRSTRY=	%%DATADIR%%

FRALIASES=	fr_FR fr_BE fr_CA fr_CH fr_LU
.for ALIAS in ${FRALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_fr.dic ${DATADIR}/
.for ALIAS in ${FRALIASES}
	${LN} -s hyph_fr.dic ${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
