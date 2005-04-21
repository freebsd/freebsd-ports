# New ports collection makefile for:	dnshijacker
# Date created:		2004-10-19
# Whom:			lx@redundancy.redundancy.org
#
# $FreeBSD$
#

PORTNAME=	dnshijacker
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	dns security
MASTER_SITES=	http://pedram.redhive.com/downloads/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A tool to hijack DNS requests

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

LDFLAGS+=	-lpcap -lnet

PLIST_FILES=	bin/dnshijacker

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

do-build:
	cd ${WRKSRC} && \
	${CC} ${PORTNAME}.c ${CFLAGS} -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib ${LDFLAGS} `libnet-config --defines` \
	`libnet-config --cflags` -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnshijacker ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
