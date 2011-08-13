# New ports collection makefile for:	hyphen
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	french textproc
MASTER_SITES=	http://www.dicollecte.org/download/fr/
DISTNAME=	hyph_fr_${PORTVERSION:S/./-/}

MAINTAINER=	office@FreeBSD.org
COMMENT=	French hyphenation rules

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_fr_FR.dic
PLIST_DIRSTRY=	%%DATADIR%%

FRALIASES=	fr_BE fr_CA fr_CH fr_LU
.for ALIAS in ${FRALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_fr_FR.dic ${DATADIR}/
.for ALIAS in ${FRALIASES}
	${LN} -s hyph_fr_FR.dic ${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
