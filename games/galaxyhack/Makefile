# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	galaxyhack
PORTVERSION=	1.74
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/Fleet%20packages/020906:fleets
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AI script based strategy game

LICENSE=	GPLv2

BUILD_DEPENDS=	winicontoppm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2

OPTIONS_DEFINE=	FLEETS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
OPTIONS_SUB=	yes
FLEETS_DESC=	Additional fleets

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		dos2unix gmake tar:bzip2
USE_SDL=	gfx image mixer sdl
ALL_TARGET=	${PORTNAME}

SUB_FILES=	${PORTNAME}-sh

PLIST_FILES=	bin/galaxyhack \
		libexec/galaxyhack \
		share/pixmaps/galaxyhack.png
PORTDATA=	*

DESKTOP_ENTRIES="GalaxyHack" "" "${PREFIX}/share/pixmaps/galaxyhack.png" \
		"${PORTNAME}" "" ""

FLEETS_DISTFILES=		gh_fleets_020906.zip:fleets
FLEETS_EXTRACT_DEPENDS=		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
OPTIMIZED_CFLAGS_MAKE_ENV=	OPTIMIZED_CFLAGS=YES

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MFLEETS}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${UNZIP_CMD} -o ${DISTDIR}/${FLEETS_DISTFILES:S/:fleets//} \
		-x "*/CVS/*" "*/.svn/*" -d ${STAGEDIR}${DATADIR}
.endif

post-build:
	@(winicontoppm ${WRKSRC}/../GalaxyHack.ico | pnmtopng \
		> ${WRKDIR}/galaxyhack.png)

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} ${PORTNAME}-sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME})
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} settings.dat \
		${STAGEDIR}${DATADIR})
.for d in fleets gamedata graphics music standardpictures
	@(cd ${WRKSRC}/.. && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKDIR} && ${INSTALL_DATA} galaxyhack.png \
		${STAGEDIR}/${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
