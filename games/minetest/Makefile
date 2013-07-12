# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest
PORTVERSION=	0.4.4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An Infiniminer/Minecraft inspired game

LIB_DEPENDS=	Irrlicht:${PORTSDIR}/x11-toolkits/irrlicht \
		sqlite3:${PORTSDIR}/databases/sqlite3

LICENSE=	LGPL21

USE_GITHUB=	yes
GH_ACCOUNT=	celeron55
GH_TAGNAME=	0.4.4
GH_COMMIT=	ab06fca

USES=		cmake
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${EXAMPLESDIR}"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

MAN6=		minetest.6 minetestserver.6

OPTIONS_DEFINE=	CLIENT SERVER SOUND NLS DOCS EXAMPLES
OPTIONS_DEFAULT=CLIENT SERVER SOUND NLS DOCS EXAMPLES
CLIENT_DESC=	Build client
SERVER_DESC=	Build server
SOUND_DESC=	Enable sound

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DENABLE_GETTEXT:BOOL=YES
USES+=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_GETTEXT:BOOL=NO
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		gl
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DBUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
.else
CMAKE_ARGS+=	-DBUILD_CLIENT=0
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
CMAKE_ARGS+=	-DBUILD_SERVER=1
PLIST_SUB+=	SERVER=""
.else
CMAKE_ARGS+=	-DBUILD_SERVER=0
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MSOUND}
USE_OPENAL=	yes
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindIrrlicht.cmake
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/src/CMakeLists.txt
#	@${REINPLACE_CMD} -e 's|share/man|man|; /EXAMPLE_CONF_DIR/ s|..DOCDIR.|"${EXAMPLESDIR}"|' \
#		${WRKSRC}/CMakeLists.txt
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/install.*DESTINATION.*DOCDIR/I d' ${WRKSRC}/CMakeLists.txt
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '/install.*DESTINATION.*EXAMPLE_CONF_DIR/I d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
