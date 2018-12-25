# Created by: Bartosz Fabianowski <freebsd@chillt.de>
# $FreeBSD$

PORTNAME=	widelands
DISTVERSION=	build19
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	https://launchpad.net/widelands/${DISTVERSION}/${DISTVERSION}/+download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libicuuc.so:devel/icu \
		libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext \
		tar:bzip2 python:build
CMAKE_ARGS=	-DWL_INSTALL_BASEDIR="${PREFIX}" \
		-DWL_INSTALL_DATADIR="${DATADIR}" \
		-DWL_INSTALL_DOCDIR="${DOCSDIR}" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_OPTIMIZE_FLAGS=""
USE_GL=		gl glew
USE_SDL=	sdl2 mixer2 image2 net2 ttf2
CXXFLAGS_powerpc=	-Wno-maybe-uninitialized
CXXFLAGS_powerpcspe=	-Wno-maybe-uninitialized
CXXFLAGS_powerpc64=	-Wno-maybe-uninitialized
CXXFLAGS_sparc64=	-Wno-maybe-uninitialized

PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Widelands" \
		"" \
		"${DATADIR}/pics/wl-ico-64.png" \
		"widelands" \
		"Game;StrategyGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
