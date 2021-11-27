# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	openttd
DISTVERSION=	12.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open source clone of Microprose Transport Tycoon Deluxe

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblzo2.so:archivers/lzo2

USES=		cmake compiler:c++17-lang cpe pkgconfig tar:xz
CMAKE_ARGS=	-DCMAKE_INSTALL_BINDIR:PATH=bin \
		-DCMAKE_INSTALL_DATADIR:PATH=share

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS FLUIDSYNTH SAVE_PASSWORDS SERVER
SERVER_PREVENTS=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

SAVE_PASSWORDS_DESC=	Save passwords between server restarts
SAVE_PASSWORDS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-save-passwords

SERVER_DESC=		Build dedicated server only (no GUI)
SERVER_USES_OFF=	gnome sdl
SERVER_USE_OFF=		SDL=sdl
SERVER_CMAKE_ON=	-DOPTION_DEDICATED:BOOL=ON
SERVER_LIB_DEPENDS_OFF=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libicui18n.so:devel/icu \
			libicu-le-hb.so:devel/icu-le-hb \
			libiculx.so:devel/icu-lx
SERVER_VARS=		USE_RC_SUBR=${PORTNAME}

post-install-SERVER-on:
	@${REINPLACE_CMD} -E '/icons|pixmaps/d' ${TMPPLIST}

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
