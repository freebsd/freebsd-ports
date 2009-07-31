# New ports collection makefile for:	wesnoth-devel
# Date created:			7 September 2008
# Whom:				Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.5.14
PORTREVISION=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.wesnoth.org/files/
MASTER_SITE_SUBDIR=	wesnoth

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	wesnoth-1.4* wesnoth-1.6*

USE_SDL=	image mixer net ttf
USE_GNOME=	gnometarget pango
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-localedir=${PREFIX}/share/locale

MANLANG=	"" cs da de en_GB es fi fr gl hu it ja
MANLANG+=	lt nl pl racv sk sr sr@latin sv tr zh_CN zh_TW

MAN6_CS=	wesnoth.6
MAN6_DE=	wesnoth.6
MAN6_EN=	wesnoth.6
MAN6_EN_GB=	wesnoth.6
MAN6_ES=	wesnoth.6
MAN6_FI=	wesnoth.6
MAN6_GL=	wesnoth.6
MAN6_HU=	wesnoth.6
MAN6_IT=	wesnoth.6
MAN6_LT=	wesnoth.6
MAN6_PL=	wesnoth.6
MAN6_SK=	wesnoth.6
MAN6_TR=	wesnoth.6
MAN6_ZH_CN=	wesnoth.6

OPTIONS=	CAMPAIGN "Enable campaign server" On \
		EDITOR	"Enable map editor"  On \
		NLS	"Enable localization" On \
		SERVER "Enable server" On \
		TOOLS "Enable extra tools for artists and translators" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_CAMPAIGN)
PLIST_SUB+=		CAMPAIGN="@comment "
.else
CONFIGURE_ARGS+=	--enable-campaign-server
PLIST_SUB+=		CAMPAIGN=""
.endif

.if defined(WITHOUT_EDITOR)
PLIST_SUB+=		EDITOR="@comment "
CONFIGURE_ARGS+=	--disable-editor
.else
PLIST_SUB+=		EDITOR=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITHOUT_SERVER)
PLIST_SUB+=		SERVER="@comment "
.else
CONFIGURE_ARGS+=	--enable-server
MAN6+=			wesnothd.6
PLIST_SUB+=		SERVER=""
.endif

.if defined(WITHOUT_TOOLS)
PLIST_SUB+=		TOOLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS=""
.endif

.if defined(WITH_FRIBIDI) || exists(${LOCALBASE}/bin/fribidi-config)
LIB_DEPENDS+=		fribidi.0:${PORTSDIR}/converters/fribidi
.endif

.if (defined(WITH_CAMPAIGN) || defined(WITH_SERVER) || defined(WITH_TOOLS)) && defined(WITHOUT_NLS)
BROKEN=		you need NLS support for `campaignd' or `wesnothd' or tools to link against gettext
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|[$$][{]datarootdir[}]/icons|${LOCALBASE}/share/pixmaps|' \
			${WRKSRC}/icons/Makefile

.include <bsd.port.post.mk>
