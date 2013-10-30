# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	IO-YAML
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write YAML streams incrementally

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
