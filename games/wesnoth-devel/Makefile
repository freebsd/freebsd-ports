# New ports collection makefile for:	wesnoth-devel
# Date created:			7 September 2008
# Whom:				Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.9.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://files.wesnoth.org/
PKGNAMESUFFIX=	-devel

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	wesnoth-[0-9]*

USE_SDL=	image mixer net ttf
USE_GNOME=	gnometarget pango
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes

MAN6=		wesnoth.6

PORTDOCS=	*
PORTDATA=	*

OPTIONS=	ANA	 "Enable Asynchronous Network API (WIP)" On \
		CAMPAIGN "Enable campaign server"	On \
		EDITOR	 "Enable map editor"		On \
		FRIBIDI	 "Enable bidirectional support"	On \
		LOWMEM	 "Reduce memory usage (disables animations)" Off \
		NOTIFY	 "Enable desktop notifications"	On \
		POOLALLOC "Use wesnoth own memory allocator" Off \
		PYTHON	 "Enable python developer tools" Off \
		RAWSOCKETS "Use raw receiving sockets in multiplayer" Off \
		SERVER	 "Enable server"		On \
		TESTS	 "Enable unit tests"		Off \
		TINYGUI	 "Enable tiny gui (down to 320x200)" Off \
		TOOLS	 "Enable extra tools for artists and translators" On

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	debug
.endif

# XXX: breaks compilation because of -Werror
.if !defined(WITH_STRICT)
CMAKE_ARGS+=	-DENABLE_STRICT_COMPILATION=off
.endif

.if defined(WITHOUT_ANA)
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=off
.else
CMAKE_ARGS+=	-DUSE_ANA_NETWORK=on
.endif

.if defined(WITHOUT_CAMPAIGN)
CMAKE_ARGS+=	-DENABLE_CAMPAIGN_SERVER=off
PLIST_SUB+=	CAMPAIGN="@comment "
.else
CMAKE_ARGS+=	-DENABLE_CAMPAIGN_SERVER=on
PLIST_SUB+=	CAMPAIGN=""
.endif

.if defined(WITHOUT_EDITOR)
CMAKE_ARGS+=	-DENABLE_EDITOR=off
PLIST_SUB+=	EDITOR="@comment "
.else
CMAKE_ARGS+=	-DENABLE_EDITOR=on
PLIST_SUB+=	EDITOR=""
.endif

.if defined(WITHOUT_FRIBIDI)
CMAKE_ARGS+=	-DENABLE_FRIBIDI=off
.else
CMAKE_ARGS+=	-DENABLE_FRIBIDI=on
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
.endif

.if defined(WITHOUT_LOWMEM)
CMAKE_ARGS+=	-DENABLE_LOW_MEM=off
.else
CMAKE_ARGS+=	-DENABLE_LOW_MEM=off
.endif

.if defined(WITHOUT_NOTIFY)
CMAKE_ARGS+=	-DENABLE_NOTIFICATIONS=off
.else
CMAKE_ARGS+=	-DENABLE_NOTIFICATIONS=on
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DENABLE_NLS=off
PLIST_SUB+=	NLS="@comment "
.else
CMAKE_ARGS+=	-DENABLE_NLS=on -DLOCALEDIR=${PREFIX}/share/locale
USE_GETTEXT=	yes
MANLANG=	"" cs de en_GB et fi fr gl hu id it ja lt pl pt_BR sk \
		sr sr@ijekavian sr@ijekavianlatin sr@latin zh_CN zh_TW
_MANPAGES+=	${PREFIX}/man/es/man6/wesnothd.6 \
		${PREFIX}/man/tr/man6/wesnothd.6
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_POOLALLOC)
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=off
.else
CMAKE_ARGS+=	-DENABLE_POOL_ALLOC=on
.endif

.if defined(WITHOUT_PYTHON)
PLIST_SUB+=	PYTHON="@comment "
.else
BROKEN=		cmake build doesn\'t support installing python tools
USE_PYTHON=	yes
CONFIGURE_ENV+=	PYTHON_PREFIX=${PREFIX} \
		PYTHON_VERSION=${PYTHON_VERSION:S/python//}
CONFIGURE_ARGS+=--enable-python-install
PLIST_SUB+=	PYTHON=""
.endif

.if !defined(WITHOUT_RAWSOCKETS)
CFLAGS+=	-DNETWORK_USE_RAW_SOCKETS
.endif

.if defined(WITHOUT_SERVER)
CMAKE_ARGS+=	-DENABLE_SERVER=off
PLIST_SUB+=	SERVER="@comment "
.else
CMAKE_ARGS+=	-DENABLE_SERVER=on
MAN6+=		wesnothd.6
PLIST_SUB+=	SERVER=""
.endif

.if defined(WITHOUT_TESTS)
CMAKE_ARGS+=	-DENABLE_TESTS=off
PLIST_SUB+=	TESTS="@comment "
.else
CMAKE_ARGS+=	-DENABLE_TESTS=on
PLIST_SUB+=	TESTS=""
.endif

.if !defined(WITHOUT_TINYGUI)
CMAKE_ARGS+=	-DGUI=tiny
BUILD_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITHOUT_TOOLS)
CMAKE_ARGS+=	-DENABLE_TOOLS=off
PLIST_SUB+=	TOOLS="@comment "
.else
CMAKE_ARGS+=	-DENABLE_TOOLS=on
PLIST_SUB+=	TOOLS=""
.endif

.if defined(NOPORTDOCS)
CMAKE_ARGS+=	-DDOCDIR=none
.endif

.if defined(NOPORTDATA)
IGNORE=		game data is required, undefine NOPORTDATA
.endif

post-install:
	-update-desktop-database ${PREFIX}/share/applications

.include <bsd.port.mk>
