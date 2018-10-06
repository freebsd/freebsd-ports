# $FreeBSD$

PORTNAME=	TAP-SimpleOutput
PORTVERSION=	0.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple closure-driven TAP generator

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Perl-Version>=0:devel/p5-Perl-Version \
		p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
