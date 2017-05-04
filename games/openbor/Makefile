# $FreeBSD$

PORTNAME=	openbor
# Hint: svn revision is git rev-list --count ${GH_TAGNAME}
PORTVERSION=	3.0.r4432
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Moddable fighting game engine (aka Beats of Rage)

LICENSE=	BSD3CLAUSE GPLv2+ ISCL
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2+ =	${_LICENSE_STORE}/GPLv2 # source/gfxlib/hq2x.c
LICENSE_FILE_ISCL=	${WRKSRC}/source/webmlib/nestegg/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libvpx.so:multimedia/libvpx

USE_GITHUB=	yes
GH_ACCOUNT=	DCurrent
GH_TAGNAME=	ba1eb4f # git v4432 is actually svn r4437

USES=		gmake pkgconfig
USE_CSTD=	gnu89
USE_SDL=	gfx2
WRKSRC_SUBDIR=	engine
MAKE_ENV=	BUILD_LINUX=1 SDKPATH="${LOCALBASE}" \
		GCC_TARGET="${CONFIGURE_TARGET:S/amd64/x86_64/}"
MAKE_ARGS=	CC="${CC}" LIBRARIES="${LOCALBASE}/lib" \
		TARGET_ARCH=${ARCH:S/i386/x86/} ARCHFLAGS="" \
		TARGET_FINAL='${TARGET}' BUILD_MMX="" ECHO="${ECHO}"
LDFLAGS+=	-Wl,--as-needed # ogg, pthread, zlib
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	README

DESKTOP_ENTRIES="OpenBOR" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=		TREMOR
OPTIONS_DEFAULT=	${MACHINE_CPU:Msoftfp:C/.+/TREMOR/}
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT_i386=	MMX # runtime detection

MMX_BUILD_DEPENDS=	yasm:devel/yasm
MMX_MAKE_ARGS=		BUILD_MMX=1

TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_MAKE_ARGS=	BUILD_TREMOR=1 BUILD_VORBIS=""
TREMOR_LIB_DEPENDS_OFF=	libvorbisfile.so:audio/libvorbis

post-patch:
	@${REINPLACE_CMD} -e 's/ -O[0-9]//; s/ -g//; s/ -Werror//' \
		-e 's/ -fomit-frame-pointer//' \
		-e 's/ -freorder-blocks//' \
		-e 's/ -Wl,-rpath,$$(LIBRARIES)//' \
		-e '/echo/!s/	@/	/' \
		-e 's/@echo/@$$(ECHO)/' \
		-e 's/$$(LIBS)/$$(LDFLAGS) &/' \
		${WRKSRC}/Makefile
	@${GREP} -Flr 'malloc.h' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		's,malloc\.h,stdlib.h,'
	@${REINPLACE_CMD} -e 's/^function \(.*\) {/\1() {/' \
		-e 's/^get_revnum$$/VERSION_BUILD=${PORTVERSION:E:S/^r//}/' \
		${WRKSRC}/version.sh

do-configure:
	(cd ${WRKSRC} && ${SH} ./version.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OpenBOR.elf \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/resources/OpenBOR_Icon_128x128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
