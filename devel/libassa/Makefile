# Created by: ijliao
# $FreeBSD$

PORTNAME=	libassa
DISTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[0-9]*$//}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	C++ networking library and application framework

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	TIRPC_CFLAGS=" " TIRPC_LIBS=" "
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	ASSA_VERSION=${PORTVERSION:R:R}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*$//}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/assa-genesis.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
