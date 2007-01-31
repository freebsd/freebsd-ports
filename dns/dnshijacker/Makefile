# New ports collection makefile for:	dnshijacker
# Date created:		2004-10-19
# Whom:			lx@redundancy.redundancy.org
#
# $FreeBSD$
#

PORTNAME=	dnshijacker
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	dns security
MASTER_SITES=	http://pedram.redhive.com/downloads/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A tool to hijack DNS requests

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap `${LIBNET_CONFIG} --libs`

PLIST_FILES=	bin/dnshijacker

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

do-build:
	cd ${WRKSRC} && \
	${CC} ${PORTNAME}.c ${CFLAGS} -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib ${LDFLAGS} `${LIBNET_CONFIG} --defines` \
	`${LIBNET_CONFIG} --cflags` -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnshijacker ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
