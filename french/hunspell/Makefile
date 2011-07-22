# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	4.2
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hunspell-fr-moderne-v${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell modern french dictionnary

USE_ZIP=	yes
NO_BUILD=	yes

FRALIASES=	fr_BE fr_CA fr_CH fr_LU
PLIST_FILES=	share/hunspell/fr_FR.aff \
		share/hunspell/fr_FR.dic
.for ALIAS in ${FRALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKDIR}/fr-moderne.aff ${PREFIX}/share/hunspell/fr_FR.aff
		@${INSTALL_DATA} ${WRKDIR}/fr-moderne.dic ${PREFIX}/share/hunspell/fr_FR.dic
		@cd ${PREFIX}/share/hunspell; \
		for alias in ${FRALIASES}; do \
			${LN} -s fr_FR.aff $${alias}.aff ; \
			${LN} -s fr_FR.dic $${alias}.dic ; \
		done

.include <bsd.port.mk>
