CATEGORIES=	dns net
# Always set PORTREVISION explicitly as otherwise it is inherited from net/mDNSResponder
PORTREVISION=	0
PKGNAMESUFFIX=	_nss

MAINTAINER=	mazhe@alkumuna.eu
COMMENT=	Apple mDNS responder - FreeBSD nsswitch module
WWW=		https://opensource.apple.com/tarballs/mDNSResponder/

LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

CONFLICTS_INSTALL=	nss_mdns

MASTERDIR=	${.CURDIR}/../../net/mDNSResponder
EXTRA_PATCHES=	${.CURDIR}/files/patch-mDNSPosix__nss_mdns.c
PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message
DESCR=		${.CURDIR}/pkg-descr

# Disable some master port targets
TARGET_ORDER_OVERRIDE=	-1:post-install -1:install-rc-script

post-extract:
	@${CP} ${.CURDIR}/files/nss_mdns_freebsd.c ${WRKSRC}/mDNSPosix

do-build:
	(cd ${WRKSRC}/mDNSPosix && ${CC} ${CFLAGS} -c -std=c99 -Wall -fPIC \
		-I. -I${PREFIX}/include -DPREFIX=\"${PREFIX}\" \
		nss_mdns.c nss_mdns_freebsd.c)
	(cd ${WRKSRC}/mDNSPosix && ${CC} -shared -Wl,-soname=nss_mdns.so.1 nss_mdns.o nss_mdns_freebsd.o \
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

.include "${MASTERDIR}/Makefile"
