# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Validator
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Schema based configuration validation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-No-Worries>=1.0:${PORTSDIR}/devel/p5-No-Worries \
		p5-Scalar-List-Utils>=1.41:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-URI>=1.67:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
