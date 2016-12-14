# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	libretro-cores
PORTVERSION=	0.20151110
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	yuri@rawbw.com
COMMENT=	Core pack for RetroArch

BUILD_DEPENDS=	cmake:devel/cmake

ONLY_FOR_ARCHS=	i386 amd64

# core list (complete list that libretro distributes: http://buildbot.libretro.com/nightly/linux/x86_64/latest/)
ALL_CORES+=	libretro:libretro-2048:2048:d69235a:x
ALL_CORES+=	libretro:4do-libretro:4do:cbd700e:x
ALL_CORES+=	libretro:blueMSX-libretro:bluemsx:ee4ff9c:x
ALL_CORES+=	libretro:bsnes-libretro:bsnes:ee95143:accuracy,balanced,performance
ALL_CORES+=	libretro:CATSFC-libretro:catsfc:5907687:x
ALL_CORES+=	libretro:desmume:desmume:cae5945:x
ALL_CORES+=	libretro:Dinothawr:dinothawr:b49d969:x
ALL_CORES+=	libretro:dosbox-libretro:dosbox:bc5d578:x
ALL_CORES+=	libretro:emux:emux:be9022b:chip8,gb,nes,sms
ALL_CORES+=	libretro:fba_cores_cps1:fb_alpha_cps1:5614a9a:x
ALL_CORES+=	libretro:fba_cores_cps2:fb_alpha_cps2:f806c77:x
ALL_CORES+=	libretro:fbalpha:fbalpha:2a3256e:x
ALL_CORES+=	libretro:libretro-fceumm:fceumm:70ee9e6:x
ALL_CORES+=	libretro:fmsx-libretro:fmsx:4651948:x
ALL_CORES+=	libretro:fuse-libretro:fuse:c871953:x
ALL_CORES+=	libretro:gambatte-libretro:gambatte:59fb6a6:x
ALL_CORES+=	libretro:Genesis-Plus-GX:genesis_plus_gx:7d8d5f1:x
ALL_CORES+=	libretro:gpsp:gpsp:f1d14fb:x
ALL_CORES+=	libretro:gw-libretro:gw:95e3c4d:x
ALL_CORES+=	libretro:libretro-handy:handy:13d86fb:x
ALL_CORES+=	libretro:hatari:hatari:204dc6e:x
ALL_CORES+=	libretro:imageviewer-libretro:imageviewer:ae1465c:x
#ALL_CORES+=	libretro:mame:mame:a9d5a09:x BROKEN: missing file: https://github.com/libretro/mame/issues/38
ALL_CORES+=	libretro:mame2014-libretro:mame2014:6d370c1:x
ALL_CORES+=	libretro:beetle-gba-libretro:mednafen_gba:5110115:x
ALL_CORES+=	libretro:beetle-lynx-libretro:mednafen_lynx:a29513a:x
ALL_CORES+=	libretro:beetle-ngp-libretro:mednafen_ngp:f18354e:x
ALL_CORES+=	libretro:beetle-pce-fast-libretro:mednafen_pce_fast:6e2eaf7:x
ALL_CORES+=	libretro:beetle-pcfx-libretro:mednafen_pcfx:5b62ae8:x
ALL_CORES+=	libretro:beetle-psx-libretro:mednafen_psx:83b4b48:x
ALL_CORES+=	libretro:beetle-bsnes-libretro:mednafen_snes:7d9be82:x
ALL_CORES+=	libretro:beetle-supergrafx-libretro:mednafen_supergrafx:c6d3488:x
ALL_CORES+=	libretro:beetle-vb-libretro:mednafen_vb:085e0b6:x
ALL_CORES+=	libretro:beetle-wswan-libretro:mednafen_wswan:b850831:x
ALL_CORES+=	libretro:meteor-libretro:meteor:38b10c0:x
ALL_CORES+=	mgba-emu:mgba:mgba:b3d08ec:x
#ALL_CORES+=	libretro:mupen64plus-libretro:mupen64plus:7db9296:x BROKEN: needs GLES,GL....
ALL_CORES+=	libretro:nestopia:nestopia:dcaed96:x
ALL_CORES+=	libretro:nxengine-libretro:nxengine:4723600:x
ALL_CORES+=	libretro:libretro-o2em:o2em:c54042e:x
ALL_CORES+=	libretro:pcsx_rearmed:pcsx_rearmed:ce36c10:x
ALL_CORES+=	libretro:picodrive:picodrive:e912fdf:x
#ALL_CORES+=	libretro:pocketsnes-libretro:pocketsnes:5339c79:x BROKEN: asm
#ALL_CORES+=	libretro:libretro-ppsspp:ppsspp:ea17e27:x BROKEN: requires multiple distfiles?
ALL_CORES+=	libretro:libretro-prboom:prboom:d34af3f:x
ALL_CORES+=	libretro:prosystem-libretro:prosystem:7c8059c:x
ALL_CORES+=	libretro:QuickNES_Core:quicknes:518638b:x
#ALL_CORES+=	libretro:libretro-remotejoy:remotejoy:2e99718:x BROKEN: needs linux USB, is this linux-only?
ALL_CORES+=	libretro:scummvm:scummvm:c3e719a:x
ALL_CORES+=	libretro:snes9x:snes9x:ccf1ee2:x
# broken for now
ALL_CORES+=	libretro:snes9x2010:snes9x2010:dfb7eef:x
ALL_CORES+=	libretro:stella-libretro:stella:96619e4:x
ALL_CORES+=	libretro:tgbdual-libretro:tgbdual:b1bf294:x
ALL_CORES+=	libretro:tyrquake:tyrquake:8261e19:x
#ALL_CORES+=	libretro:libretro-uae:uae:7cbc230:x BROKEN: compile error https://github.com/libretro/libretro-uae/issues/4
ALL_CORES+=	libretro:vba-next:vba_next:0c20cd9:x
ALL_CORES+=	libretro:vbam-libretro:vbam:bedddba:x
ALL_CORES+=	libretro:libretro-vecx:vecx:be67ef1:x
ALL_CORES+=	libretro:virtualjaguar-libretro:virtualjaguar:ffec5c7:x
ALL_CORES+=	libretro:yabause:yabause:b121882:x

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

USES=		compiler:c++11-lib dos2unix gmake lua:53 python:2
USE_LDCONFIG=	yes
USE_GL=		gl
DOS2UNIX_FILES=	hatari/Makefile.libretro

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
	  else \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  fi; \
	done;

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	@for dir in ${CORE_DIRS}; do \
	  ${INSTALL_LIB} $$(find ${WRKSRC}/$${dir}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro; \
	done;

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
