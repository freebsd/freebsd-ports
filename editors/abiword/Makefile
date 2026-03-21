PORTNAME=	abiword
DISTVERSIONPREFIX=	release-
DISTVERSION=	3.0.8
CATEGORIES=	editors
DIST_SUBDIR=	AbiWord

PATCH_SITES=	https://gitlab.gnome.org/World/AbiWord/-/commit/
PATCHFILES=	ae05e92d.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full-featured, efficient word processing application
WWW=		https://gitlab.gnome.org/World/AbiWord

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libpng16.so:graphics/png \
		libgoffice-0.10.so:devel/goffice \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libexpat.so:textproc/expat2 \
		libwv-1.2.so.4:textproc/wv \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf:x11-fonts/dejavu

USES=		autoreconf bison compiler:c++11-lang cpe desktop-file-utils \
		gettext-tools gmake gnome iconv jpeg libtool localbase:ldflags \
		pathfix perl5 pkgconfig python:build readline shebangfix xorg
CPE_VENDOR=	abisource
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	AbiWord
USE_GNOME=	glib20 gtk30 introspection:build libgsf libxml2 librsvg2 \
		libxslt
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11
SHEBANG_FILES=	tools/cdump/xp/*.pl \
		tools/rtfgen/*.pl \
		po/*.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnomevfs --enable-plugins="${ABIWORD_PLUGINS}" \
		--enable-shared=yes --enable-static=no \
		--enable-introspection=yes

INSTALL_TARGET=	install-strip

PLIST_SUB+=	ABIVERSION=3.0

OPTIONS_DEFINE=	CLIPART DEBUG TEMPLATES WMF WP
OPTIONS_DEFAULT=CLIPART SPELLCHECK TEMPLATES WMF
OPTIONS_GROUP=	DICT
OPTIONS_GROUP_DICT=	GRAMMAR SPELLCHECK
OPTIONS_SUB=	yes

CLIPART_DESC=		Include clipart
DICT_DESC=		Spelling and grammar checking
GRAMMAR_DESC=		Grammar checking plugin
SPELLCHECK_DESC=	Spell checking support
TEMPLATES_DESC=		Include additional templates
WMF_DESC=		Windows Metafile plugin
WP_DESC=		WordPerfect img/doc import/export plugin

# check configure for ALL_PLUGINS for complete list
ABIWORD_PLUGINS=	applix bmp clarisworks command docbook eml epub \
			garble gimp goffice hancom hrtext iscii latex \
			loadbindings mif mswrite openwriter opml paint \
			passepartout pdb pdf presentation s5 sdw t602 \
			wml wikipedia xslfo

CLIPART_CONFIGURE_ENABLE=	clipart

DEBUG_CONFIGURE_ENABLE=		debug

GRAMMAR_IMPLIES=		SPELLCHECK
GRAMMAR_LIB_DEPENDS=		liblink-grammar.so:textproc/link-grammar
GRAMMAR_VARS=			ABIWORD_PLUGINS+=grammar

SPELLCHECK_LIB_DEPENDS=		libenchant-2.so:textproc/enchant2
SPELLCHECK_CONFIGURE_ENABLE=	spell

TEMPLATES_CONFIGURE_ENABLE=	templates

WMF_LIB_DEPENDS=	libwmf-0.2.so.7:graphics/libwmf
WMF_VARS=		ABIWORD_PLUGINS+=wmf

WP_LIB_DEPENDS=	libwpg-0.3.so:graphics/libwpg03 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwps-0.4.so:textproc/libwps
WP_VARS=	ABIWORD_PLUGINS+="wpg wordperfect"

post-patch:
	${REINPLACE_CMD} -i "" -e 's|com\.abisource\.AbiWord|${PORTNAME}|' \
		${WRKSRC}/abiword.appdata.xml

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${SH} ./autogen-common.sh

.include <bsd.port.mk>
