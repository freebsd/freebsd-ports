# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/abiword/Makefile,v 1.13 2009/11/10 13:56:18 kwm Exp $

PORTNAME=	abiword
PORTVERSION=	2.8.6
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		png15:${PORTSDIR}/graphics/png \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		wv-1.2:${PORTSDIR}/textproc/wv \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fribidi:${PORTSDIR}/converters/fribidi \
		psiconv:${PORTSDIR}/converters/psiconv \
		goffice-0.8:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USES=		pathfix gettext iconv pkgconfig
USE_GNOME=	libxml2 gtk20 desktopfileutils librsvg2 libxslt
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

MAN1=		abiword.1

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATHVIEW}
LIB_DEPENDS+=	mathview:${PORTSDIR}/x11-toolkits/gtkmathview
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} mathview
PLIST_SUB+=	MATHVIEW=""
.else
PLIST_SUB+=	MATHVIEW="@comment "
.endif

.if ${PORT_OPTIONS:MOTS}
LIB_DEPENDS+=	ots-1:${PORTSDIR}/textproc/ots
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} ots
PLIST_SUB+=	OTS=""
.else
PLIST_SUB+=	OTS="@comment "
.endif

.if ${PORT_OPTIONS:MWP}
USE_GNOME+=	libgsf
LIB_DEPENDS+=	wpg-0.1:${PORTSDIR}/graphics/libwpg01 \
		wpd-0.8:${PORTSDIR}/textproc/libwpd08
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} wpg wordperfect
PLIST_SUB+=	WP=""
.else
PLIST_SUB+=	WP="@comment "
.endif

.if ${PORT_OPTIONS:MAIKSAURUS}
LIB_DEPENDS+=	AiksaurusGTK-1.2:${PORTSDIR}/textproc/aiksaurus-gtk
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} aiksaurus
PLIST_SUB+=	AIKSAURUS=""
.else
PLIST_SUB+=	AIKSAURUS="@comment "
.endif

.if ${PORT_OPTIONS:MGRAMMAR}
LIB_DEPENDS+=	link-grammar:${PORTSDIR}/textproc/link-grammar
ABIWORD_PLUGINS:=	${ABIWORD_PLUGINS} grammar
PLIST_SUB+=	GRAMMAR=""
.else
PLIST_SUB+=	GRAMMAR="@comment "
.endif

.if ${PORT_OPTIONS:MPSION}
LIB_DEPENDS+=	psiconv:${PORTSDIR}/converters/psiconv
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
LIB_DEPENDS+=	loudmouth-1:${PORTSDIR}/net-im/loudmouth
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
LIB_DEPENDS+=	boost_system:${PORTSDIR}/devel/boost-libs \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gnutls:${PORTSDIR}/security/gnutls
RUN_DEPENDS+=	${LOCALBASE}/include/asio.hpp:${PORTSDIR}/net/asio
PLIST_SUB+=		COLLAB=""
.else
CONFIGURE_ARGS+=--without-boost --disable-collab-backend-tcp \
		--disable-collab-backend-service
PLIST_SUB+=		COLLAB="@comment "
.endif

.if ${PORT_OPTIONS:MSPELLCHECK}
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
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
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}-${ABIVERSION}/plugins
	@-update-desktop-database

.include <bsd.port.mk>
