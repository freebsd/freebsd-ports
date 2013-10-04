# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Dist-Joseki
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Tools for the prolific module author

RUN_DEPENDS=	p5-App-Cmd>=0:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Class-Accessor-Complex>=0:${PORTSDIR}/devel/p5-Class-Accessor-Complex \
		p5-Data-Rmap>=0:${PORTSDIR}/devel/p5-Data-Rmap \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Getopt-Attribute>=0:${PORTSDIR}/devel/p5-Getopt-Attribute \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
