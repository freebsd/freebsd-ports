# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2011.07.26
CATEGORIES=	german textproc
MASTER_SITES=	http://www.openthesaurus.de/export/
DISTNAME=	Deutscher-Thesaurus
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	German thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/mythes/th_de_DE_v2.idx \
		share/mythes/th_de_DE_v2.dat
PLIST_DIRSTRY=	share/mythes

DEALIASES=	de_AT de_BE de_CH de_LI de_LU

.for ALIAS in ${DEALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.idx \
		share/mythes/th_${ALIAS}_v2.dat
.endfor

do-install:
	${MKDIR} ${PREFIX}/share/mythes/
	${INSTALL_DATA} ${WRKSRC}/th_de_DE_v2.dat ${WRKSRC}/th_de_DE_v2.idx ${PREFIX}/share/mythes/
.for ALIAS in ${DEALIASES}
	${LN} -s th_de_DE_v2.dat ${PREFIX}/share/mythes/th_${ALIAS}_v2.dat
	${LN} -s th_de_DE_v2.idx ${PREFIX}/share/mythes/th_${ALIAS}_v2.idx
.endfor

.include <bsd.port.mk>
