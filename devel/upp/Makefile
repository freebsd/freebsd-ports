# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	upp
PORTVERSION=	9251
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2015.2/
DISTNAME=	${PORTNAME}-x11-src-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${BUILD_WRKSRC}/Core/Copying

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libnotify.so:devel/libnotify

USES=		execinfo gmake
USE_XORG=	xft
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/uppsrc

MACRO_FLAGS=	-DflagGUI -DflagMT -DflagGCC -DflagSHARED -DflagPOSIX -DflagBSD -DflagFREEBSD

MAKE_ARGS=	UPPOUT="../_out/" OutFile="../theide" \
		Macro="${MACRO_FLAGS}" \
		LIBPATH="-L${LOCALBASE}/lib -L/usr/lib" \
		CINC="-I. -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/gtk-2.0 -I${LOCALBASE}/include/atk-1.0 \
		-I${LOCALBASE}/include/cairo -I${LOCALBASE}/include/gdk-pixbuf-2.0 \
		-I${LOCALBASE}/include/pango-1.0 -I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/lib/glib-2.0/include -I/usr/include"

MAKE_JOBS_UNSAFE=	yes

BROKEN_ia64=	Does not compile on ${ARCH}
BROKEN_powerpc=	Does not compile on ${ARCH}
BROKEN_sparc64=	Does not compile on ${ARCH}

PORTDATA=	bazaar examples reference tutorial uppsrc *.bm

DESKTOP_ENTRIES="TheIDE" "IDE for cross-platform C++ development" \
		"${DATADIR}/uppsrc/ide/theide-48.png" "theide" \
		"Development;IDE;GTK;" false

OPTIONS_DEFINE=	SDL OPENGL MYSQL PGSQL USEMALLOC
USEMALLOC_DESC=	Compile without U++ heap allocator
USEMALLOC_VARS=	MACRO_FLAGS+=-DflagUSEMALLOC

PLIST_FILES=	bin/theide

SDL_USE=	sql
OPENGL_USE=	gl
MYSQL_USE=	mysql=yes
PGSQL_USES=	pgsql

post-patch: .SILENT
	${MV} ${BUILD_WRKSRC}/Makefile.in ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/^CXX =/d;/^CFLAGS =/d;/^CXXFLAGS =/d;/^LDFLAGS =/d' \
		-e 's|-Linux-|-BSD-FreeBSD-|' \
		-e 's|-ldl|-lXau -lXdmcp -lfreetype -lexpat -lxcb -lpng -lexecinfo|' \
		${BUILD_WRKSRC}/Makefile
# Use simplified upstream patch to fix the build
	${REINPLACE_CMD} -e '/ftoutln.h/d' ${BUILD_WRKSRC}/CtrlCore/GtkDrawText.cpp

post-build: .SILENT
	${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC.bm
	${ECHO_CMD} "COMMON_CPP_OPTIONS = \"-std=c++0x\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_FLAGS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINK = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_BLITZ = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_OPTIONS = \"-O2 -ffunction-sections -fdata-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_SIZE_OPTIONS = \"-Os -finline-limit=20 -ffunction-sections -fdata-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_FLAGS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_LINK = \"-Wl,--gc-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "INCLUDE = \"${LOCALBASE}/include;${LOCALBASE}/include/freetype2;${LOCALBASE}/include/gtk-2.0;${LOCALBASE}/include/atk-1.0;${LOCALBASE}/include/cairo;${LOCALBASE}/include/gdk-pixbuf-2.0;${LOCALBASE}/include/pango-1.0;${LOCALBASE}/include/glib-2.0;${LOCALBASE}/lib/glib-2.0/include;/usr/include\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LIB = \"${LOCALBASE}/lib;/usr/lib\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LINKMODE_LOCK = \"0\";" >> ${WRKSRC}/GCC.bm
# Also create CLANG build method, based on GCC with some changes
	(cd ${WRKSRC} && ${CP} GCC.bm CLANG.bm && \
		${SED} -i '' -e '/^BUILDER/s|GCC|CLANG| ; \
		s| -fdata-sections|| ; s| -finline-limit=20||' CLANG.bm)
	${ECHO_CMD} "COMMON_OPTIONS = \"-Wno-logical-op-parentheses\";" >> ${WRKSRC}/CLANG.bm
	${ECHO_CMD} "ALLOW_PRECOMPILED_HEADERS = \"0\";" >> ${WRKSRC}/CLANG.bm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/theide ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA} -not ( -type d -empty )" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
