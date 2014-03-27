# Created by: Alexander G. Chetirbock <bock@bock.nnov.ru>
# $FreeBSD$

PORTNAME=	doomlegacy
DISTVERSION=	1.44_alpha4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://doomlegacy.sourceforge.net/releases/ \
		http://freebsd.nsu.ru/distfiles/:wad
DISTNAME=	${PORTNAME}_${DISTVERSION}_src_r${SVN_REV}
# legacy.wad is not included in distfile and must be regenerated manually
# when needed (its contents change); luckily, it doesn't happen too often
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} legacy_wad${EXTRACT_SUFX}:wad
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Improved and extended version of Doom

LICENSE=	GPLv2

USES=		gmake zip
USE_GL=		glu
USE_SDL=	mixer sdl

CFLAGS+=	-DSVN_REV=\\\"${SVN_REV}\\\"
WRKSRC=		${WRKDIR}/${PORTNAME}_${DISTVERSION}/src

PLIST_FILES=	bin/${PORTNAME} share/doom/legacy.wad
PORTDOCS=	*

SVN_REV=	999

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	ASM

.if exists(/usr/include/netipx/ipx.h)
OPTIONS_DEFINE+=	IPX
IPX_DESC=	IPX protocol support
.endif

ASM_BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
ASM_MAKE_ENV=		USEASM=1 OLD_DEPENDENCIES=1

.include <bsd.port.options.mk>

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|<malloc|<stdlib|' ${WRKSRC}/p_setup.c \
		${WRKSRC}/r_data.c ${WRKSRC}/w_wad.c
# Unbreak the build when using optimized assembly routines
	${REINPLACE_CMD} -e 's|dc_transmap|dc_translucentmap| ; \
		s|colormaps|reg_&|' ${WRKSRC}/tmap.nas
# Ensure that gathered memory stats are printed correctly
	${REINPLACE_CMD} -e 's|total, free|(int)total, (int)free|' \
		${WRKSRC}/z_zone.c
# Make local directory name less ambiguous; adjust default WAD search path
	${REINPLACE_CMD} -e 's|\.legacy|.${PORTNAME}| ; \
		/DEFWADS1/s|/.*|${DMDIR}"|' ${WRKSRC}/doomdef.h
# Provide better support for relative paths (for `-iwad' switch)
	${REINPLACE_CMD} -e "s|s\[0\] ==[^)]*|strchr(s, '/')|" \
			${WRKSRC}/d_main.c
.if ! ${PORT_OPTIONS:MIPX}
	${REINPLACE_CMD} -e '/USE_IPX/s|define|undef|' ${WRKSRC}/doomdef.h
	${REINPLACE_CMD} -e 's| -lipx||' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/doomlegacy ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/legacy.wad ${STAGEDIR}${DMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/_doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
