# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	upp
PORTVERSION=	10804
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2017.1/
DISTNAME=	${PORTNAME}-x11-src-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${BUILD_WRKSRC}/Core/Copying

USES=		compiler:c++11-lib

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/uppsrc

MACRO_FLAGS=	-DflagBSD -Dflag${OPSYS:tu}
CINC_GUI=	-I. -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/gtk-2.0 -I${LOCALBASE}/include/atk-1.0 \
		-I${LOCALBASE}/include/cairo -I${LOCALBASE}/include/gdk-pixbuf-2.0 \
		-I${LOCALBASE}/include/pango-1.0 -I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/lib/glib-2.0/include -I/usr/include
CINC_CONSOLE=	-I. -I${LOCALBASE}/include -I/usr/include

BROKEN_aarch64=	Does not compile on ${ARCH}: error Unknown CPU architecture
BROKEN_powerpc=	Does not compile on ${ARCH}
BROKEN_sparc64=	Does not compile on ${ARCH}

PORTDATA=	bazaar examples reference tutorial uppsrc *.bm

OPTIONS_DEFINE=	MYSQL OPENGL PGSQL SCD SDL USEMALLOC
OPTIONS_DEFAULT=	IDE SCD UMK
OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	IDE UMK
BUILD_DESC=	Build/install
IDE_DESC=	Build/install TheIDE (integrated development environment)
IDE_DESKTOP_ENTRIES=	"TheIDE" "IDE for cross-platform C++ development" \
		"${DATADIR}/uppsrc/ide/theide-48.png" "theide" \
		"Development;IDE;GTK;" false
IDE_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libnotify.so:devel/libnotify \
		libpng.so:graphics/png
IDE_PLIST_FILES=	bin/theide ${MANPREFIX}/man/man1/theide.1.gz
IDE_USE=	XORG=x11,xau,xcb,xcursor,xdmcp,xext,xfixes,xft,xi,xinerama,xrandr,xrender \
		GNOME=cairo,gdkpixbuf2,gtk20
IDE_USES=	gmake
UMK_DESC=	Build/install UMK (U++ MaKe command line utility)
UMK_PLIST_FILES=	bin/umk ${MANPREFIX}/man/man1/umk.1.gz
USEMALLOC_DESC=	Compile without U++ heap allocator
USEMALLOC_VARS=	MACRO_FLAGS+=-DflagUSEMALLOC
SCD_DESC=	Install spelling dictionaries (*.scd files)
SCD_VARS=	PORTDATA+=*.scd
SDL_USE=	sql
OPENGL_USE=	gl
MYSQL_USE=	mysql=yes
PGSQL_USES=	pgsql
LLD_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
# Disable some warnings for Clang
CXXFLAGS+=	-Wno-logical-op-parentheses
.endif

post-patch: .SILENT
	${CP} ${BUILD_WRKSRC}/Makefile.in ${BUILD_WRKSRC}/Makefile
	${CP} ${BUILD_WRKSRC}/uMakefile.in ${BUILD_WRKSRC}/uMakefile
	${REINPLACE_CMD} -i '' -e '/^CXX[[:blank:]]*=/d; /^CFLAGS[[:blank:]]*=/d; \
		/^LDFLAGS[[:blank:]]*=/d ; \
		/^Macro[[:blank:]]*=/s|-DflagLINUX|${MACRO_FLAGS}| ; \
		s|\(^CXXFLAGS\)[[:blank:]]*=.*\(-std=.*\)|\1 += \2| ; \
		s|\(^LIBPATH\)[[:blank:]]*=.*|\1 = -L${LOCALBASE}/lib -L/usr/lib|' \
		${BUILD_WRKSRC}/Makefile \
		${BUILD_WRKSRC}/uMakefile
	${REINPLACE_CMD} -i '' -e 's|\(^CINC\)[[:blank:]]*=.*|\1 = ${CINC_GUI}| ; \
		/^OutDir_/s|-Gui-Linux|| ; /^OutDir_/s|-Mt|| ; \
		s|-ldl|-lXau -lXdmcp -lxcb -lexecinfo|' \
		${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -i '' -e 's|\(^CINC\)[[:blank:]]*=.*|\1 = ${CINC_CONSOLE}| ; \
		/^OutDir_/s|-Linux|| ; \
		s|-ldl|-lexecinfo|' \
		${BUILD_WRKSRC}/uMakefile

do-build: .SILENT
	${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC.bm
	${ECHO_CMD} "COMMON_CPP_OPTIONS = \"-std=c++11\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_FLAGS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUG_LINK = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_BLITZ = \"0\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_OPTIONS = \"-O2 -ffunction-sections -fdata-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_FLAGS = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "RELEASE_LINK = \"-Wl,--gc-sections\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "INCLUDE = \"${LOCALBASE}/include;${LOCALBASE}/include/freetype2;${LOCALBASE}/include/gtk-2.0;${LOCALBASE}/include/atk-1.0;${LOCALBASE}/include/cairo;${LOCALBASE}/include/gdk-pixbuf-2.0;${LOCALBASE}/include/pango-1.0;${LOCALBASE}/include/glib-2.0;${LOCALBASE}/lib/glib-2.0/include;/usr/include\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LIB = \"${LOCALBASE}/lib;/usr/lib\";" >> ${WRKSRC}/GCC.bm
	${ECHO_CMD} "LINKMODE_LOCK = \"0\";" >> ${WRKSRC}/GCC.bm
# Also create CLANG build method, based on GCC with some changes
	(cd ${WRKSRC} && ${CP} GCC.bm CLANG.bm && \
		${SED} -i '' -e '/^BUILDER/s|GCC|CLANG| ; s| -fdata-sections||' \
		CLANG.bm)
	${ECHO_CMD} "COMMON_OPTIONS = \"-Wno-logical-op-parentheses\";" >> ${WRKSRC}/CLANG.bm
	${ECHO_CMD} "ALLOW_PRECOMPILED_HEADERS = \"0\";" >> ${WRKSRC}/CLANG.bm

do-build-IDE-on:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} Makefile ${_MAKE_JOBS} UPPOUT="../_out/" OutFile="../theide")

do-build-UMK-on:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} uMakefile ${_MAKE_JOBS} UPPOUT="../_out/" OutFile="../umk")

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR} \
		"-not ( -type d -empty )")
	(cd ${STAGEDIR}${DATADIR}/uppsrc && ${RM} build_info.h *Makefile*)

do-install-IDE-on:
	${INSTALL_PROGRAM} ${WRKSRC}/theide ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${BUILD_WRKSRC}/ide/theide.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-UMK-on:
	${INSTALL_PROGRAM} ${WRKSRC}/umk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${BUILD_WRKSRC}/umk/umk.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
