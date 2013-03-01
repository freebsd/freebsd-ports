# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	spp
PORTVERSION=	0.3.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://caia.swin.edu.au/tools/spp/downloads/

MAINTAINER=	lars@eggert.org
COMMENT=	Calculates round trip time from pcap files or live capture

PLIST_FILES=	bin/spp

post-patch:
	@${REINPLACE_CMD} -E '/(-DDEBUG|-g)/s|^|#|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
