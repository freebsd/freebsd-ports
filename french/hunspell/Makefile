# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	4.3
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hunspell-fr-moderne-v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Modern French hunspell dictionaries

USE_ZIP=	yes
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
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/fr-moderne.aff ${DATADIR}/fr_FR.aff
	${INSTALL_DATA} ${WRKSRC}/fr-moderne.dic ${DATADIR}/fr_FR.dic
.for ALIAS in ${FRALIASES}
	${LN} -s fr_FR.aff ${DATADIR}/${ALIAS}.aff
	${LN} -s fr_FR.dic ${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
