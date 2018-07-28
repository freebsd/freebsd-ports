# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dumbbench
PORTVERSION=	0.111
CATEGORIES=	benchmarks perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	More reliable benchmarking with the least amount of thinking

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Class-XSAccessor>=1.05:devel/p5-Class-XSAccessor \
		p5-Devel-CheckOS>=0:devel/p5-Devel-CheckOS \
		p5-Number-WithError>=1:math/p5-Number-WithError \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Statistics-CaseResampling>=0.06:math/p5-Statistics-CaseResampling

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
