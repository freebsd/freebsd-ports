# $FreeBSD$

PORTNAME=	Array-Heap
PORTVERSION=	3.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	eserte12@yahoo.de
COMMENT=	Perl module implementing fast binary heaps/priority queues

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Array/Heap/Heap.so

.include <bsd.port.mk>
