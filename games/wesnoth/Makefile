# $FreeBSD$

PORTNAME=	wesnoth
PORTVERSION=	1.12.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION:R} \
		http://files.wesnoth.org/ \
		http://ports.toco-domains.de

DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@toco-domains.de
COMMENT=	Fantasy turn-based strategy game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libpng.so:${PORTSDIR}/graphics/png

LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

USE_SDL=	image mixer net ttf
USE_GNOME=	pango
USES=		cmake pkgconfig tar:bzip2
CMAKE_ARGS=	-DMANDIR="man"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ANA CAMPAIGN FRIBIDI LOWMEM NOTIFY OPENMP POOLALLOC PYTHON \
		RAWSOCKETS SERVER TESTS TOOLS DOCS

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

.include <bsd.port.options.mk>

# disable strict compilation, because it will break the build
CMAKE_ARGS+=	-DENABLE_STRICT_COMPILATION=off

.if ${PORT_OPTIONS:MANA}
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=on
PLIST_SUB+=	ANA=""
.else
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=off
PLIST_SUB+=	ANA="@comment "
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
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
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
LIB_DEPENDS+=	libdbus-1.so:${PORTSDIR}/devel/dbus
.else
CMAKE_ARGS+=	-DENABLE_NOTIFICATIONS=off
.endif

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DENABLE_NLS=on -DLOCALEDIR=${PREFIX}/share/locale
USES+=		gettext
MANLANG=	"" cs de en_GB es et fi fr gl hu id it lt pl ru sk \
		sr sr@ijekavian sr@ijekavianlatin sr@latin tr uk vi zh_CN zh_TW
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
BROKEN=	compilation fails with OpenMP
CMAKE_ARGS+=	-DENABLE_OMP=on
.else
CMAKE_ARGS+=	-DENABLE_OMP=off
.endif

.if ${PORT_OPTIONS:MPOOLALLOC}
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=on
.else
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=off
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
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
PLIST_SUB+=	SERVER=""
.else
CMAKE_ARGS+=	-DENABLE_SERVER=off
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MTESTS}
CMAKE_ARGS+=	-DENABLE_TESTS=on
PLIST_SUB+=	TESTS=""
BROKEN=	compilations fails with enabled TEST option
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

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/man -type d -empty -delete

.include <bsd.port.mk>
