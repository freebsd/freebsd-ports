# Created by: ijliao
# $FreeBSD$

PORTNAME=	libassa
PORTVERSION=	3.4.2.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/3.4.2
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([[:digit:]])$/-\1/}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	C++ networking library and application framework

GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	ASSA_VERSION=${PORTVERSION:R:R}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/(\.[[:digit:]])$//}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/assa-genesis.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
