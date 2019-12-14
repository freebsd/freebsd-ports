# $FreeBSD$

PORTNAME=	wesnoth
PORTVERSION=	1.14.9
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/ \
		http://ports.toco-domains.de/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fantasy turn-based strategy game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libvorbisfile.so:audio/libvorbis \
		libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

PORTSCOUT=	limitw:1,even

USES=		cmake compiler:c++11-lang cpe gnome pkgconfig \
		python:2.7,run readline:port shebangfix ssl sdl tar:bzip2 xorg
USE_SDL=	image2 mixer2 ttf2
USE_LDCONFIG=	yes
USE_GNOME=	cairo pango
USE_XORG=	ice sm x11 xext
SHEBANG_FILES=	data/tools/about_cfg_to_wiki \
		data/tools/addon_manager/html.py \
		data/tools/campaign2wiki.py \
		data/tools/expand-terrain-macros.py \
		data/tools/extractbindings data/tools/imgcheck \
		data/tools/hexometer.py \
		data/tools/journeylifter data/tools/rmtrans/rmtrans.py \
		data/tools/scoutDefault.py data/tools/terrain2wiki.py \
		data/tools/trackplacer data/tools/unit_tree/TeamColorizer \
		data/tools/unit_tree/helpers.py \
		data/tools/unit_tree/overview.py \
		data/tools/unit_tree/update-wmlunits \
		data/tools/wesnoth/campaignserver_client.py \
		data/tools/wesnoth/wescamp.py data/tools/wesnoth/wmldata.py \
		data/tools/wesnoth/wmlparser.py \
		data/tools/wesnoth/wmlparser2.py \
		data/tools/wesnoth/wmlparser3.py \
		data/tools/wesnoth_addon_manager data/tools/wmlflip \
		data/tools/wmlindent data/tools/wmllint \
		data/tools/steam-changelog \
		data/tools/wmllint-1.4 \
		data/tools/wmlunits \
		data/tools/wmlscope \
		data/tools/wmlvalidator \
		data/tools/wmlxgettext \
		data/tools/GUI.pyw

CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	battle_for_wesnoth
CMAKE_ARGS=	-DMANDIR="man" -DENABLE_STRICT_COMPILATION=off

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	CAMPAIGN DOCS FRIBIDI NLS \
		NOTIFY SERVER TEST
OPTIONS_DEFAULT=	CAMPAIGN FRIBIDI NOTIFY SERVER
OPTIONS_SUB=	yes

CAMPAIGN_DESC=	Campaign server
CAMPAIGN_CMAKE_ON=-DENABLE_CAMPAIGN_SERVER=on
DOCS_CMAKE_OFF=	-DDOCDIR=none
FRIBIDI_DESC=	Bidirectional support
FRIBIDI_LIB_DEPENDS=libfribidi.so:converters/fribidi
FRIBIDI_CMAKE_OFF=-DENABLE_FRIBIDI=off
NLS_USES=	gettext
NLS_CMAKE_ON=	-DLOCALEDIR=${PREFIX}/share/locale
NLS_CMAKE_OFF=	-DENABLE_NLS=off
NOTIFY_DESC=	Desktop notifications
NOTIFY_LIB_DEPENDS=libdbus-1.so:devel/dbus
NOTIFY_CMAKE_OFF=-DENABLE_NOTIFICATIONS=off
SERVER_DESC=	Server
SERVER_CMAKE_OFF=-DENABLE_SERVER=off
TEST_CMAKE_ON=	-DENABLE_TESTS=on

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/man -type d -empty -delete

.include <bsd.port.mk>
