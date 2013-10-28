# $FreeBSD$

PORTNAME=	wesnoth
PORTVERSION=	1.10.7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Fantasy turn-based strategy game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/X11/fonts/junicode/Junicode.ttf:${PORTSDIR}/x11-fonts/junicode
LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		png15:${PORTSDIR}/graphics/png

USE_SDL=	image mixer net ttf
USE_GNOME=	pango desktopfileutils
USE_BZIP2=	yes
USES=		cmake pkgconfig
CMAKE_ARGS=	-DMANDIR="man"

MAN6=		wesnoth.6

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ANA CAMPAIGN FRIBIDI LOWMEM NOTIFY OPENMP POOLALLOC PYTHON \
		RAWSOCKETS SERVER TESTS TOOLS

OPTIONS_DEFAULT=	CAMPAIGN FRIBIDI NOTIFY SERVER TOOLS

ANA_DESC=	Asynchronous Network API (WIP)
CAMPAIGN_DESC=	Campaign server
FRIBIDI_DESC=	Bidirectional support
LOWMEM_DESC=	Reduce memory usage (disables animations)
NOTIFY_DESC=	Desktop notifications
OPENMP_DESC=	OpenMP support
POOLALLOC_DESC=	Use wesnoth own memory allocator
PYTHON_DESC=	Python developer tools
RAWSOCKETS_DESC=	Use raw receiving sockets in multiplayer
SERVER_DESC=	Server
TESTS_DESC=	Unit tests
TOOLS_DESC=	Extra tools for artists and translators

NO_STAGE=	yes
.include <bsd.port.options.mk>

# XXX: breaks compilation because of -Werror
.if empty(PORT_OPTIONS:MSTRICT)
CMAKE_ARGS+=	-DENABLE_STRICT_COMPILATION=off
.endif

.if ${PORT_OPTIONS:MANA}
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=on
.else
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=off
.endif

.if ${PORT_OPTIONS:MCAMPAIGN}
CMAKE_ARGS+=	-DENABLE_CAMPAIGN_SERVER=on
PLIST_SUB+=	CAMPAIGN=""
.else
CMAKE_ARGS+=	-DENABLE_CAMPAIGN_SERVER=off
PLIST_SUB+=	CAMPAIGN="@comment "
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
CMAKE_ARGS+=	-DENABLE_FRIBIDI=on
LIB_DEPENDS+=	fribidi:${PORTSDIR}/converters/fribidi
.else
CMAKE_ARGS+=	-DENABLE_FRIBIDI=off
.endif

.if ${PORT_OPTIONS:MLOWMEM}
CMAKE_ARGS+=	-DENABLE_LOW_MEM=on
.else
CMAKE_ARGS+=	-DENABLE_LOW_MEM=off
.endif

.if ${PORT_OPTIONS:MNOTIFY}
CMAKE_ARGS+=	-DENABLE_NOTIFICATIONS=on
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
.else
CMAKE_ARGS+=	-DENABLE_NOTIFICATIONS=off
.endif

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DENABLE_NLS=on -DLOCALEDIR=${PREFIX}/share/locale
USES+=		gettext
MANLANG=	"" cs de en_GB es et fi fr gl hu id it lt pl ru sk \
		sr sr@ijekavian sr@ijekavianlatin sr@latin vi zh_CN zh_TW
.if ${PORT_OPTIONS:MSERVER}
_MANPAGES+=	${PREFIX}/man/ja/man6/wesnothd.6 \
		${PREFIX}/man/pt_BR/man6/wesnothd.6 \
		${PREFIX}/man/tr/man6/wesnothd.6
.endif
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=off
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DENABLE_OMP=on
.else
CMAKE_ARGS+=	-DENABLE_OMP=off
.endif

.if ${PORT_OPTIONS:MPOOLALLOC}
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=on
BROKEN=		does not build with pool alloc
.else
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=off
.endif

.if ${PORT_OPTIONS:MPYTHON}
BROKEN=		cmake build doesn't support installing python tools
USE_PYTHON=	yes
CONFIGURE_ENV+=	PYTHON_PREFIX=${PREFIX} \
		PYTHON_VERSION=${PYTHON_VERSION:S/python//}
CONFIGURE_ARGS+=--enable-python-install
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRAWSOCKETS}
CFLAGS+=	-DNETWORK_USE_RAW_SOCKETS
.endif

.if ${PORT_OPTIONS:MSERVER}
CMAKE_ARGS+=	-DENABLE_SERVER=on
MAN6+=		wesnothd.6
PLIST_SUB+=	SERVER=""
.else
CMAKE_ARGS+=	-DENABLE_SERVER=off
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MTESTS}
CMAKE_ARGS+=	-DENABLE_TESTS=on
PLIST_SUB+=	TESTS=""
.else
CMAKE_ARGS+=	-DENABLE_TESTS=off
PLIST_SUB+=	TESTS="@comment "
.endif

.if ${PORT_OPTIONS:MTOOLS}
CMAKE_ARGS+=	-DENABLE_TOOLS=on
PLIST_SUB+=	TOOLS=""
.else
CMAKE_ARGS+=	-DENABLE_TOOLS=off
PLIST_SUB+=	TOOLS="@comment "
.endif

.if empty(PORT_OPTIONS:MDOCS)
CMAKE_ARGS+=	-DDOCDIR=none
.endif

pre-build:
	${CP} ${LOCALBASE}/lib/X11/fonts/junicode/Junicode.ttf \
		${WRKSRC}/fonts/Junicode-Regular.ttf

post-install:
	-@update-desktop-database ${PREFIX}/share/applications

.include <bsd.port.mk>
