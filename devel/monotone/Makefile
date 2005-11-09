# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	0.23
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.venge.net/monotone/downloads/ \
		http://norton.kettering.edu/freebsd/

MAINTAINER=	lapo@lapo.it
COMMENT=	A distributed version control system with digital signatures

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		boost_regex.3:${PORTSDIR}/devel/boost

OPTIONS=	LUA_PORT "Use Lua port instead of the included one" on \
		SQLITE_PORT "Use SQLite3 port instead of the included one" on

USE_REINPLACE=	yes
USE_ICONV=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

PLIST_FILES=	bin/monotone
INFO=		monotone
MAN1=		monotone.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST_FILES+=	share/locale/fr/LC_MESSAGES/monotone.mo \
		share/locale/ja/LC_MESSAGES/monotone.mo
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LUA_PORT)
LIB_DEPENDS+=	lua.5:${PORTSDIR}/lang/lua
CONFIGURE_ARGS+=	--with-bundled-lua=no
.endif
.if !defined(WITHOUT_SQLITE_PORT)
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-bundled-sqlite=no
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/monotone.info*

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(CXX) -Wall\)|\1 ${CXXFLAGS}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
