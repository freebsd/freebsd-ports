# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2011.07.20
CATEGORIES=	german textproc
MASTER_SITES=	http://www.openthesaurus.de/export/
DISTNAME=	Deutscher-Thesaurus
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	German thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

DEALIASES=	de_AT de_BE de_CH de_LI de_LU

PLIST_FILES=	share/mythes/th_de_DE_v2.idx \
		share/mythes/th_de_DE_v2.dat

.for ALIAS in ${DEALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.idx \
		share/mythes/th_${ALIAS}_v2.dat
.endfor

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_de_DE_v2.* ${PREFIX}/share/mythes
	@cd ${PREFIX}/share/mythes; \
	for alias in ${DEALIASES}; do \
	  ${LN} -s th_de_DE_v2.idx th_$${alias}_v2.idx ; \
	  ${LN} -s th_de_DE_v2.dat th_$${alias}_v2.dat ; \
	done

.include <bsd.port.mk>
