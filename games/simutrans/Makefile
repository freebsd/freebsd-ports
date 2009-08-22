# New ports collection makefile for:	simutrans
# Date created:		24 January 2009
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	simutrans
PORTVERSION=	102.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/102-0
DISTFILES=	simutrans-src-102-0.zip \
		simulinux-102-0.zip \
		pak64-102-0.zip

MAINTAINER=	tijl@ulyssis.org
COMMENT=	Transport business simulation game

MAKE_ARGS=	BACKEND=mixer_sdl \
		COLOUR_DEPTH=16 \
		OSTYPE=freebsd \
		FLAGS=-DUSE_C \
		VERBOSE=1
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_ZIP=	yes

.include "${.CURDIR}/Makefile.plist"

PLIST_DIRS=	${SIMUTRANS_DIRS:S/^/%%DATADIR%%\//} %%DATADIR%%
PLIST_FILES=	bin/simutrans \
		bin/simutrans-bin \
		${SIMUTRANS_DATA:S/^/%%DATADIR%%\//}

do-install:
.for _D in ${SIMUTRANS_DIRS}
	${MKDIR} ${DATADIR}/${_D}
.endfor
.for _D in ${SIMUTRANS_DATA}
	${INSTALL_DATA} ${WRKSRC}/simutrans/${_D} ${DATADIR}/${_D}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/sim ${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${PREFIX}/bin/simutrans

.include <bsd.port.mk>
