# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	bomb-her-man
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GH \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Bomberman clone written in C++

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_GITHUB=	yes
GH_ACCOUNT=	Keruspe
GH_PROJECT=	Bomb-her-man
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8f5aa22

USE_SDL=	sdl image mixer ttf
USE_GNOME=	intltool librsvg2
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env
USE_GMAKE=	yes
ALL_TARGET=	# empty

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Bomb-her-man" "Bomberman clone" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	NLS

# Wrong versioning upstream
PORTSCOUT=	 ignore:1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|itlocaledir = $$(prefix)/$$(DATADIRNAME)/locale|itlocaledir = $$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
