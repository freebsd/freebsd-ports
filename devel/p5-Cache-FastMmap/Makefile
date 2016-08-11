# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Cache-FastMmap
PORTVERSION=	1.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN CPAN/Cache
MASTER_SITE_SUBDIR=	CPAN:ROBM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Uses an mmap\'ed file to act as a shared memory interprocess cache

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cache/FastMmap/FastMmap.so

.include <bsd.port.mk>
