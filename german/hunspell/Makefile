# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110609
CATEGORIES=	german textproc
MASTER_SITES=	http://www.j3e.de/ispell/igerman98/dict/
DISTNAME=	igerman98-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell german dictionary

BUILD_DEPENDS=	buildhash:${PORTSDIR}/textproc/ispell

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/igerman98-${PORTVERSION}
USE_GMAKE=	yes

ALL_TARGET=	hunspell-all

PLIST_FILES=	share/hunspell/de_DE.aff \
		share/hunspell/de_DE.dic \
		share/hunspell/de_CH.aff \
		share/hunspell/de_CH.dic \
		share/hunspell/de_AU.aff \
		share/hunspell/de_AU.dic
PLIST_DIRS=	share/hunspell

DEALIASES=	de_BE de_LU
CHALIASES=	de_LI

.for ALIAS in ${DEALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor
.for ALIAS in ${CHALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/hunspell/*.aff \
		${WRKSRC}/hunspell/*.dic \
		${PREFIX}/share/hunspell/
	@cd ${PREFIX}/share/hunspell; \
	for alias in ${DEALIASES}; do \
		${LN} -s de_DE.aff $${alias}.aff ; \
		${LN} -s de_DE.dic $${alias}.dic ; \
	done; \
	for alias in ${CHALIASES}; do \
		${LN} -s de_CH.aff $${alias}.aff ; \
		${LN} -s de_CH.dic $${alias}.dic ; \
	done;

.include <bsd.port.mk>
