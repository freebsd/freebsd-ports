# Created by: vsevolod
# $FreeBSD$

PORTNAME=	libev
DISTVERSION=	4.33
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/ \
		http://dist.schmorp.de/libev/Attic/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Full-featured and high-performance event loop library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/libev.pc.in > ${WRKDIR}/libev.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/libev.pc ${STAGEDIR}${PKGCONFIGDIR}/

.include <bsd.port.mk>
