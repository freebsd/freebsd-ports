# New ports collection makefile for:	unbound
# Date created:				25 Apr 2008
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unbound
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A validating, recursive, and caching DNS resolver

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	unbound

MAN1=		unbound-host.1
MAN3=		libunbound.3
MAN5=		unbound.conf.5
MAN8=		unbound.8 unbound-checkconf.8

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall

OPTIONS=	LIBEVENT "is useful when using many (10000) outgoing ports" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT)
LIB_DEPENDS+=	event:${PORTSDIR}/devel/libevent
CONFIGURE_ARGS+=	--with-libevent=${PREFIX}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/etc/unbound/unbound.pid#/var/run/unbound/unbound.pid#' ${WRKSRC}/doc/example.conf ${WRKSRC}/doc/unbound.conf.5

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
