# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=		oolite
PORTVERSION=		1.88
CATEGORIES=		games gnustep
MASTER_SITES=		https://github.com/OoliteProject/oolite/releases/download/1.88/
DISTNAME=		${PORTNAME}-source-${PORTVERSION}
DIST_SUBDIR=		oolite

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Trade and combat space simulator, clone of Elite

LICENSE=		CC-BY-NC-SA-3.0 GPLv2 ZLIB
LICENSE_COMB=		multi
LICENSE_FILE_CC-BY-NC-SA-3.0=	${WRKSRC}/Doc/LICENSE.TXT

BUILD_DEPENDS=		zip:archivers/zip \
			${LOCALBASE}/bin/unzip:archivers/unzip
LIB_DEPENDS=		libespeak.so:audio/espeak \
			libnspr4.so:devel/nspr \
			libvorbisfile.so:audio/libvorbis \
			libpng.so:graphics/png \
			libminizip.so:archivers/minizip

USES=			gl gnustep openal:al perl5 python:build tar:bzip2
USE_CXXSTD=		gnu++98
USE_GL=			gl glu
USE_SDL=		sdl
USE_XORG=		x11
USE_GNUSTEP=		base build
# Redefine DO_MAKE_BUILD, because current gnustep in USES overrides MAKEFILE
# without possibility to change it, as it was done in the previous implementation
DO_MAKE_BUILD=		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g}
ALL_TARGET=		release-deployment
USE_PERL5=		build

GNUSTEP_LOCAL_APPS=	${GNUSTEP_LOCAL_ROOT}/Applications

SUB_FILES=	oolite
SUB_LIST=	GNUSTEP_SYSTEM_TOOLS="${GNUSTEP_SYSTEM_TOOLS}"

WRKSRC=	${WRKDIR}/${DISTNAME}
RELEASEDIR=	${WRKSRC}/oolite.app
DATADIR=	${GNUSTEP_LOCAL_APPS}/oolite.app
PORTDATA=	Resources
PORTDOCS=	*.pdf CHANGELOG.TXT contributors.txt

PLIST_FILES+=	bin/oolite ${DATADIR}/oolite \
		share/applications/oolite.desktop \
		share/pixmaps/oolite-icon.png

OPTIONS_DEFINE=	DOCS

BROKEN_aarch64=		fails to configure: error: These compiler flags are invalid: -O
BROKEN_armv6=		fails to compile: your compiler does not follow the C++ specification for temporary object destruction order
BROKEN_armv7=		fails to compile: your compiler does not follow the C++ specification for temporary object destruction order

post-patch: .SILENT
	${REINPLACE_CMD} -e 's/GNUSTEP_USER_ROOT/GNUSTEP_LOCAL_ROOT/ ; \
		s/sdl-config/$${SDL_CONFIG}/ ; \
		s|-lstdc++|`$${SDL_CONFIG} --libs` &| ; \
		s|:src/Core/MiniZip|| ; \
		s|-Isrc/Core/MiniZip|-I$${LOCALBASE}/include/minizip| ; \
		s|-lz|-lminizip| ; \
		/ioapi.c/d ; /unzip.c/d ; \
		s|/usr/X11R6|$${LOCALBASE}|' \
		${WRKSRC}/GNUmakefile
# Change value of the SAVEDIR define
	${REINPLACE_CMD} -e 's|oolite-saves|\.oolite-saves|' \
		${WRKSRC}/src/Core/NSFileManagerOOExtensions.h

do-install:
	(cd ${RELEASEDIR} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/oolite ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${RELEASEDIR}/oolite ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
