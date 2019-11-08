# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	galaxyhack
PORTVERSION=	1.74
PORTREVISION=	34
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/Fleet%20packages/020906:fleets
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AI script based strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	winicontoppm:graphics/netpbm
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	FLEETS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
OPTIONS_SUB=	yes
FLEETS_DESC=	Additional fleets

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		compiler:c++11-lang dos2unix gmake sdl tar:bzip2
USE_SDL=	gfx image mixer sdl
ALL_TARGET=	${PORTNAME}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

SUB_FILES=	${PORTNAME}-sh

PLIST_FILES=	bin/galaxyhack \
		libexec/galaxyhack \
		share/pixmaps/galaxyhack.png
PORTDATA=	*

DESKTOP_ENTRIES="GalaxyHack" "" "${PREFIX}/share/pixmaps/galaxyhack.png" \
		"${PORTNAME}" "" ""

FLEETS_DISTFILES=		gh_fleets_020906.zip:fleets
FLEETS_EXTRACT_DEPENDS=		${UNZIP_CMD}:archivers/unzip
OPTIMIZED_CFLAGS_MAKE_ENV=	OPTIMIZED_CFLAGS=YES

post-build:
	@(winicontoppm ${WRKSRC}/../GalaxyHack.ico | pnmtopng \
		> ${WRKDIR}/galaxyhack.png)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../settings.dat ${STAGEDIR}${DATADIR}
.for d in fleets gamedata graphics music standardpictures
	@(cd ${WRKSRC}/.. && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/galaxyhack.png ${STAGEDIR}/${PREFIX}/share/pixmaps

do-install-FLEETS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${UNZIP_CMD} -o ${DISTDIR}/${FLEETS_DISTFILES:S/:fleets//} \
		-x "*/CVS/*" "*/.svn/*" -d ${STAGEDIR}${DATADIR}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d ${DATADIR_REL} -type d -empty -exec \
		${ECHO_CMD} @dir {} \; >> ${TMPPLIST}

.include <bsd.port.mk>
