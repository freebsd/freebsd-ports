# Created by: vsevolod
# $FreeBSD$

PORTNAME=	libev
PORTVERSION=	4.22
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/ \
		http://dist.schmorp.de/libev/Attic/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Full-featured and high-performance event loop library

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig
USE_LDCONFIG=	yes

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/libev.pc.in > ${WRKDIR}/libev.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/libev.pc ${STAGEDIR}${PKGCONFIGDIR}/

.include <bsd.port.mk>
