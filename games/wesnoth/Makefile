# New ports collection makefile for:	wesnoth
# Date created:			22 December 2003
# Whom:				Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.8.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	wesnoth-devel-[0-9]*

USE_SDL=	image mixer net ttf
USE_GNOME=	desktopfileutils gnometarget pango
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
USE_BZIP2=	yes
USE_LUA=	5.1
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262
ACLOCAL_ARGS=	-Im4
AUTOMAKE_ARGS=	--add-missing --copy
CONFIGURE_ENV=	PKG_CONFIG=${LOCALBASE}/bin/pkg-config \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-boost=${LOCALBASE} \
		--with-icondir=${PREFIX}/share/pixmaps \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-localedir=${PREFIX}/share/locale

MANLANG=	"" cs de en_GB es et fi fr gl hu it ja lt pl pt_BR sk \
		sr sr@ijekavian sr@ijekavianlatin sr@latin tr zh_CN zh_TW

MAN6=		wesnoth.6

PORTDOCS=	*
PORTDATA=	*

OPTIONS=	BWMON	 "Enable bandwidth monitoring for server" Off \
		CAMPAIGN "Enable campaign server"	On \
		EDITOR	 "Enable map editor"		On \
		FRIBIDI	 "Enable bidirectional support"	On \
		LOWMEM	 "Reduce memory usage (disables animations)" Off \
		NLS	 "Enable localization"		On \
		NOTIFY	 "Enable desktop notifications"	On \
		POOLALLOC "Use wesnoth own memory allocator" Off \
		PYTHON	 "Enable python developer tools" On \
		RAWSOCKETS "Use raw receiving sockets in multiplayer" Off \
		SERVER	 "Enable server"		On \
		TESTS	 "Enable unit tests"		Off \
		TINYGUI	 "Enable tiny gui (down to 320x200)" Off \
		TOOLS	 "Enable extra tools for artists and translators" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif

# XXX: breaks compilation because of -Werror
.if !defined(WITH_STRICT)
CONFIGURE_ARGS+=	--disable-strict-compilation
.endif

.if defined(WITHOUT_BWMON)
CONFIGURE_ARGS+=	--disable-bandwidth-monitor
.else
CONFIGURE_ARGS+=	--enable-bandwidth-monitor
.endif

.if defined(WITHOUT_CAMPAIGN)
CONFIGURE_ARGS+=	--disable-campaign-server
PLIST_SUB+=		CAMPAIGN="@comment "
.else
CONFIGURE_ARGS+=	--enable-campaign-server
PLIST_SUB+=		CAMPAIGN=""
.endif

.if defined(WITHOUT_EDITOR)
CONFIGURE_ARGS+=	--disable-editor
PLIST_SUB+=		EDITOR="@comment "
.else
CONFIGURE_ARGS+=	--enable-editor
PLIST_SUB+=		EDITOR=""
.endif

.if defined(WITHOUT_FRIBIDI)
CONFIGURE_ARGS+=	--without-fribidi
.else
CONFIGURE_ARGS+=	--with-fribidi
LIB_DEPENDS+=		fribidi.3:${PORTSDIR}/converters/fribidi
.endif

.if defined(WITHOUT_LOWMEM)
CONFIGURE_ARGS+=	--disable-lowmem
.else
CONFIGURE_ARGS+=	--enable-lowmem
.endif

.if defined(WITHOUT_NOTIFY)
CONFIGURE_ARGS+=	--disable-notifications
.else
CONFIGURE_ARGS+=	--enable-notifications --enable-dbus
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
.endif

.if defined(WITHOUT_POOLALLOC)
CONFIGURE_ARGS+=	--disable-pool-alloc
.else
CONFIGURE_ARGS+=	--enable-pool-alloc
.endif

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--disable-python-install
PLIST_SUB+=		PYTHON="@comment "
.else
USE_PYTHON=		yes
CONFIGURE_ENV+=		PYTHON_PREFIX=${PREFIX} \
			PYTHON_VERSION=${PYTHON_VERSION:S/python//}
CONFIGURE_ARGS+=	--enable-python-install
PLIST_SUB+=		PYTHON=""
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if defined(WITHOUT_RAWSOCKETS)
CONFIGURE_ARGS+=	--disable-raw-sockets
.else
CONFIGURE_ARGS+=	--enable-raw-sockets
.endif

.if defined(WITHOUT_SERVER)
CONFIGURE_ARGS+=	--disable-server
PLIST_SUB+=		SERVER="@comment "
.else
CONFIGURE_ARGS+=	--enable-server
MAN6+=			wesnothd.6
PLIST_SUB+=		SERVER=""
.endif

.if defined(WITHOUT_TESTS)
CONFIGURE_ARGS+=	--disable-tests
PLIST_SUB+=		TESTS="@comment "
.else
CONFIGURE_ARGS+=	--enable-tests
PLIST_SUB+=		TESTS=""
.endif

.if defined(WITHOUT_TINYGUI)
CONFIGURE_ARGS+=	--disable-tinygui
.else
BUILD_DEPENDS+=		convert:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--enable-tinygui
.endif

.if defined(WITHOUT_TOOLS)
CONFIGURE_ARGS+=	--disable-tools
PLIST_SUB+=		TOOLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS=""
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${WRKDIR}/docs
.endif

.if (defined(WITH_CAMPAIGN) || defined(WITH_SERVER) || defined(WITH_TOOLS)) && defined(WITHOUT_NLS)
BROKEN=		you need NLS support for `campaignd' or `wesnothd' or tools to link against gettext
.endif

.if defined(NOPORTDATA)
IGNORE=		game data is required, undefine NOPORTDATA
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|png_voidp_NULL|NULL|g' \
		-e 's|png_error_ptr_NULL|NULL|g' \
		${WRKSRC}/src/tools/exploder_utils.cpp

post-install:	.SILENT
	-update-desktop-database

.include <bsd.port.post.mk>
