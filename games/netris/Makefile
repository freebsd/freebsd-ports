# Created by: desmo
# $FreeBSD$

PORTNAME=		netris
PORTVERSION=		0.52
CATEGORIES=		games ipv6
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

PATCH_SITES=		http://debian.lcs.mit.edu/pub/usagi/ftp.v6.linux.or.jp/IPv6-2/netris/
PATCHFILES=		netris-0.5-v6-19991206a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		gavin@FreeBSD.org
COMMENT=		Network head to head version of T*tris

BROKEN=			unfetchable
LICENSE=		GPLv2+

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		--cc '${CC}' --copt '${CFLAGS}'
CONFIGURE_ARGS+=	--enable-ipv6

PLIST_FILES=	bin/netris \
		bin/sample-robot \
		man/man1/netris.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netris ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sr ${STAGEDIR}${PREFIX}/bin/sample-robot
	${INSTALL_MAN} ${FILESDIR}/netris.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
