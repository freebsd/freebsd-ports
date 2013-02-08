# Created by:	nemysis@gmx.ch
#
# $FreeBSD$

PORTNAME=	bomb-her-man
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GH \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Bomberman clone written in C++

LICENSE=	GPLv3

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_GITHUB=	yes
GH_ACCOUNT=	Keruspe
GH_PROJECT=	Bomb-her-man
GH_TAGNAME=	master
GH_COMMIT=	8f5aa22

USE_SDL=	sdl image mixer ttf
USE_GNOME=	intltool librsvg2
GNU_CONFIGURE=	yes
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
ALL_TARGET=	# empty
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README

DESKTOP_ENTRIES="Bomb-her-man" "Bomberman clone" \
		"${PREFIX}/share/pixmaps/${PORTNAME}_48.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
