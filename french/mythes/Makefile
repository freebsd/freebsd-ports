# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2.2.2
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	thesaurus-v${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	French thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

FRALIASES=	fr_BE fr_CA fr_CH fr_LU

PLIST_FILES=	share/mythes/th_fr_FR_v2.dat \
		share/mythes/th_fr_FR_v2.idx

.for ALIAS in ${FRALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.dat \
		share/mythes/th_${ALIAS}_v2.idx
.endfor

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/thes_fr.dat ${PREFIX}/share/mythes/th_fr_FR_v2.dat
	@${INSTALL_DATA} ${WRKDIR}/thes_fr.idx ${PREFIX}/share/mythes/th_fr_FR_v2.idx
	@cd ${PREFIX}/share/mythes; \
	for alias in ${FRALIASES}; do \
	  ${LN} -s th_fr_FR_v2.idx th_$${alias}_v2.idx ; \
	  ${LN} -s th_fr_FR_v2.dat th_$${alias}_v2.dat ; \
	done

.include <bsd.port.mk>
