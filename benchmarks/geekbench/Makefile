# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	geekbench
PORTVERSION=	2.1.13
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.primatelabs.ca/download/
DISTNAME=	Geekbench21-Linux
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Cross-platform benchmark suite

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes

WRKSRC=		${WRKDIR}/dist/${DISTNAME}
PLIST_FILES=	bin/geekbench

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekbench_x86_32 ${PREFIX}/bin/geekbench

.include <bsd.port.mk>
