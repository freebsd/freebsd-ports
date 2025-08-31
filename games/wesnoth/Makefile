PORTNAME=	wesnoth
PORTVERSION=	1.18.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/ \
		http://ports.toco-domains.de/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Fantasy turn-based strategy game
WWW=		https://www.wesnoth.org/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libvorbisfile.so:audio/libvorbis \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libicudata.so:devel/icu \
		libharfbuzz.so:print/harfbuzz

USES=		cmake compiler:c++17-lang cpe desktop-file-utils \
		gnome lua:54 pkgconfig python:run \
		readline shebangfix ssl sdl tar:bzip2 xorg
USE_SDL=	image2 mixer2 ttf2
USE_GNOME=	cairo pango
USE_XORG=	ice sm x11 xext

LDFLAGS+=	-lboost_system -lpthread

PORTSCOUT=	limitw:1,even

SHEBANG_FILES=	data/tools/about_cfg_to_wiki \
		data/tools/addon_manager/__init__.py \
		data/tools/addon_manager/html.py \
		data/tools/check_mixed_indent \
		data/tools/expand-terrain-macros.py \
		data/tools/extractbindings data/tools/imgcheck \
		data/tools/GUI.pyw \
		data/tools/hexometer.py \
		data/tools/steam-changelog \
		data/tools/TeamColorizer \
		data/tools/trackviewer.pyw \
		data/tools/terrain2wiki.py \
		data/tools/tmx_trackplacer \
		data/tools/unit_tree/__init__.py \
		data/tools/unit_tree/animations.py \
		data/tools/unit_tree/helpers.py \
		data/tools/unit_tree/html_output.py \
		data/tools/unit_tree/overview.py \
		data/tools/unit_tree/team_colorizer.py \
		data/tools/unit_tree/update-wmlunits \
		data/tools/unit_tree/wiki_output.py \
		data/tools/wesnoth/campaignserver_client.py \
		data/tools/wesnoth/libgithub.py \
		data/tools/wesnoth/trackplacer3/cfgfileformat.py \
		data/tools/wesnoth/trackplacer3/datatypes.py \
		data/tools/wesnoth/trackplacer3/tmxfileformat.py \
		data/tools/wesnoth/version.py \
		data/tools/wesnoth/wescamp.py \
		data/tools/wesnoth/wmldata.py \
		data/tools/wesnoth/wmliterator3.py \
		data/tools/wesnoth/wmlparser.py \
		data/tools/wesnoth/wmlparser3.py \
		data/tools/wesnoth/wmltools3.py \
		data/tools/wesnoth_addon_manager \
		data/tools/wmlflip \
		data/tools/wmlindent \
		data/tools/wmllint \
		data/tools/wmllint-1.4 \
		data/tools/wmlunits \
		data/tools/wmlscope \
		data/tools/wmlxgettext \
		po/FINDCPP \
		po/FINDPY \
		run_boost_tests \
		run_wml_tests \
		update_copyrights \
		utils/ai_test/ai_test.py \
		utils/compare_images.py \
		utils/dockerbuilds/mingw/get_dlls.py \
		utils/git_export_campaign \
		utils/optiwebp.py \
		utils/po_stat.py \
		utils/pofix.py \
		utils/unused_functions.py \
		utils/update_appdata \
		utils/update_copyright.py \
		utils/woptipng.py

CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	battle_for_wesnoth
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man \
		-DENABLE_STRICT_COMPILATION=off

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

#post-install:
#	${FIND} ${STAGEDIR}${PREFIX}/man -type d -empty -delete

.include <bsd.port.mk>
