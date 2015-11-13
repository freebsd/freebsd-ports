# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	geekbench
PORTVERSION=	2.1.13
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.primatelabs.ca/download/
DISTNAME=	Geekbench21-Linux
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform benchmark suite

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes

WRKSRC=		${WRKDIR}/dist/${DISTNAME}
PLIST_FILES=	bin/geekbench

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekbench_x86_32 \
		${STAGEDIR}${PREFIX}/bin/geekbench

.include <bsd.port.mk>
