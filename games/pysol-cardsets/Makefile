# New ports collection makefile for:    PySol Cardsets
# Date created:         18 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol-cardsets
PORTVERSION=	4.40
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	serg@tmn.ru
COMMENT=	Collection of free cardsets adapted for use with PySol

RUN_DEPENDS=	pysol:${PORTSDIR}/games/pysol

USE_BZIP2=	yes
NO_BUILD=	yes

CARDSETS=	1567 1750 1815 1880-delarue 1880-tarot 1890-grimaud aisleriot \
		briscola culemann-1850a culemann-1850b dashavatara-ganjifa \
		denizens dondorf-whist-a dondorf-whist-b fantasy \
		gdkcard-bonded get-a-round gortz-1841 gortz-1842 gpl hamburg-a \
		hamburg-b hegewald-1770 houbigant hungarian-tarokk jacoby \
		joan-darc kabale kintengu-small liege little-sorcerer \
		maritimes melange migeon-costume mughal-ganjifa naylor \
		nickel-ante ovale-salon oxymoron-small penguins \
		prince-charles rangoon-d rangoon-e rangoon-r revolution-1 \
		revolution-2 revolution-3 rivers-banks spaced spider \
		spin-dist tensho tksol transformation traugott-1800 \
		traugott-1834 ukiyoe-fuji ukiyoe-sharaku vienna-2k-small \
		vienna-tarock wilhelmtell xpat2 xpat2-nox-large \
		xpat2-nox-medium xpat2-nox-small xpat2-nox-tiny xskat-french \
		xskat-french-large xskat-german

do-install:
	@${MKDIR} ${PREFIX}/share/pysol
.for set in ${CARDSETS}
	(cd ${WRKSRC}/data; tar cf - cardset-${set}) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
.endfor

.include <bsd.port.mk>
