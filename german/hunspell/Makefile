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

PLIST_FILES=	share/hunspell/de_AT.aff \
		share/hunspell/de_AT.dic \
		share/hunspell/de_CH.aff \
		share/hunspell/de_CH.dic \
		share/hunspell/de_DE.aff \
		share/hunspell/de_DE.dic
PLIST_DIRSTRY=	share/hunspell

CHALIASES=	de_LI
DEALIASES=	de_BE de_LU
.for ALIAS in ${CHALIASES} ${DEALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${PREFIX}/share/hunspell/
	${INSTALL_DATA} ${WRKSRC}/hunspell/*.aff ${WRKSRC}/hunspell/*.dic ${PREFIX}/share/hunspell/
.for ALIAS in ${CHALIASES}
	${LN} -s de_CH.aff ${PREFIX}/share/hunspell/${ALIAS}.aff
	${LN} -s de_CH.dic ${PREFIX}/share/hunspell/${ALIAS}.dic
.endfor
.for ALIAS in ${DEALIASES}
	${LN} -s de_DE.aff ${PREFIX}/share/hunspell/${ALIAS}.aff
	${LN} -s de_DE.dic ${PREFIX}/share/hunspell/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
