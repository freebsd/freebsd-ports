# Created by: Alexander G. Chetirbock <bock@bock.nnov.ru>
# $FreeBSD$

PORTNAME=	doomlegacy
PORTVERSION=	1.45.2
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION:S,_,%20,}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${DISTVERSION}_common.zip

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Improved and extended version of Doom

LICENSE=	GPLv2

USES=		gmake tar:bzip2
USE_GL=		glu
USE_SDL=	mixer sdl

CFLAGS+=	-DSVN_REV=\\\"1139\\\"

PLIST_FILES=	bin/${PORTNAME} share/doom/legacy.wad
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	ASM

.if exists(/usr/include/netipx/ipx.h)
OPTIONS_DEFINE+=	IPX
IPX_DESC=	IPX protocol support
.endif

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_MAKE_ENV=		USEASM=1 OLD_DEPENDENCIES=1

.include <bsd.port.options.mk>

post-patch: .SILENT
# Adjust default WAD search path
	${REINPLACE_CMD} -e '/DEFWADS1/s|/.*|${DMDIR}"|' \
		${WRKSRC}/src/doomdef.h
# Provide better support for relative paths (for `-iwad' switch)
	${REINPLACE_CMD} -e "s|s\[0\] ==[^)]*|strchr(s, '/')|" \
		${WRKSRC}/src/d_main.c
# Unbreak against Clang (https://llvm.org/bugs/show_bug.cgi?id=10365)
	${REINPLACE_CMD} -e 's,%cc,cc,' ${WRKSRC}/src/m_fixed.h
# Unbreak against Clang 3.7.0
	${REINPLACE_CMD} -e '/draw_dir_line(/s,inline,static &,' \
		${WRKSRC}/src/m_menu.c
.if ! ${PORT_OPTIONS:MIPX}
	${REINPLACE_CMD} -e '/USE_IPX/s|define|undef|' ${WRKSRC}/src/doomdef.h
	${REINPLACE_CMD} -e 's| -lipx||' ${WRKSRC}/Makefile
.endif

pre-build:
	${ECHO_CMD} CC_ENVIRONMENT=1 MAKE_OPTIONS_PRESENT=1 HAVE_MIXER=1 | \
		${XARGS} -n 1 > ${BUILD_WRKSRC}/make_options
	${MAKE_CMD} -C ${BUILD_WRKSRC} dirs
	${MAKE_CMD} -C ${BUILD_WRKSRC} depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doomlegacy ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${PORTVERSION}/legacy.wad \
		${STAGEDIR}${DMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
