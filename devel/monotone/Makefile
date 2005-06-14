# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.venge.net/monotone/downloads/ \
		http://norton.kettering.edu/freebsd/

MAINTAINER=	mwicks@kettering.edu
COMMENT=	A distributed version control system with digital signatures

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt		\
		boost_regex.2:${PORTSDIR}/devel/boost

USE_REINPLACE=	yes
USE_ICONV=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/monotone
INFO=		monotone
MAN1=		monotone.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.endif
.if defined(WITH_LUA_PORT)
LIB_DEPENDS+=	lua.5:${PORTSDIR}/lang/lua
CONFIGURE_ARGS+=	--with-bundled-lua=no
.endif
.if defined(WITH_SQLITE_PORT)
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-bundled-sqlite=no
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(CXX) -Wall\)|\1 ${CXXFLAGS}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
