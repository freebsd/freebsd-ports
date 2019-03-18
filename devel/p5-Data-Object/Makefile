# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Object
PORTVERSION=	0.92
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data Type Objects for Perl 5

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>=1.002001:devel/p5-Exporter-Tiny \
		p5-Function-Parameters>=2.001003:devel/p5-Function-Parameters \
		p5-Import-Into>=1.002005:devel/p5-Import-Into \
		p5-JSON-Tiny>=0.58:converters/p5-JSON-Tiny \
		p5-Moo>=2.000001:devel/p5-Moo \
		p5-Path-Tiny>=0.108:devel/p5-Path-Tiny \
		p5-Role-Tiny>=2.000006:devel/p5-Role-Tiny \
		p5-Template-Tiny>=1.12:textproc/p5-Template-Tiny \
		p5-Try-Tiny>=0.30:lang/p5-Try-Tiny \
		p5-Type-Tiny>=1.000005:devel/p5-Type-Tiny \
		p5-YAML-Tiny>=1.73:textproc/p5-YAML-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
