# New ports collection makefile for:	netris
# Date created:	1 August 1996
# Whom:	desmo
#
# $FreeBSD$
#

PORTNAME=		netris
PORTVERSION=		0.52
CATEGORIES=		games ipv6
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

PATCH_SITES=		http://debian.lcs.mit.edu/pub/usagi/ftp.v6.linux.or.jp/IPv6-2/netris/
PATCHFILES=		netris-0.5-v6-19991206a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		gavin.atkinson@ury.york.ac.uk
COMMENT=		A network head to head version of T*tris

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		--cc '${CC}' --copt '${CFLAGS}'
MAN1=			netris.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/netris.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
