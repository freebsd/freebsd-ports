# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	powerdns-recursor
PORTVERSION=	3.5.1
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

OPTIONS_DEFINE=	SETUID LUA STATIC
OPTIONS_DEFAULT=	SETUID
SETUID_DESC=		Run as pdns_recursor user
STATIC_DESC=		Build static binaries

CXXFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

MAN8=		rec_control.8 pdns_recursor.8
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

USE_RC_SUBR+=	pdns-recursor

.if ${PORT_OPTIONS:MSETUID}
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-setuid
USERS=		pdns_recursor
GROUPS=		pdns
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=5.1
LUA_COMPS=lua
MAKE_ENV+=LUA=1
MAKE_ENV+=LUA_CPPFLAGS_CONFIG=-I${PREFIX}/include/lua51
MAKE_ENV+="LUA_LIBS_CONFIG=-L${PREFIX}/lib/lua51/ -llua"
.endif

.if ${PORT_OPTIONS:MSTATIC}
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

post-install:
.if !exists(${PREFIX}/etc/pdns/recursor.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns/recursor.conf-dist \
		${PREFIX}/etc/pdns/recursor.conf
.endif
	@${INSTALL_MAN} ${WRKSRC}/*.8 ${PREFIX}/man/man8/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
