# New ports collection makefile for:	wesnoth
# Date created:			22 December 2003
# Whom:				Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	wesnoth
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.wesnoth.org/files/

MAINTAINER=	mezz7@cox.net
COMMENT=	A fantasy turn-based strategy game

USE_SDL=	image mixer net ttf sdl
USE_GNOME=	gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN6=		wesnoth.6 wesnothd.6

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_EDITOR) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-editor
PLIST_SUB+=		EDITOR:=""
.else
PLIST_SUB+=		EDITOR:="@comment "
.endif

.if defined(WITH_SERVER) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-server
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

pre-everything::
.if !defined(WITH_DEBUG) || !defined(WITH_EDITOR) || !defined(WITH_SERVER) || !defined(WITH_TOOLS)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif

.if !defined(WITH_DEBUG)
	@${ECHO_MSG} "WITH_DEBUG=yes for enable debug in wesnoth."
.endif

.if !defined(WITH_EDITOR)
	@${ECHO_MSG} "WITH_EDITOR=yes for enable compilation editor."
.endif

.if !defined(WITH_SERVER)
	@${ECHO_MSG} "WITH_SERVER=yes for enable compilation of server."
.endif

.if !defined(WITH_TOOLS)
	@${ECHO_MSG} "WITH_TOOLS=yes for enable compilation of translation tools."
.endif

.include <bsd.port.mk>
