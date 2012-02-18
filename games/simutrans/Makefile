# New ports collection makefile for:	simutrans
# Date created:		24 January 2009
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	simutrans
PORTVERSION=	111.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${SIMUTRANS_VERSION} \
		SF/${PORTNAME}/pak64/${SIMUTRANS_VERSION}:pak64
DISTFILES=	simutrans-src-${SIMUTRANS_VERSION}.zip \
		simulinux-${SIMUTRANS_VERSION}.zip \
		simupak64-${SIMUTRANS_VERSION}.zip:pak64

MAINTAINER=	tijl@coosemans.org
COMMENT=	Transportation simulation game

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/simutrans/licence.txt

SIMUTRANS_VERSION=	${PORTVERSION:S,.,-,g}
SIMUTRANS_REVISION=	4911

OPTIONS=	FOOD	"Add-on with farms, foods, markets,..." off

MAKE_ARGS=	BACKEND=mixer_sdl \
		COLOUR_DEPTH=16 \
		OSTYPE=freebsd \
		FLAGS="-DUSE_C -DREVISION=${SIMUTRANS_REVISION}" \
		VERBOSE=1
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	Makefile
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_ZIP=	yes

.include <bsd.port.options.mk>

.if defined(WITH_FOOD)
DISTFILES+=	simupak64-addon-food-${SIMUTRANS_VERSION}.zip:pak64
.endif

.include "${.CURDIR}/Makefile.plist"

PLIST_DIRS=	${SIMUTRANS_DIRS:S,^,%%DATADIR%%/,} %%DATADIR%%
PLIST_FILES=	${SIMUTRANS_DATA:S,^,%%DATADIR%%/,}

post-patch:
	@${REINPLACE_CMD} 's/simutrans/.simutrans/' ${WRKSRC}/simsys.cc

do-install:
	${MKDIR} ${DATADIR}
.for _D in ${SIMUTRANS_DIRS:O}
	${MKDIR} ${DATADIR}/${_D}
.endfor
.for _D in ${SIMUTRANS_DATA}
	${INSTALL_DATA} ${WRKSRC}/simutrans/${_D} ${DATADIR}/${_D}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
		${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${PREFIX}/bin/simutrans
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/simutrans.desktop \
		${PREFIX}/share/applications/simutrans.desktop

.include <bsd.port.mk>
