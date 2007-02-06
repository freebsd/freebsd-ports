# New ports collection makefile for:	powerdns-recursor
# Date Created:				14.Nov 2006
# Whom:					sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	powerdns-recursor
PORTVERSION=	3.1.4
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-recursor-${PORTVERSION}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	An advanced DNS recursor

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4

OPTIONS=	STATIC	"Enable Full STATIC" off

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	CXX="${CXX}" CC="${CC}"

MAN8=		rec_control.8 pdns_recursor.8
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns-recursor

.if defined(WITH_STATIC)
MAKE_ENV+=STATIC=full
PLIST_SUB+=	STATIC="@comment "
.endif

.if exists(/usr/include/ucontext.h) && ${OSVERSION} >= 500000
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

pre-install:
		@${ECHO} "==>  Creating custom user to run pdns_recursor..."
		@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !exists(${PREFIX}/etc/pdns/recursor.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns/recursor.conf-dist \
		${PREFIX}/etc/pdns/recursor.conf
.endif
	@${INSTALL_MAN} ${WRKSRC}/*.8 ${PREFIX}/man/man8/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
