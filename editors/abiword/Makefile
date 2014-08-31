# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/abiword/Makefile,v 1.13 2009/11/10 13:56:18 kwm Exp $

PORTNAME=	abiword
PORTVERSION=	2.8.6
PORTREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source, cross-platform WYSIWYG word processor

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libpng15.so:${PORTSDIR}/graphics/png \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libwv.so:${PORTSDIR}/textproc/wv \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libpsiconv.so:${PORTSDIR}/converters/psiconv \
		libgoffice-0.8.so:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gettext gmake iconv libtool pathfix pkgconfig
USE_GNOME=	libxml2 gtk20 librsvg2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-gnomevfs --enable-plugins="${ABIWORD_PLUGINS}" \
		enable_dynamic="yes" enable_static="no" \
		--disable-collab-backend-telepathy \
		--enable-collab-backend-sugar
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

ABIVERSION=	2.8
PLIST_SUB+=	ABIVERSION=${ABIVERSION}

OPTIONS_DEFINE=	DEBUG SPELLCHECK CLIPART TEMPLATES MATHVIEW \
		OTS WP AIKSAURUS GRAMMAR PSION
OPTIONS_DEFAULT=SPELLCHECK CLIPART TEMPLATES COLLAB

OPTIONS_GROUP=	COLLAB
OPTIONS_GROUP_COLLAB=	COLXMPP

SPELLCHECK_DESC=	Spell checking support
CLIPART_DESC=		Include clipart
TEMPLATES_DESC=		Include additional templates
COLLAB_DESC=		Collaboration backend
COLXMPP_DESC=		Collaboration jammer/XMPP backend
MATHVIEW_DESC=		MathML render plugin
OTS_DESC=		Text Summarizer plugin
WP_DESC=		WordPerfect img/doc import/export plugin
AIKSAURUS_DESC=		Thesaurus plugin
GRAMMAR_DESC=		Grammar checking plugin
PSION_DESC=		Psion 5(MX) files convertion plugin

# check configure for ALL_PLUGINS for complete list
ABIWORD_PLUGINS=	garble loadbindings opml xslfo bmp iscii sdw babelfish \
			paint command latex pdf wikipedia hrtext openxml \
			goffice wmf kword mif wml s5 freetranslation gdict mht \
			applix t602 docbook google eml hancom presentation \
			clarisworks pdb urldict openwriter mswrite gimp \
			passepartout collab eml

# opendocument enabled by default, rsvg plugin isn't needed on unix.
# Plugins we don't support:
# gda

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATHVIEW}
LIB_DEPENDS+=	libmathview.so:${PORTSDIR}/x11-toolkits/gtkmathview
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} mathview
PLIST_SUB+=	MATHVIEW=""
.else
PLIST_SUB+=	MATHVIEW="@comment "
.endif

.if ${PORT_OPTIONS:MOTS}
LIB_DEPENDS+=	libots-1.so:${PORTSDIR}/textproc/ots
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} ots
PLIST_SUB+=	OTS=""
.else
PLIST_SUB+=	OTS="@comment "
.endif

.if ${PORT_OPTIONS:MWP}
USE_GNOME+=	libgsf
LIB_DEPENDS+=	libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} wpg wordperfect
PLIST_SUB+=	WP=""
.else
PLIST_SUB+=	WP="@comment "
.endif

.if ${PORT_OPTIONS:MAIKSAURUS}
LIB_DEPENDS+=	libAiksaurusGTK-1.2.so:${PORTSDIR}/textproc/aiksaurus-gtk
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} aiksaurus
PLIST_SUB+=	AIKSAURUS=""
.else
PLIST_SUB+=	AIKSAURUS="@comment "
.endif

.if ${PORT_OPTIONS:MGRAMMAR}
LIB_DEPENDS+=	liblink-grammar.so:${PORTSDIR}/textproc/link-grammar
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} grammar
PLIST_SUB+=	GRAMMAR=""
.else
PLIST_SUB+=	GRAMMAR="@comment "
.endif

.if ${PORT_OPTIONS:MPSION}
LIB_DEPENDS+=	libpsiconv.so:${PORTSDIR}/converters/psiconv
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} psion
PLIST_SUB+=	PSION=""
.else
PLIST_SUB+=	PSION="@comment "
.endif

#.if ! ${PORT_OPTIONS:MCOLLAB} && ${PORT_OPTIONS:MCOLXMPP}
#BROKEN=		Please enable the COLLAB option, the COLXMPP option need it.
#.endif

.if ${PORT_OPTIONS:MCOLXMPP}
CONFIGURE_ARGS+=--enable-collab-backend-xmpp
LIB_DEPENDS+=	libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth
.else
CONFIGURE_ARGS+=--disable-collab-backend-xmpp
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-symbols
.endif

.if ${PORT_OPTIONS:MCOLLAB}
CONFIGURE_ARGS+=--with-boost --enable-collab-backend-tcp \
		--enable-collab-backend-service
BUILD_DEPENDS+=	${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnutls.so:${PORTSDIR}/security/gnutls
RUN_DEPENDS+=	${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
PLIST_SUB+=		COLLAB=""
.else
CONFIGURE_ARGS+=--without-boost --disable-collab-backend-tcp \
		--disable-collab-backend-service
PLIST_SUB+=		COLLAB="@comment "
.endif

.if ${PORT_OPTIONS:MSPELLCHECK}
LIB_DEPENDS+=		libenchant.so:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-spell
PLIST_SUB+=		DICT=""
.else
CONFIGURE_ARGS+=	--disable-spell
PLIST_SUB+=		DICT="@comment "
.endif

.if ${PORT_OPTIONS:MTEMPLATES}
CONFIGURE_ARGS+=	--enable-templates
PLIST_SUB+=		TEMPLATES=""
.else
CONFIGURE_ARGS+=	--disable-templates
PLIST_SUB+=		TEMPLATES="@comment "
.endif

.if ${PORT_OPTIONS:MCLIPART}
CONFIGURE_ARGS+=	--enable-clipart
PLIST_SUB+=		CLIPART=""
.else
CONFIGURE_ARGS+=	--disable-clipart
PLIST_SUB+=		CLIPART="@comment "
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
