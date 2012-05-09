# New ports collection makefile for:	simutrans
# Date created:		24 January 2009
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	simutrans
PORTVERSION=	111.2.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${SIMUTRANS_VERSION} \
		SF/${PORTNAME}/pak64/${SIMUTRANS_PAK64}:pak64
DISTFILES=	simutrans-src-${SIMUTRANS_VERSION}.zip \
		simupak64-${SIMUTRANS_PAK64}.zip:pak64

MAINTAINER=	tijl@coosemans.org
COMMENT=	Transportation simulation game

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/simutrans/license.txt

SIMUTRANS_VERSION=	${PORTVERSION:S,.,-,g}
SIMUTRANS_REVISION=	5583
SIMUTRANS_PAK64=	111-2

MAKE_ARGS=	BACKEND=mixer_sdl \
		COLOUR_DEPTH=16 \
		OSTYPE=freebsd \
		FLAGS="-DUSE_C -DREVISION=${SIMUTRANS_REVISION}" \
		VERBOSE=1
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_ZIP=	yes

PLIST_DIRSTRY=	share/applications
PLIST_FILES=	bin/simutrans \
		bin/simutrans-bin \
		share/applications/simutrans.desktop
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} 's/simutrans/.simutrans/' ${WRKSRC}/simsys.cc

do-install:
	cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		"config font music pak skin text" ${DATADIR}
.ifndef NOPORTDOCS
	${INSTALL_DATA} ${WRKSRC}/simutrans/readme.txt ${DATADIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
		${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${PREFIX}/bin/simutrans
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/simutrans.desktop \
		${PREFIX}/share/applications/simutrans.desktop

.include <bsd.port.mk>
