# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	IO-YAML
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write YAML streams incrementally

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
