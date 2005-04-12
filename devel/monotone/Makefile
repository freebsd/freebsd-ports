# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	http://www.venge.net/monotone/  \
		http://norton.kettering.edu/freebsd/

MAINTAINER=	mwicks@kettering.edu
COMMENT=	A distributed version control system with digital signatures

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt		\
		boost_regex.2:${PORTSDIR}/devel/boost

USE_ICONV=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	bin/monotone
INFO=		monotone
MAN1=		monotone.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.endif
.if !defined(WITHOUT_ADNS)
LIB_DEPENDS+=	adns.1:${PORTSDIR}/dns/adns
.else
CONFIGURE_ARGS+=	--with-bundled-adns
.endif
.if !defined(WITHOUT_LUA)
LIB_DEPENDS+=	lua.5:${PORTSDIR}/lang/lua
.else
CONFIGURE_ARGS+=	--with-bundled-lua
.endif
.if !defined(WITHOUT_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
.else
CONFIGURE_ARGS+=	--with-bundled-sqlite
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile on FreeBSD-4.11"
.endif

.include <bsd.port.post.mk>
