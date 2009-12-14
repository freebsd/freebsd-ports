# New ports collection makefile for:	simutrans
# Date created:		24 January 2009
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	simutrans
PORTVERSION=	102.2.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${SIMUTRANS_VERSION} \
		SF/${PORTNAME}/pak64/${SIMUTRANS_VERSION}:pak64
DISTFILES=	simutrans-src-${SIMUTRANS_VERSION}.zip \
		simulinux-${SIMUTRANS_VERSION}.zip \
		simupak64-${SIMUTRANS_VERSION}.zip:pak64 \
		simupak64-addon-food-${SIMUTRANS_VERSION}.zip:pak64

MAINTAINER=	tijl@coosemans.org
COMMENT=	Transportation simulation game

SIMUTRANS_VERSION=	${PORTVERSION:S,.,-,g}

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

PLIST_DIRS=	${SIMUTRANS_DIRS:S,^,%%DATADIR%%/,} %%DATADIR%%
PLIST_FILES=	${SIMUTRANS_DATA:S,^,%%DATADIR%%/,} \
		${SIMUTRANS_DOCS:S,^,%%PORTDOCS%%%%DATADIR%%/,}

post-patch:
	@${REINPLACE_CMD} 's/simutrans/.simutrans/' ${WRKSRC}/simsys_s.cc

do-install:
	${MKDIR} ${DATADIR}
.for _D in ${SIMUTRANS_DIRS:O}
	${MKDIR} ${DATADIR}/${_D}
.endfor
.for _D in ${SIMUTRANS_DATA}
	${INSTALL_DATA} ${WRKSRC}/simutrans/${_D} ${DATADIR}/${_D}
.endfor
.ifndef NOPORTDOCS
.for _D in ${SIMUTRANS_DOCS}
	${INSTALL_DATA} ${WRKSRC}/simutrans/${_D} ${DATADIR}/${_D}
.endfor
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/sim ${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${PREFIX}/bin/simutrans
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/simutrans.desktop \
		${PREFIX}/share/applications/simutrans.desktop

.include <bsd.port.mk>
