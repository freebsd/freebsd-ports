PORTNAME=	libretro-picodrive
DISTVERSION=	0.20230811
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MegaDrive/MegaCD/32X emulator
WWW=		https://github.com/libretro/picodrive

LICENSE=	MAME-License
LICENSE_NAME=	MAME license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	all archs except x86 report error: unsupported arch

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	picodrive
GH_TAGNAME=	570319349588288f64c676123244acdb0be33881

GH_TUPLE=	irixxxx:libpicofe:7b58e15:libpicofe/platform/libpicofe \
		notaz:cyclone68000:425e3a4:cyclone68000/cpu/cyclone \
		digital-sound-antiques:emu2413:1.5.9:emu2413/pico/sound/emu2413 \
		rtissera:libchdr:a20e04c:libchdr/pico/cd/libchdr \
		mackron:dr_libs:dd762b8:dr_libs/platform/common/dr_libs

PLIST_FILES=	lib/libretro/picodrive_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/picodrive_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
