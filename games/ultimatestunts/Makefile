# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ultimatestunts
PORTVERSION=	0.7.7.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/sourcecode \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTNAME=	${PORTNAME}-srcdata-${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Racing game with elaborate stunts

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

USES=		compiler gettext gl openal:al,alut pkgconfig sdl
USE_GL=		gl glu
USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openal
MAKE_JOBS_UNSAFE=	yes
LLD_UNSAFE=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
CPPFLAGS+=	$$(pkgconf --cflags-only-I sdl)
LDFLAGS+=	$$(pkgconf --libs-only-L sdl)

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Ultimate Stunts" "" "${PORTNAME}" \
		"ustunts" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .svn -print0 | ${XARGS} -0 ${RM} -r
	@(cd ${WRKSRC} && ${CP} ${PORTNAME}.conf.in ${PORTNAME}.conf)

post-patch:
	${REINPLACE_CMD} -e 's|@usdatadir@|${DATADIR}|; \
		s|@PACKAGE_VERSION@|${PORTVERSION:R}|' \
		${WRKSRC}/${PORTNAME}.conf
	${REINPLACE_CMD} -e 's|^localedir.*|localedir = ${DATADIR}/lang|' \
		${WRKSRC}/po/Makefile.in.in
	${REINPLACE_CMD} -e 's|$${usdatadir}|${STAGEDIR}${DATADIR}|; \
		s|lang ||' \
		${WRKSRC}/data/Makefile.in

.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|install-exec install-data|install-exec|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
