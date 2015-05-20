# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CPAN-Meta-YAML
PORTVERSION=	0.016
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write a subset of YAML for CPAN Meta files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
TEST_DEPENDS+=	p5-Test-Simple>=0.99:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
