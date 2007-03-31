# New ports collection makefile for:	wesnoth
# Date created:			22 December 2003
# Whom:				Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.wesnoth.org/files/
MASTER_SITE_SUBDIR=	wesnoth

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A fantasy turn-based strategy game

USE_GCC=	3.4
USE_SDL=	image mixer net
USE_GNOME=	gnometarget
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-freetype-prefix=${LOCALBASE} \
		--with-localedir=${PREFIX}/share/locale \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS} -ftemplate-depth-45" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN6=		wesnoth.6
MANLANG=	"" cs de en_GB fr ja nl pt_BR sk sv

.if defined(WITH_CAMPAIGN) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-campaign-server
PLIST_SUB+=		CAMPAIGN:=""
.else
PLIST_SUB+=		CAMPAIGN:="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_ZIPIOS)
CONFIGURE_ARGS+=	--with-zipios
LIB_DEPENDS+=	zipios.0:${PORTSDIR}/archivers/zipios++
.endif

.if defined(WITH_EDITOR) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-editor
MAN6+=			wesnoth_editor.6
PLIST_SUB+=		EDITOR:=""
.else
PLIST_SUB+=		EDITOR:="@comment "
.endif

.if defined(WITH_SERVER) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-server
MAN6+=			wesnothd.6
PLIST_SUB+=		SERVER:=""
.else
PLIST_SUB+=		SERVER:="@comment "
.endif

.if defined(WITH_TOOLS) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS:=""
.else
PLIST_SUB+=		TOOLS:="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
CONFIGURE_ARGS+=	--with-gnome
PLIST_SUB+=		GNOME:=""
.else
PLIST_SUB+=		GNOME:="@comment "
.endif

.if exists(${LOCALBASE}/bin/kde-config)
CONFIGURE_ARGS+=	--with-kde
PLIST_SUB+=		KDE:=""
.else
PLIST_SUB+=		KDE:="@comment "
.endif

pre-everything::
.if !defined(WITH_CAMPAIGN) || !defined(WITH_DEBUG) || !defined(WITH_EDITOR) || !defined(WITH_SERVER) || !defined(WITH_TOOLS)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif
.if !defined(WITH_CAMPAIGN)
	@${ECHO_MSG} "WITH_CAMPAIGN=yes to enable compilation of campaign server."
.endif
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} "WITH_DEBUG=yes to enable debugging in Wesnoth."
.endif
.if !defined(WITH_EDITOR)
	@${ECHO_MSG} "WITH_EDITOR=yes to enable compilation of map editor."
.endif
.if !defined(WITH_SERVER)
	@${ECHO_MSG} "WITH_SERVER=yes to enable compilation of server."
.endif
.if !defined(WITH_TOOLS)
	@${ECHO_MSG} "WITH_TOOLS=yes to enable compilation of tools for translators and artists."
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|[$$][{]datarootdir[}]/applications|${LOCALBASE}/share/gnome/applications|; \
		s|[$$][{]datarootdir[}]/icons|${LOCALBASE}/share/gnome/pixmaps|' \
			${WRKSRC}/icons/Makefile

.include <bsd.port.post.mk>
