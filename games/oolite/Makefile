# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=		oolite
PORTVERSION=		1.80
CATEGORIES=		games gnustep
MASTER_SITES=		http://github.com/OoliteProject/oolite/releases/download/1.80b/
DISTNAME=		${PORTNAME}-source-${PORTVERSION}
DIST_SUBDIR=		oolite

MAINTAINER=		avg@icyb.net.ua
COMMENT=		Trade and combat space simulator, clone of Elite

LICENSE=		CCBYNCSAv3 GPLv2 ZLIB
LICENSE_COMB=		multi
LICENSE_NAME_CCBYNCSAv3=	Creative Commons Attribution-NonCommercial-ShareAlike License version 3.0
LICENSE_FILE_CCBYNCSAv3=	${WRKSRC}/Doc/LICENSE.TXT
LICENSE_PERMS_CCBYNCSAv3=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip \
			${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=		libespeak.so:${PORTSDIR}/audio/espeak \
			libnspr4.so:${PORTSDIR}/devel/nspr \
			libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
			libpng15.so:${PORTSDIR}/graphics/png \
			libminizip.so:${PORTSDIR}/archivers/minizip

USES=			gmake openal:al perl5 python:build tar:bzip2
USE_GL=			yes
USE_SDL=		sdl
USE_GNUSTEP=		yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_BUILD=	yes
USE_MAKEFILE=		yes
ALL_TARGET=		release-deployment
USE_PERL5=		build

SUB_FILES=	oolite
SUB_LIST=	GNUSTEP_SYSTEM_TOOLS="${GNUSTEP_SYSTEM_TOOLS}"

WRKSRC=	${WRKDIR}/${DISTNAME}
RELEASEDIR=	${WRKSRC}/oolite.app
DATADIR=	${GNUSTEP_LOCAL_APPS}/oolite.app
PORTDATA=	Resources
PORTDOCS=	*.pdf CHANGELOG.TXT contributors.txt

PLIST_FILES+=	bin/oolite %%DATADIR%%/oolite \
		share/applications/oolite.desktop \
		share/pixmaps/oolite-icon.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900014
BUILD_DEPENDS+=	clang34:${PORTSDIR}/lang/clang34
CC=		${LOCALBASE}/bin/clang34
CXX=		${LOCALBASE}/bin/clang++34
CPP=		${LOCALBASE}/bin/clang-cpp34
.elif exists(${CC})
CCVERSION!=	${CC} --version
COMPILER_VERSION=	${CCVERSION:M[0-9].[0-9]*:C/([0-9]).?/\1/g}
COMPILER_IS_CLANG=	${CCVERSION:Mclang}

# Check for LLVM/Clang v3.4.1
.if ${COMPILER_IS_CLANG} && ${COMPILER_VERSION} == 341
# Force to use optimization for size, because of speed optimization error(s)
# for ${WRKSRC}/src/Core/Scripting/OOJavaScriptEngine.m file
ADD_OBJCFLAGS=	s|-std=c99|-std=c99 -Os|
.endif
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's/GNUSTEP_USER_ROOT/GNUSTEP_LOCAL_ROOT/ ; \
		s/sdl-config/$${SDL_CONFIG}/ ; \
		s|-lstdc++|`$${SDL_CONFIG} --libs` -lstdc++| ; \
		s|:src/Core/MiniZip|| ; \
		s|-Isrc/Core/MiniZip|-I$${LOCALBASE}/include/minizip| ; \
		s|-lz|-lminizip| ; \
		/ioapi.c/d ; /unzip.c/d ; \
		s|/usr/X11R6|$${LOCALBASE}| ; ${ADD_OBJCFLAGS}' \
		${WRKSRC}/GNUmakefile
# Conversion needed for unsigned int type for using isfinite function
	${REINPLACE_CMD} -e 's|isfinite(uValue)|isfinite((long double)uValue)|' \
		${WRKSRC}/src/Core/Scripting/OOJSPlayerShip.m
# Change value of the SAVEDIR define
	${REINPLACE_CMD} -e 's|oolite-saves|\.oolite-saves|' \
		${WRKSRC}/src/Core/NSFileManagerOOExtensions.h

do-install:
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/oolite ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${RELEASEDIR}/oolite ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
