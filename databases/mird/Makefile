# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	mird
PORTVERSION=	1.0.7
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://grendel.firewall.com/caudium-pkg/ \
		http://www.mirar.org/mird/
DISTNAME=	Mird-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A free database library with transaction support

BROKEN=		Unfetchable due to checksum mismatch
DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=	2013-11-01

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_AUTOTOOLS=	autoconf:env
USE_GCC=	any
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS=,CFLAGS+=,' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,-O,,g' ${WRKSRC}/src/configure

post-install:
	${STRIP_CMD} ${PREFIX}/lib/libmird.so.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
