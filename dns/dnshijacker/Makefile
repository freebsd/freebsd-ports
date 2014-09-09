# Created by: lx@redundancy.redundancy.org
# $FreeBSD$

PORTNAME=	dnshijacker
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	dns security
MASTER_SITES=	http://pedram.redhive.com/downloads/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	Tool to hijack DNS requests

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap `${LIBNET_CONFIG} --libs`

PLIST_FILES=	bin/dnshijacker

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

PORTDOCS=	README

do-build:
	cd ${WRKSRC} && \
	${CC} ${PORTNAME}.c ${CFLAGS} -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib ${LDFLAGS} `${LIBNET_CONFIG} --defines` \
	`${LIBNET_CONFIG} --cflags` -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnshijacker ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
