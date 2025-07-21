PORTNAME=	freeciv
PORTVERSION=	3.2.0
PORTREVISION?=	0
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION} \
		http://files.freeciv.org/stable/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy
WWW=		https://www.freeciv.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicuuc.so:devel/icu \
		libltdl.so:devel/libltdl \
		libzstd.so:archivers/zstd
LIB_DEPENDS+=	${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=libunwind.so:devel/libunwind

USES=		autoreconf compiler:c++11-lang cpe desktop-file-utils gmake \
		iconv:wchar_t libtool lua:54 pkgconfig readline shebangfix ssl tar:xz
SHEBANG_FILES=	bootstrap/*.sh data/flags/convert* scripts/mapimg2anim \
		scripts/setup_auth_server.sh translations/*.sh

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--disable-static \
		--enable-aimodules \
		--enable-client=${_FREECIV_CLIENT:ts,} \
		--enable-fcdb=${_FREECIV_DB:ts,} \
		--enable-fcmp=${_FREECIV_MP:U:S/^/cli /:ts,} \
		--enable-mapimg=no \
		--enable-shared

LDFLAGS+=	-Wl,--as-needed ${ICONV_LIB}

PORTDATA=	*

OPTIONS_DEFINE=		DOCS IPV6  NLS
OPTIONS_DEFAULT=	QT6 SQLITE3
OPTIONS_MULTI=		DB UI
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE3
OPTIONS_MULTI_UI=	GTK3 GTK4 QT6 SDL
OPTIONS_SUB=		yes

DB_DESC=	Database support
UI_DESC=	GUI clients

GTK3_USES=	gnome sdl
GTK3_USE=	GNOME=cairo,gdkpixbuf,glib20,gtk30,pango \
		SDL=mixer2
GTK3_VARS=	_FREECIV_CLIENT+=gtk3.22 \
		_FREECIV_MP+=gtk3

GTK4_USES=	gnome sdl
GTK4_USE=	GNOME=cairo,gdkpixbuf,glib20,gtk40,pango \
		SDL=mixer2
GTK4_VARS=	_FREECIV_CLIENT+=gtk4 \
		_FREECIV_MP+=gtk4

IPV6_CONFIGURE_ENABLE=	ipv6

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql-prefix=${LOCALBASE}
MYSQL_VARS=		_FREECIV_DB+=mysql

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgres-prefix=${LOCALBASE}
PGSQL_VARS=		_FREECIV_DB+=postgres

QT6_USES=		qt:6 sdl
QT6_USE=		QT=base,tools:build \
			SDL=mixer2
QT6_CONFIGURE_ON=	--with-qt6=yes \
			--with-qt6-includes=${LOCALBASE}/${QT_INCDIR_REL} \
			--with-qt6-libs=${LOCALBASE}/${QT_LIBDIR_REL}
QT6_CONFIGURE_ENV=	MOCCMD=${MOC}
QT6_CONFIGURE_ENABLE=	ruledit
QT6_VARS=		_FREECIV_CLIENT+=qt \
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreeciv*.so

.include <bsd.port.post.mk>
