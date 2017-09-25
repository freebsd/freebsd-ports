# $FreeBSD$

PORTNAME=	wesnoth
PORTVERSION=	1.12.6
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/ \
		http://ports.toco-domains.de/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Fantasy turn-based strategy game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

BROKEN_powerpc64=	fails to link: schema_validator.cpp: undefined reference to boost::match_results

LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

PORTSCOUT=	limitw:1,even

USE_SDL=	image mixer net ttf
USE_LDCONFIG=	yes
USE_GNOME=	pango
USES=		cmake cpe pkgconfig python:run shebangfix tar:bzip2
SHEBANG_FILES=	data/tools/about_cfg_to_wiki \
		data/tools/campaign2wiki.py \
		data/tools/castle-cutter/mk-castle.sh \
		data/tools/expand-terrain-macros.py \
		data/tools/extractbindings data/tools/imgcheck \
		data/tools/journeylifter data/tools/rmtrans/rmtrans.py \
		data/tools/scoutDefault.py data/tools/terrain2wiki.py \
		data/tools/trackplacer data/tools/unit_tree/TeamColorizer \
		data/tools/unit_tree/overview.py \
		data/tools/unit_tree/update-wmlunits \
		data/tools/wesnoth/wescamp.py data/tools/wesnoth/wmldata.py \
		data/tools/wesnoth/wmlparser.py \
		data/tools/wesnoth/wmlparser2.py \
		data/tools/wesnoth_addon_manager data/tools/wmlflip \
		data/tools/wmlindent data/tools/wmllint \
		data/tools/wmllint-1.4 data/tools/wmllint_gui \
		data/tools/wmlmove data/tools/wmlscope data/tools/wmlunits \
		data/tools/wmlvalidator
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	battle_for_wesnoth
CMAKE_ARGS=	-DMANDIR="man" -DENABLE_STRICT_COMPILATION=off

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ANA CAMPAIGN DOCS FRIBIDI LOWMEM NLS \
		NOTIFY OPENMP RAWSOCKETS SERVER TEST TOOLS
OPTIONS_DEFAULT=	CAMPAIGN FRIBIDI NOTIFY OPENMP SERVER TOOLS
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
# -std=gnu++11 is necessary on FreeBSD 10, whose libc++ does not have the
# `operator delete(void*, size_t)' overload from C++14. GCC 6 defaults to
# --std=gnu++14, which then breaks the build (bug 219485).
OPENMP_USE=	CXXSTD=gnu++11
OPENMP_USES=	compiler:gcc-c++11-lib
OPENMP_CMAKE_ON=-DENABLE_OMP=on
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
