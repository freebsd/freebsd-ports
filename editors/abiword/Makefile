# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/abiword/Makefile,v 1.13 2009/11/10 13:56:18 kwm Exp $

PORTNAME=	abiword
PORTVERSION=	3.0.1
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/abiword/${PORTVERSION}/source/
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source, cross-platform WYSIWYG word processor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libpopt.so:${PORTSDIR}/devel/popt \
		libpng.so:${PORTSDIR}/graphics/png \
		libwv.so:${PORTSDIR}/textproc/wv \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libgoffice-0.10.so:${PORTSDIR}/devel/goffice010
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu

USES=		desktop-file-utils gmake iconv libtool pathfix pkgconfig
USE_GNOME=	libxml2 gtk30 librsvg2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-gnomevfs --enable-plugins="${ABIWORD_PLUGINS}" \
		--enable-shared="yes" --enable-static="no"
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB+=	ABIVERSION=3.0

OPTIONS_DEFINE=	AIKSAURUS CLIPART DEBUG MATHVIEW NLS OTS PSION \
		TEMPLATES MATHVIEW WP
OPTIONS_DEFAULT=CLIPART COLSERVICE COLSUGAR COLTCP SPELLCHECK TEMPLATES
OPTIONS_SUB=	yes

OPTIONS_GROUP=	DICT COLLAB
OPTIONS_GROUP_DICT=	GRAMMAR SPELLCHECK
OPTIONS_GROUP_COLLAB=	COLFAKE COLSERVICE COLSIP COLSUGAR COLTCP COLTELEPATHY COLXMPP

AIKSAURUS_DESC=		Thesaurus plugin
CLIPART_DESC=		Include clipart
COLLAB_DESC=		Collaboration backend
COLFAKE_DESC=		Fake collaboration for debugging purposes only
COLSERVICE_DESC=	Collaborate with AbiCollab.net webservice
COLSIP_DESC=		Collaborate with the SIP/SIMPLE backend
COLSUGAR_DESC=		Collaborate with the Sugar/OLPC environment
COLTCP_DESC=		Collaborate with direct TCP peer to peer connections
COLTELEPATHY_DESC=	Collaborate with the Telepathy backend (experimental)
COLXMPP_DESC=		Collaborate with the Jabber/XMPP backend
DICT_DESC=		Spelling and grammar checking
GRAMMAR_DESC=		Grammar checking plugin (requires SPELLCHECK option)
MATHVIEW_DESC=		MathML render plugin
OTS_DESC=		Text Summarizer plugin
PSION_DESC=		Psion 5(MX) files convertion plugin
SPELLCHECK_DESC=	Spell checking support
TEMPLATES_DESC=		Include additional templates
WP_DESC=		WordPerfect img/doc import/export plugin

# check configure for ALL_PLUGINS for complete list
ABIWORD_PLUGINS=	garble loadbindings opml xslfo bmp iscii sdw babelfish \
			paint command latex pdf wikipedia hrtext openxml \
			goffice wmf kword mif wml s5 freetranslation gdict mht \
			applix t602 docbook google eml hancom presentation \
			clarisworks pdb urldict openwriter mswrite gimp \
			passepartout eml

# opendocument enabled by default, rsvg plugin isn't needed on unix.
# Plugins we don't support:
# gda

AIKSAURUS_LIB_DEPENDS=		libAiksaurusGTK-1.2.so:${PORTSDIR}/textproc/aiksaurus-gtk

CLIPART_CONFIGURE_ENABLE=	clipart

COLFAKE_CONFIGURE_ENABLE=	collab-backend-fake

COLSERVICE_CONFIGURE_ENABLE=	collab-backend-service
COLSERVICE_BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
COLSERVICE_LIB_DEPENDS=		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
				libgnutls.so:${PORTSDIR}/security/gnutls
COLSERVICE_RUN_DEPENDS=		${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio

COLSIP_CONFIGURE_ENABLE=	collab-backend-sip

COLSUGAR_CONFIGURE_ENABLE=	collab-backend-sugar
COLSUGAR_LIB_DEPENDS=		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

COLTCP_CONFIGURE_ENABLE=	collab-backend-tcp
COLTCP_BUILD_DEPENDS=		${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
COLTCP_RUN_DEPENDS=		${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio

COLTELEPATHY_CONFIGURE_ENABLE=	collab-backend-telepathy
COLTELEPATHY_LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

COLXMPP_CONFIGURE_ENABLE=	collab-backend-xmpp
COLXMPP_LIB_DEPENDS=		libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth

DEBUG_CONFIGURE_ENABLE=		debug symbols

GRAMMAR_LIB_DEPENDS=		liblink-grammar.so:${PORTSDIR}/textproc/link-grammar

MATHVIEW_LIB_DEPENDS=		libmathview.so:${PORTSDIR}/x11-toolkits/gtkmathview

NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

OTS_LIB_DEPENDS=		libots-1.so:${PORTSDIR}/textproc/ots

PSION_LIB_DEPENDS=		libpsiconv.so:${PORTSDIR}/converters/psiconv

SPELLCHECK_LIB_DEPENDS=		libenchant.so:${PORTSDIR}/textproc/enchant
SPELLCHECK_CONFIGURE_ENABLE=	spell

TEMPLATES_CONFIGURE_ENABLE=	templates

WP_USE=		gnome=libgsf
WP_LIB_DEPENDS=	libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAIKSAURUS}
ABIWORD_PLUGINS+=	aiksaurus
.endif

.if ${PORT_OPTIONS:MCOL*}
PLIST_SUB+=		COLLAB=""
ABIWORD_PLUGINS+=	collab
.else
PLIST_SUB+=		COLLAB="@comment "
.endif

.if ${PORT_OPTIONS:MGRAMMAR}
ABIWORD_PLUGINS+=	grammar
.endif

.if ${PORT_OPTIONS:MMATHVIEW}
ABIWORD_PLUGINS+=	mathview
.endif

.if ${PORT_OPTIONS:MOTS}
ABIWORD_PLUGINS+=	ots
.endif

.if ${PORT_OPTIONS:MPSION}
ABIWORD_PLUGINS+=	psion
.endif

.if ${PORT_OPTIONS:MWP}
ABIWORD_PLUGINS+=	wpg wordperfect
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/goffice-bits/goffice/app/goffice-app.h \
		${WRKSRC}/src/af/util/xp/ut_go_file.h
# The following substitutions ensure that plugins are linked with libabiword
# from the work or stage directory instead of a previously installed library.
# In pseudo code:
# s,PLUGIN_LIBS="$PLUGIN_LIBS -Lsrc -labiword",
#   PLUGIN_LIBS="src/libabiword.la $PLUGIN_LIBS",
# s,foo_LIBS="$foo_LIBS $PLUGIN_LIBS",
#   foo_LIBS="$PLUGIN_LIBS $foo_LIBS",
# The initial value of PLUGIN_LIBS may contain -L/usr/local/lib so it would
# have to come after -Lsrc, but -Lsrc is not correct when libtool relinks
# plugins during staging so use src/libabiword.la and let libtool figure out
# what flags are needed.  Secondly, switch around foo_LIBS and PLUGIN_LIBS
# because foo_LIBS may contain -L/usr/local/lib.
	@${REINPLACE_CMD} \
		-e "s,\$$PLUGIN_LIBS \"'-L\$${top_builddir}/src'\" -labiword-\$$ABIWORD_SERIES,\\\\\$${top_builddir}/src/libabiword-\$$ABIWORD_SERIES.la \$$PLUGIN_LIBS," \
		-e "/_LIBS=/s,\"\\(.*\\)\"\\('\$${PLUGIN_LIBS}.*'\\),\\2\" \\1\"," \
		-e 's|" == "|" = "|g' ${WRKSRC}/configure

.include <bsd.port.mk>
