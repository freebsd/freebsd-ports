# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	upp
PORTVERSION=	5485
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-x11-src-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LICENSE=	BSD

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		notify:${PORTSDIR}/devel/libnotify

USE_XORG=	xft
USE_GNOME=	gtk20
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/uppsrc
MAKE_JOBS_SAFE=	yes

MACRO_FLAGS=	-DflagGUI -DflagGCC -DflagSHARED -DflagPOSIX -DflagBSD -DflagFREEBSD

MAKE_ARGS=	UPPOUT="../_out/" OutFile="../theide" \
		Macro="${MACRO_FLAGS}" \
		LIBPATH="-L${LOCALBASE}/lib -L/usr/lib" \
		CINC="-I. -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/gtk-2.0 -I${LOCALBASE}/include/atk-1.0 \
		-I${LOCALBASE}/include/cairo -I${LOCALBASE}/include/gdk-pixbuf-2.0 \
		-I${LOCALBASE}/include/pango-1.0 -I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/include/libpng -I/usr/include"

PORTDATA=	bazaar examples reference tutorial uppsrc GCC.bm

DESKTOP_ENTRIES="TheIDE" "IDE for cross-platform C++ development" \
		"${DATADIR}/uppsrc/ide/theide-48.png" "theide" \
		"Development;IDE;GTK;" false

OPTIONS_DEFINE=	SDL OPENGL MYSQL PGSQL USEMALLOC
USEMALLOC_DESC=	Compile without U++ heap allocator

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.endif
.if ${PORT_OPTIONS:MOPENGL}
USE_GL=	gl
.endif
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.endif
.if ${PORT_OPTIONS:MUSEMALLOC}
MACRO_FLAGS+=	-DflagUSEMALLOC
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

pre-build: .SILENT
	${MV} ${BUILD_WRKSRC}/Makefile.in ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/^CC =/d;/^CFLAGS =/d;/^CXXFLAGS =/d;/^LDFLAGS =/d' \
	-e 's|$$(CC)|$$(CXX)|' \
	-e 's|-Linux-|-BSD-FreeBSD-|' \
	-e 's|-ldl|-lXau -lXdmcp -lfreetype -lexpat -lxcb -lpng|' \
	${BUILD_WRKSRC}/Makefile

post-build: .SILENT
	${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_FLAGS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINK = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_BLITZ = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_OPTIONS = \"-O2 -ffunction-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_SIZE_OPTIONS = \"-Os -finline-limit=20 -ffunction-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "INCLUDE = \"${LOCALBASE}/include;${LOCALBASE}/include/freetype2;${LOCALBASE}/include/gtk-2.0;${LOCALBASE}/include/atk-1.0;${LOCALBASE}/include/cairo;${LOCALBASE}/include/gdk-pixbuf-2.0;${LOCALBASE}/include/pango-1.0;${LOCALBASE}/include/glib-2.0;${LOCALBASE}/include/libpng;/usr/include\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LIB = \"${LOCALBASE}/lib;/usr/lib\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "REMOTE_HOST = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "REMOTE_OS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "REMOTE_TRANSFER = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "REMOTE_MAP = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LINKMODE_LOCK = \"0\";" >> ${WRKSRC}/GCC.bm

do-install: .SILENT
	${INSTALL_PROGRAM} ${WRKSRC}/theide ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${DATADIR}
.endif

post-install:
	@${ECHO_CMD} bin/theide >> ${TMPPLIST}

.include <bsd.port.mk>
