# New ports collection makefile for:	wesnoth
# Date created:			22 December 2003
# Whom:				Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.6/${PORTNAME}-${PORTVERSION} \
		http://www.wesnoth.org/files/


MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	wesnoth-1.5*

USE_SDL=	image mixer net ttf
USE_GNOME=	gnometarget pango
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262
ACLOCAL_ARGS=	-Im4
AUTOMAKE_ARGS=	--add-missing --copy
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-localedir=${PREFIX}/share/locale

MANLANG=	"" cs de en_GB es fi fr hu it lt pl sr sr@latin sv tr \
		zh_CN zh_TW

MAN6=		wesnoth.6
MAN6_GL=	wesnoth.6
MAN6_RU=	wesnoth.6
MAN6_SK=	wesnoth.6

OPTIONS=	CAMPAIGN "Enable campaign server"	On \
		EDITOR	 "Enable map editor"		On \
		FRIBIDI	 "Enable bidirectional support"	On \
		NLS	 "Enable localization"		On \
		SERVER	 "Enable server"		On \
		TOOLS	 "Enable extra tools for artists and translators" On

.include <bsd.port.pre.mk>

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

.if defined(WITHOUT_FRIBIDI)
CONFIGURE_ARGS+=	--without-fribidi
.else
LIB_DEPENDS+=		fribidi.3:${PORTSDIR}/converters/fribidi
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

.if (defined(WITH_CAMPAIGN) || defined(WITH_SERVER) || defined(WITH_TOOLS)) && defined(WITHOUT_NLS)
BROKEN=		you need NLS support for `campaignd' or `wesnothd' or tools to link against gettext
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|[$$][{]datarootdir[}]/icons|${LOCALBASE}/share/pixmaps|' \
			${WRKSRC}/icons/Makefile

.include <bsd.port.post.mk>
