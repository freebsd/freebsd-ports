# Created by: vsevolod
# $FreeBSD$

PORTNAME=	libev
PORTVERSION=	4.15
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/ \
		http://dist.schmorp.de/libev/Attic/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A full-featured and high-performance event loop library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig

MAN3=		ev.3

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

NO_STAGE=	yes
post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/libev.pc.in > ${WRKDIR}/libev.pc

post-install:
	@${INSTALL_DATA} ${WRKDIR}/libev.pc ${PKGCONFIGDIR}/

.include <bsd.port.mk>
