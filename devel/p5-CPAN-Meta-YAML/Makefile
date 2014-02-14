# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CPAN-Meta-YAML
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write a subset of YAML for CPAN Meta files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Simple>=0.99:${PORTSDIR}/devel/p5-Test-Simple \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-JSON-PP>=0:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=0:${PORTSDIR}/converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
