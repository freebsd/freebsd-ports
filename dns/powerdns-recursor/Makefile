# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	powerdns-recursor
PORTVERSION=	3.5.3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-recursor-${PORTVERSION}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	Advanced DNS recursor

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USES=		gmake tar:bzip2

OPTIONS_DEFINE=	SETUID LUA STATIC
OPTIONS_DEFAULT=	SETUID
SETUID_DESC=		Run as pdns_recursor user
STATIC_DESC=		Build static binaries

CXXFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

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
USES+=		lua:51
MAKE_ENV+=LUA=1
MAKE_ENV+="LUA_CPPFLAGS_CONFIG=-I${LUA_INCDIR}"
MAKE_ENV+="LUA_LIBS_CONFIG=-L${LUA_LIBDIR} -llua-${LUA_VER}"
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
	${INSTALL_MAN} ${WRKSRC}/*.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
