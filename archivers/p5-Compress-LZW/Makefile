# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Compress-LZW
PORTVERSION=	0.04
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure perl implementation of LZW

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moo>=1.001000:devel/p5-Moo \
		p5-Type-Tiny>0:devel/p5-Type-Tiny \
		p5-namespace-clean>0:devel/p5-namespace-clean \
		p5-strictures>0:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
