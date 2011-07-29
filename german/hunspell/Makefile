# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110609
PORTREVISION=	1
CATEGORIES=	german textproc
MASTER_SITES=	http://www.j3e.de/ispell/igerman98/dict/
DISTNAME=	igerman98-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell german dictionary

BUILD_DEPENDS=	buildhash:${PORTSDIR}/textproc/ispell

USE_BZIP2=	yes
ALL_TARGET=	hunspell-all
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/de_AT.aff \
		%%DATADIR%%/de_AT.dic \
		%%DATADIR%%/de_CH.aff \
		%%DATADIR%%/de_CH.dic \
		%%DATADIR%%/de_DE.aff \
		%%DATADIR%%/de_DE.dic
PLIST_DIRSTRY=	%%DATADIR%%

CHALIASES=	de_LI
DEALIASES=	de_BE de_LU
.for ALIAS in ${CHALIASES} ${DEALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hunspell/*.aff ${WRKSRC}/hunspell/*.dic ${DATADIR}/
.for ALIAS in ${CHALIASES}
	${LN} -s de_CH.aff ${DATADIR}/${ALIAS}.aff
	${LN} -s de_CH.dic ${DATADIR}/${ALIAS}.dic
.endfor
.for ALIAS in ${DEALIASES}
	${LN} -s de_DE.aff ${DATADIR}/${ALIAS}.aff
	${LN} -s de_DE.dic ${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
