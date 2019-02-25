# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	spp
PORTVERSION=	0.4
CATEGORIES=	benchmarks
MASTER_SITES=	https://bitbucket.org/caia-swin/spp/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	caia-swin-${PORTNAME}

MAINTAINER=	lstewart@FreeBSD.org
COMMENT=	Calculates round trip time from pcap files or live capture

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		tar:bzip2
BB_TAGNAME=	8b9f676fed0e
WRKSRC=		${WRKDIR}/caia-swin-${PORTNAME}-${BB_TAGNAME}

PLIST_FILES=	bin/spp man/man1/spp.1.gz

.include <bsd.port.mk>
