# New ports collection makefile for:	wesnoth
# Date created:			22 December 2003
# Whom:				Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.wesnoth.org/files/
MASTER_SITE_SUBDIR=	wesnoth

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	image mixer net
USE_GNOME=	gnometarget
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-freetype-prefix=${LOCALBASE} \
		--with-localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS} -ftemplate-depth-45" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN6=		wesnoth.6
MANLANG=	"" ca_ES@valencia cs da de es fr gl hu it ja
MANLANG+=	lt nl pl sk sr sr@latin sv tr zh_CN

OPTIONS=	CAMPAIGN "Enable campaign server" On \
		EDITOR	"Enable map editor"  On \
		NLS	"Enable localization" On \
		SERVER "Enable server" On \
		TOOLS "Enable extra tools for artists and translators" On

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
.else
CONFIGURE_ARGS+=	--enable-editor
MAN6+=			wesnoth_editor.6
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

post-configure:
	@${REINPLACE_CMD} -e 's|[$$][{]datarootdir[}]/icons|${LOCALBASE}/share/pixmaps|' \
			${WRKSRC}/icons/Makefile

.include <bsd.port.post.mk>
