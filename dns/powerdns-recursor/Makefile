# New ports collection makefile for:	powerdns-recursor
# Date Created:				14.Nov 2006
# Whom:					sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	powerdns-recursor
PORTVERSION=	3.1.7
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-recursor-${PORTVERSION}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	An advanced DNS recursor

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	SETUID	"Run as pdns_recursor user" on \
		LUA	"Enable Lua bindings" off \
		STATIC	"Build static binaries" off

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		rec_control.8 pdns_recursor.8
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns-recursor

.if defined(WITH_SETUID)
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-setuid
.endif

.if defined(WITH_LUA)
USE_LUA=5.1
LUA_COMPS=lua
MAKE_ENV+=LUA=1
MAKE_ENV+=LUA_CPPFLAGS_CONFIG=-I${LOCALBASE}/include/lua51
MAKE_ENV+="LUA_LIBS_CONFIG=-L${LOCALBASE}/lib/lua51/ -llua"
.endif

.if defined(WITH_STATIC)
MAKE_ENV+=STATIC=full
.endif

.if exists(/usr/include/ucontext.h)
UCONTEXT!=	${AWK} '/setcontext/ { print "YES" }' \
		/usr/include/ucontext.h
.if ${UCONTEXT} == ""
BROKEN=		requires setcontext()
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's;SBINDIR=/usr/sbin/;SBINDIR=${PREFIX}/sbin/;' \
	   -e 's;BINDIR=/usr/bin/;BINDIR=${PREFIX}/bin/;' \
	   -e 's;CONFIGDIR="/etc/powerdns/";CONFIGDIR=${PREFIX}/etc/pdns/;' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;"/etc/powerdns/";"${PREFIX}/etc/pdns/";' \
		${WRKSRC}/config.h

.if defined(WITH_SETUID)
pre-install:
		@${ECHO} "==>  Creating custom user to run pdns_recursor..."
		@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
.if !exists(${PREFIX}/etc/pdns/recursor.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns/recursor.conf-dist \
		${PREFIX}/etc/pdns/recursor.conf
.endif
	@${INSTALL_MAN} ${WRKSRC}/*.8 ${PREFIX}/man/man8/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
