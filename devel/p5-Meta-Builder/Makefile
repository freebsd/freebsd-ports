# $FreeBSD$

PORTNAME=	Meta-Builder
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for creating Meta objects to track custom metrics

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Fennec-Lite>=0:${PORTSDIR}/devel/p5-Fennec-Lite

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Meta::Builder.3 \
	Meta::Builder::Base.3 \
	Meta::Builder::Util.3

NO_STAGE=	yes
.include <bsd.port.mk>
