# Created by: Alexander G. Chetirbock <bock@bock.nnov.ru>
# $FreeBSD$

PORTNAME=	doomlegacy
DISTVERSION=	1.44_alpha3
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://doomlegacy.sourceforge.net/releases/ \
		http://freebsd.nsu.ru/distfiles/:wad
DISTNAME=	${PORTNAME}_${DISTVERSION}_src_r${SVN_REV}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} legacy_wad${EXTRACT_SUFX}:wad
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved and extended version of Doom

LICENSE=	GPLv2

USE_ZIP=	yes
USE_GL=		glu
USE_GMAKE=	yes
USE_SDL=	mixer sdl

MAKE_ENV=	OLD_DEPENDENCIES=1		# since .dep file is removed
CFLAGS+=	-DSVN_REV=\\\"${SVN_REV}\\\"
WRKSRC=		${WRKDIR}/${PORTNAME}_${DISTVERSION:S/.//}/src

PLIST_FILES=	bin/${PORTNAME} share/doom/legacy.wad
PORTDOCS=	*

SVN_REV=	845

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASM}
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
MAKE_ENV+=	USEASM=1
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|<malloc|<stdlib|' ${WRKSRC}/p_setup.c \
		${WRKSRC}/r_data.c ${WRKSRC}/w_wad.c
# Unbreak the build when using optimized assembly routines
	${REINPLACE_CMD} -e 's|dc_transmap|dc_translucentmap| ; \
		s|colormaps|reg_&|' ${WRKSRC}/tmap.nas
# Ensure that gathered memory stats are printed correctly
	${REINPLACE_CMD} -e 's|total, free|(int)total, (int)free|' \
		${WRKSRC}/z_zone.c
# Adjust config and save games directory name to be less ambiguous
	${REINPLACE_CMD} -e 's|\.legacy|.${PORTNAME}|' ${WRKSRC}/doomdef.h
# Change default value of DOOMWADDIR; better support for relative paths
	${REINPLACE_CMD} -e 's|\(doomwaddir = \)"\."|\1"${DMDIR}"| ; \
		1306,1309d' -e "s|s\[0\] ==[^)]*|strchr(s, '/')|" \
			${WRKSRC}/d_main.c
# Remove broken dependency file (wrong paths inside) and a copy of GPL
	${RM} ${WRKSRC}/sdl.dep ; ${TOUCH} ${WRKSRC}/sdl.dep
	${RM} ${WRKSRC}/_doc/LICENSE.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/doomlegacy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/legacy.wad ${DMDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/_doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
