# $FreeBSD$

PORTNAME=	mDNSResponder_nss
PORTVERSION=	544
CATEGORIES=	dns net
MASTER_SITES=	http://opensource.apple.com/tarballs/mDNSResponder/
DISTNAME=	${PORTNAME:S/_nss//}-${PORTVERSION}

MAINTAINER=	mazhe@alkumuna.eu
COMMENT=	Apple mDNS responder - FreeBSD nsswitch module

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libdns_sd.so:${PORTSDIR}/net/mDNSResponder

CONFLICTS_INSTALL=	dns/nss_mdns

WRKSRC=		${WRKDIR}/${PORTNAME:S/_nss//}-${PORTVERSION}

post-extract:
	@${CP} ${FILESDIR}/nss_mdns_freebsd.c ${WRKSRC}/mDNSPosix

do-build:
	(cd ${WRKSRC}/mDNSPosix && ${CC} ${CFLAGS} -c -std=c99 -Wall -fPIC \
		-I. -I${PREFIX}/include -DPREFIX=\"${PREFIX}\" \
		nss_mdns.c nss_mdns_freebsd.c)
	(cd ${WRKSRC}/mDNSPosix && ${LD} -shared nss_mdns.o nss_mdns_freebsd.o \
		-o nss_mdns.so.1 -L${PREFIX}/lib -R${PREFIX}/lib -ldns_sd)

do-install:
	${INSTALL_LIB} ${WRKSRC}/mDNSPosix/nss_mdns.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/nss_mdns.so.1 ${STAGEDIR}${PREFIX}/lib/nss_mdns.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/mDNSPosix/nss_mdns.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nss_mdns.so.1

.include <bsd.port.mk>
