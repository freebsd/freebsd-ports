# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent
PKGNAMESUFFIX=	-hiphop
PORTVERSION=	1.4.14b
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/
DISTNAME=	${PORTNAME}-${DISTVERSION}-stable

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Static libevent with custom patches for HipHop

LICENSE=	BSD3CLAUSE

HIPHOP_DIR=	share/hiphop-php

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-shared --enable-static
GNU_CONFIGURE_PREFIX=	${PREFIX}/${HIPHOP_DIR}/ext
INSTALL_TARGET=	install-libLTLIBRARIES \
		install-includeHEADERS \
		install-nodist_includeHEADERS
USES=		libtool
PLIST_SUB+=	HIPHOP_DIR="${HIPHOP_DIR}"

pre-configure:
	@${MKDIR} ${WRKSRC}/m4

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/s/-lrt//g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/epoll.c ${WRKSRC}/epoll_sub.c ${WRKSRC}/evdns.c

regression-test: build
	@(${SH} ${WRKSRC}/test/regress)

.include <bsd.port.mk>
