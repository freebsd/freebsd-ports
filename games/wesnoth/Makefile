# $FreeBSD$

PORTNAME=	wesnoth
PORTVERSION=	1.12.5
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/ \
		http://ports.toco-domains.de/

MAINTAINER=	ports@toco-domains.de
COMMENT=	Fantasy turn-based strategy game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

PORTSCOUT=	limitw:1,even

USE_SDL=	image mixer net ttf
USE_LDCONFIG=	yes
USE_GNOME=	pango
USES=		cmake cpe pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	data/tools/campaign2wiki.py \
		data/tools/castle-cutter/mk-castle.sh \
		data/tools/terrain2wiki.py \
		data/tools/unit_tree/update-wmlunits
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	battle_for_wesnoth
CMAKE_ARGS=	-DMANDIR="man" -DENABLE_STRICT_COMPILATION=off

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ANA CAMPAIGN DOCS FRIBIDI LOWMEM NLS \
		NOTIFY OPENMP RAWSOCKETS SERVER TEST TOOLS
OPTIONS_DEFAULT=	CAMPAIGN FRIBIDI NOTIFY SERVER TOOLS
OPTIONS_SUB=	yes

ANA_DESC=	Asynchronous Network API (WIP)
ANA_CMAKE_ON=	-DUSE_ANA_NETWORK=on
CAMPAIGN_DESC=	Campaign server
CAMPAIGN_CMAKE_ON=-DENABLE_CAMPAIGN_SERVER=on
DOCS_CMAKE_OFF=	-DDOCDIR=none
FRIBIDI_DESC=	Bidirectional support
FRIBIDI_LIB_DEPENDS=libfribidi.so:converters/fribidi
FRIBIDI_CMAKE_OFF=-DENABLE_FRIBIDI=off
LOWMEM_DESC=	Reduce memory usage (disables animations)
LOWMEM_CMAKE_ON=-DENABLE_LOW_MEM=on
NLS_USES=	gettext
NLS_CMAKE_ON=	-DLOCALEDIR=${PREFIX}/share/locale
NLS_CMAKE_OFF=	-DENABLE_NLS=off
NOTIFY_DESC=	Desktop notifications
NOTIFY_LIB_DEPENDS=libdbus-1.so:devel/dbus
NOTIFY_CMAKE_OFF=-DENABLE_NOTIFICATIONS=off
OPENMP_DESC=	OpenMP support
OPENMP_USES=	compiler:openmp
OPENMP_CMAKE_ON=-DENABLE_OMP=on
OPENMP_BROKEN=	Does not compile with OPENMP option enabled
RAWSOCKETS_DESC=	Use raw receiving sockets in multiplayer
RAWSOCKETS_CFLAGS=-DNETWORK_USE_RAW_SOCKETS
SERVER_DESC=	Server
SERVER_CMAKE_OFF=-DENABLE_SERVER=off
TEST_CMAKE_ON=	-DENABLE_TESTS=on
TOOLS_DESC=	Extra tools for artists and translators
TOOLS_CMAKE_ON=	-DENABLE_TOOLS=on

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/man -type d -empty -delete

.include <bsd.port.mk>
