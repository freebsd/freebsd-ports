# New ports collection makefile for:	yzis
# Date created:        Tue May 20 19:00:00 UTC 2008
# Whom:                Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	yzis
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://yzis.org.free.fr/releases/ \
		http://contribs.martymac.com/FreeBSD-ports/distfiles/
DISTNAME=	${PORTNAME}-M3

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Vi-like editor

LIB_DEPENDS=	audio:${PORTSDIR}/audio/nas \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		mng:${PORTSDIR}/graphics/libmng \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		ungif:${PORTSDIR}/graphics/libungif \
		ps:${PORTSDIR}/print/pslib
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		doxygen:${PORTSDIR}/devel/doxygen

USE_BZIP2=	yes
USE_FAM=	yes
USE_FREETYPE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LUA=	5.0
LUA_COMPS=	lua
USE_KDELIBS_VER=	3
USE_XORG=	xrender xext sm ice x11 xau xdmcp xt xi \
		xrandr xcursor xinerama xft xfixes

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
CPPFLAGS=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-lua-includes=${LUA_INCDIR} \
		--with-lua-libraries=${LUA_LIBDIR}
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
OPTIONS=	NCURSES "Build nyzis (ncurses frontend - buggy)" off

.include <bsd.port.pre.mk>

.if defined(WITH_NCURSES)
CONFIGURE_ARGS+=	--enable-nyzis
PLIST_SUB+=	PL_NCURSES=""
# Define_XOPEN_SOURCE_EXTENDED for ncurses/widec support
CPPFLAGS+=	-D_XOPEN_SOURCE_EXTENDED
.else
CONFIGURE_ARGS+=	--disable-nyzis
PLIST_SUB+=	PL_NCURSES="@comment "
.endif

.include <bsd.port.post.mk>
