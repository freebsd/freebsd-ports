# $FreeBSD$

PORTNAME=	mDNSResponder
PORTVERSION=	1096.0.2
CATEGORIES=	dns net
MASTER_SITES=	http://opensource.apple.com/tarballs/mDNSResponder/
PKGNAMESUFFIX=	_nss

MAINTAINER=	mazhe@alkumuna.eu
COMMENT=	Apple mDNS responder - FreeBSD nsswitch module

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

CONFLICTS_INSTALL=	nss_mdns-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME:S/_nss//}-${PORTVERSION}

.include <bsd.port.pre.mk>

LD=${CC}

post-extract:
	@${CP} ${FILESDIR}/nss_mdns_freebsd.c ${WRKSRC}/mDNSPosix

do-build:
	(cd ${WRKSRC}/mDNSPosix && ${CC} ${CFLAGS} -c -std=c99 -Wall -fPIC \
		-I. -I${PREFIX}/include -DPREFIX=\"${PREFIX}\" \
		nss_mdns.c nss_mdns_freebsd.c)
	(cd ${WRKSRC}/mDNSPosix && ${LD} -shared -Wl,-soname=nss_mdns.so.1 nss_mdns.o nss_mdns_freebsd.o \
		-o nss_mdns.so.1 -L${PREFIX}/lib -R${PREFIX}/lib -ldns_sd)

post-build:
	${STRIP_CMD} ${WRKSRC}/mDNSPosix/nss_mdns.so.1

do-install:
	${INSTALL_LIB} ${WRKSRC}/mDNSPosix/nss_mdns.so.1 \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf nss_mdns.so.1 \
		${STAGEDIR}${PREFIX}/lib/nss_mdns.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/mDNSPosix/nss_mdns.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5

	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.conf \
		${STAGEDIR}${PREFIX}/etc/nss_mdns.conf.sample

.include <bsd.port.post.mk>
