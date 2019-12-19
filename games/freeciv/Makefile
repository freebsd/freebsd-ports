# Created by: ada@bsd.org
# $FreeBSD$

PORTNAME=	freeciv
PORTVERSION=	2.6.1
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libltdl.so:devel/libltdl

USES=		autoreconf compiler:c++11-lang gmake iconv libtool lua:53 \
		pkgconfig readline ssl tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--disable-static \
		--enable-aimodules \
		--enable-client=${_FREECIV_CLIENT:ts,} \
		--enable-fcdb=${_FREECIV_DB:ts,} \
		--enable-fcmp=${_FREECIV_MP:U:S/^/cli /:ts,} \
		--enable-mapimg=no \
		--enable-shared

LDFLAGS+=	-Wl,--as-needed

PORTDATA=	*

OPTIONS_DEFINE=		DOCS IPV6 NLS
OPTIONS_DEFAULT=	QT5 SQLITE3
OPTIONS_MULTI=		DB UI
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE3
OPTIONS_MULTI_UI=	GTK2 GTK3 QT5 SDL
OPTIONS_SUB=		yes

DB_DESC=	Database support
UI_DESC=	GUI clients

GTK2_USES=	gnome sdl
GTK2_USE=	GNOME=gdkpixbuf2,glib20,gtk20,pango SDL=mixer2
GTK2_VARS=	_FREECIV_CLIENT+=gtk2 \
		_FREECIV_MP+=gtk2

GTK3_USES=	gnome sdl
GTK3_USE=	GNOME=cairo,gdkpixbuf2,glib20,gtk30,pango SDL=mixer2
GTK3_VARS=	_FREECIV_CLIENT+=gtk3 \
		_FREECIV_MP+=gtk3

IPV6_CONFIGURE_ENABLE=	ipv6

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql-prefix=${LOCALBASE}
MYSQL_VARS=		_FREECIV_DB+=mysql

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgres-prefix=${LOCALBASE}
PGSQL_VARS=		_FREECIV_DB+=postgres

QT5_USES=		qt:5 sdl
QT5_USE=		QT=core,gui,widgets,buildtools_build SDL=mixer2
QT5_CONFIGURE_ON=	--with-qt5-includes=${LOCALBASE}/${QT_INCDIR_REL} \
			--with-qt5-libs=${LOCALBASE}/${QT_LIBDIR_REL}
QT5_CONFIGURE_ENABLE=	ruledit
QT5_VARS=		_FREECIV_CLIENT+=qt \
			_FREECIV_MP+=qt

SDL_USES=	sdl
SDL_USE=	SDL=gfx2,image2,mixer2,ttf2
SDL_VARS=	_FREECIV_CLIENT+=sdl2

SQLITE3_USES=	sqlite
SQLITE3_VARS=	_FREECIV_DB+=sqlite3

# Save OPTIONS_MULTI_UI value for later before the framework
# does things with it.
_FREECIV_CLIENTS:=	${OPTIONS_MULTI_UI}

.include <bsd.port.pre.mk>

.if ${_FREECIV_CLIENT:Uno} == no
CONFLICTS=	freeciv
PLIST_SUB+=	${_FREECIV_CLIENTS:S/$/="@comment "/} \
		CLIENT="@comment "
.else
CONFLICTS=	freeciv-nox11
PLIST_SUB+=	CLIENT=""
.endif

# Avoid annoying and too general LUA_LIBDIR=lib sub from USES=lua
PLIST_SUB:=	${PLIST_SUB:NLUA_LIBDIR=*}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreeciv*.so

.include <bsd.port.post.mk>
