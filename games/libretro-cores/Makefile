# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	libretro-cores
PORTVERSION=	0.20161109
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	yuri@rawbw.com
COMMENT=	Core pack for RetroArch

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS+=	libinotify.so:devel/libinotify    # for libretro-lutro
LIB_DEPENDS+=	libcurl.so:ftp/curl               # for Craft

ONLY_FOR_ARCHS=	i386 amd64

# core list (complete list that libretro distributes: http://buildbot.libretro.com/nightly/linux/x86_64/latest/)
ALL_CORES+=	libretro:libretro-2048:2048:6730b2b:x
ALL_CORES+=	libretro:4do-libretro:4do:f433301:x
ALL_CORES+=	libretro:81-libretro:81:b484a7a:x
ALL_CORES+=	libretro:blueMSX-libretro:bluemsx:ee4ff9c:x
ALL_CORES+=	libretro:bsnes-libretro:bsnes:365c5c1:accuracy,balanced,performance
ALL_CORES+=	libretro:CATSFC-libretro:catsfc:5907687:x
ALL_CORES+=	libretro:Craft:craft:dc6ae44:x
ALL_CORES+=	libretro:desmume:desmume:ab1bd5a:x
ALL_CORES+=	libretro:Dinothawr:dinothawr:4ef365e:x
ALL_CORES+=	libretro:dosbox-libretro:dosbox:e1ab4fc:x
ALL_CORES+=	libretro:emux:emux:834f9f9:chip8,gb,nes,sms
ALL_CORES+=	libretro:fba_cores_cps1:fb_alpha_cps1:5614a9a:x
ALL_CORES+=	libretro:fba_cores_cps2:fb_alpha_cps2:f806c77:x
ALL_CORES+=	libretro:fbalpha:fbalpha:6d36b3a:x
ALL_CORES+=	libretro:libretro-fceumm:fceumm:50d0dfe:x
ALL_CORES+=	libretro:fmsx-libretro:fmsx:91e6deb:x
ALL_CORES+=	libretro:fuse-libretro:fuse:6cda7ed:x
ALL_CORES+=	libretro:gambatte-libretro:gambatte:59fb6a6:x
ALL_CORES+=	libretro:Genesis-Plus-GX:genesis_plus_gx:3c6d839:x
ALL_CORES+=	libretro:gpsp:gpsp:4d860ae:x
ALL_CORES+=	libretro:gw-libretro:gw:0408906:x
ALL_CORES+=	libretro:libretro-handy:handy:84f188b:x
ALL_CORES+=	libretro:hatari:hatari:4930236:x
ALL_CORES+=	libretro:imageviewer-libretro:imageviewer:ae1465c:x
ALL_CORES+=	libretro:libretro-lutro:lutro:4d6da23:x
ALL_CORES+=	libretro:mame2000-libretro:mame2000:b4ca94b:x
ALL_CORES+=	libretro:mame2003-libretro:mame2003:57f6dae:x
ALL_CORES+=	libretro:mame2014-libretro:mame2014:2e3943d:x
#ALL_CORES=	libretro:mame:mame:cfa60c7:x BROKEN: fails to build https://github.com/libretro/mame/issues/15
ALL_CORES+=	libretro:beetle-gba-libretro:mednafen_gba:b17b3a2:x
ALL_CORES+=	libretro:beetle-lynx-libretro:mednafen_lynx:76fd67f:x
ALL_CORES+=	libretro:beetle-ngp-libretro:mednafen_ngp:15887b8:x
ALL_CORES+=	libretro:beetle-pce-fast-libretro:mednafen_pce_fast:8daf99e:x
ALL_CORES+=	libretro:beetle-pcfx-libretro:mednafen_pcfx:89d16cd:x
ALL_CORES+=	libretro:beetle-psx-libretro:mednafen_psx:e661a34:x
ALL_CORES+=	libretro:beetle-bsnes-libretro:mednafen_snes:ff6938b:x
ALL_CORES+=	libretro:beetle-supergrafx-libretro:mednafen_supergrafx:42c8c0d:x
ALL_CORES+=	libretro:beetle-vb-libretro:mednafen_vb:c99ba93:x
ALL_CORES+=	libretro:beetle-wswan-libretro:mednafen_wswan:afbcd37:x
ALL_CORES+=	libretro:meteor-libretro:meteor:38b10c0:x
ALL_CORES+=	mgba-emu:mgba:mgba:8fd14f4:x
#ALL_CORES+=	libretro:mupen64plus-libretro:mupen64plus:7db9296:x BROKEN: needs GLES,GL....
ALL_CORES+=	libretro:nestopia:nestopia:b8de4c8:x
ALL_CORES+=	libretro:nxengine-libretro:nxengine:ee65158:x
ALL_CORES+=	libretro:libretro-o2em:o2em:0d54d35:x
ALL_CORES+=	libretro:pcsx_rearmed:pcsx_rearmed:1aa232f:x
ALL_CORES+=	libretro:picodrive:picodrive:0d87bd6:x
#ALL_CORES+=	libretro:pocketsnes-libretro:pocketsnes:5339c79:x BROKEN: asm
#ALL_CORES+=	libretro:libretro-ppsspp:ppsspp:ea17e27:x BROKEN: requires multiple distfiles?
ALL_CORES+=	libretro:libretro-prboom:prboom:d1479f0:x
ALL_CORES+=	libretro:prosystem-libretro:prosystem:b675fdf:x
ALL_CORES+=	libretro:QuickNES_Core:quicknes:ff4c152:x
ALL_CORES+=	libretro:reicast-emulator:reicast:3601150:x
#ALL_CORES+=	libretro:libretro-remotejoy:remotejoy:2e99718:x BROKEN: needs linux USB, is this linux-only?
ALL_CORES+=	libretro:scummvm:scummvm:47bb6e5:x
ALL_CORES+=	libretro:snes9x:snes9x:ccf1ee2:x
ALL_CORES+=	libretro:snes9x2010:snes9x2010:dfb7eef:x
ALL_CORES+=	libretro:stella-libretro:stella:3aa5737:x
ALL_CORES+=	libretro:tgbdual-libretro:tgbdual:6f8bfe5:x
ALL_CORES+=	libretro:tyrquake:tyrquake:34bd008:x
ALL_CORES+=	libretro:libretro-uae:puae:99af768:x
ALL_CORES+=	libretro:vba-next:vba_next:7623670:x
ALL_CORES+=	libretro:vbam-libretro:vbam:bedddba:x
ALL_CORES+=	libretro:libretro-vecx:vecx:1a86382:x
ALL_CORES+=	libretro:virtualjaguar-libretro:virtualjaguar:8be4390:x
ALL_CORES+=	libretro:yabause:yabause:dac3c5a:x

USE_GITHUB=	nodefault

# variables that depend on ALL_CORES
GH_TUPLE=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\1:\2:\4:\3/\2,}
CORE_DIRS=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\2,}

#PLIST_FILES+=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),libexec/libretro/\3_libretro.so,}
.for CORE in ${ALL_CORES}
.for A in ${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\5,:S/,/ /g}
PLIST_FILES+=	libexec/libretro/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}_${A}_libretro.so
.endfor
GIT_REV+=	GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}=$$(git ls-remote https://github.com/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\1,}/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\2,}.git | ${GREP} HEAD | ${SED} -E "s/^(.......).*/\\1/g") &&
GIT_REV_ECHO+=	echo "GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}=$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}" &&
GIT_REV_CHANGE+=	if [ "${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\4,}" != "$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}" ]; then echo "upstream revision changed: core=${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,} old=${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\4,}  new=$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}"; fi &&
.endfor

PLIST_FILES:=	${PLIST_FILES:S/_x_libretro/_libretro/}

WRKSRC=		${WRKDIR}/all-cores

USES=		compiler:c++11-lib dos2unix gmake lua:53 python:2 ssl
USE_LDCONFIG=	yes
USE_GL=		gl
DOS2UNIX_FILES=	hatari/Makefile.libretro 81-libretro/81/sp0256.c libretro-uae/Makefile

BROKEN=	checksum mismatch

.include <bsd.port.pre.mk>

# Avoid a lot of patching for 9.
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_CXXSTD=	gnu++11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/"__VA_ARGS__/" __VA_ARGS__/' \
		${WRKSRC}/desmume/desmume/src/wifi.cpp

do-build:
	@for dir in ${CORE_DIRS}; do \
	  ${ECHO_MSG} "===>  Building for ${PKGNAME}: core $${dir} ($$(date))"; \
	  cd ${WRKSRC}/$${dir}; \
	  if [ -f Makefile.freebsd ]; then \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.freebsd ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  elif [ -f Makefile.libretro ]; then \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.libretro ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  elif [ -f CMakeLists.txt ]; then \
	    ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake . && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  else \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  fi; \
	done;

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	@for dir in ${CORE_DIRS}; do \
	  ${INSTALL_LIB} $$(find ${WRKSRC}/$${dir}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro; \
	done;

post-install:
	@${RM} ${STAGEDIR}/${PREFIX}/libexec/libretro/libcurl.so

print-upstream-revisions:
	@${ECHO} "--begin print upstream revisions--" && \
		${GIT_REV} \
		${GIT_REV_ECHO} \
	${ECHO} "--end print upstream revisions--"

print-updated-revisions:
	@${ECHO} "--begin print updated revisions--" && \
		${GIT_REV} \
		${GIT_REV_CHANGE} \
	${ECHO} "--end print updated revisions--"

.include <bsd.port.post.mk>
