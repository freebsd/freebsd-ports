# New ports collection makefile for:	freedroidrpg
# Date created:			18 Jul 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	freedroidrpg
PORTVERSION=	0.11.1
CATEGORIES=	games
MASTER_SITES=	SF/freedroid

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modification of the classical Freedroid engine into an RPG

USE_BZIP2=	yes
USE_SDL=	mixer image net sdl
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=

MAN6=		freedroidRPG.6

OPTIONS=	BACKTRACE "Use backtrace() to generate nice bug reports" on \
		EDITORS "Build the GTK editors" on \
		OPENGL "Enable the OpenGL support (highly recommended!)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BACKTRACE)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
CONFIGURE_ARGS+=--enable-backtrace
STRIP=		#
.else
CONFIGURE_ARGS+=--disable-backtrace
.endif

.if !defined(WITHOUT_EDITORS)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=--enable-editors
PLIST_SUB+=	EDITORS=""
.else
CONFIGURE_ARGS+=--disable-editors
PLIST_SUB+=	EDITORS="@comment "
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.include <bsd.port.post.mk>
