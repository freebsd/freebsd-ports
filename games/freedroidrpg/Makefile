# New ports collection makefile for:	freedroidrpg
# Date created:			18 Jul 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	freedroidrpg
PORTVERSION=	0.9.13
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freedroid

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Modification of the classical Freedroid engine into an RPG

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_SDL=	mixer image net sdl
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=

MAN6=		freedroidRPG.6

OPTIONS=	BACKTRACE "Use backtrace() to generate nice bug reports" on \
		EDITORS "Build the GTK editors" on \
		OPENGL "Enable the OpenGL support (highly recommended!)" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile (missing fenv.h)"
.endif

.if defined(WITH_BACKTRACE)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
CONFIGURE_ARGS+=--enable-backtrace
STRIP=		# keep debugging symbols
.else
CONFIGURE_ARGS+=--disable-backtrace
.endif

.if defined(WITH_EDITORS)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=--enable-editors
PLIST_SUB+=	EDITORS=""
.else
CONFIGURE_ARGS+=--disable-editors
PLIST_SUB+=	EDITORS="@comment "
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.include <bsd.port.post.mk>
