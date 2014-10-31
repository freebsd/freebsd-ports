# Created by: Alexander G. Chetirbock <bock@bock.nnov.ru>
# $FreeBSD$

PORTNAME=	doomlegacy
DISTVERSION=	1.45_beta1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION:S,_,%20,}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${DISTVERSION}_common.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved and extended version of Doom

LICENSE=	GPLv2

USES=		gmake tar:bzip2
USE_GL=		glu
USE_SDL=	mixer sdl

CFLAGS+=	-DSVN_REV=\\\"1107\\\"
WRKSRC=		${WRKDIR}/${DISTNAME:S,_beta1,,}/src

PLIST_FILES=	bin/${PORTNAME} share/doom/legacy.wad
PORTDOCS=	*

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
# Adjust default WAD search path
	${REINPLACE_CMD} -e '/DEFWADS1/s|/.*|${DMDIR}"|' ${WRKSRC}/doomdef.h
# Provide better support for relative paths (for `-iwad' switch)
	${REINPLACE_CMD} -e "s|s\[0\] ==[^)]*|strchr(s, '/')|" \
		${WRKSRC}/d_main.c
# Unbreak on big-endian architectures
	${REINPLACE_CMD} -e '150s|^|#include "m_swap.h"|' \
		${WRKSRC}/p_spec.c
	${REINPLACE_CMD} -e '60s|^|#include "m_swap.h"|' \
		${WRKSRC}/p_switch.c
.if ! ${PORT_OPTIONS:MIPX}
	${REINPLACE_CMD} -e '/USE_IPX/s|define|undef|' ${WRKSRC}/doomdef.h
	${REINPLACE_CMD} -e 's| -lipx||' ${WRKSRC}/Makefile
.endif

pre-build:
	${ECHO_CMD} MAKE_OPTIONS_PRESENT=1 HAVE_MIXER=1 | ${XARGS} -n 1 \
		> ${BUILD_WRKSRC}/../make_options
	${MAKE_CMD} -C ${BUILD_WRKSRC} dirs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/doomlegacy ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_1.45/legacy.wad \
		${STAGEDIR}${DMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/../docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
