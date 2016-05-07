# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Base
PORTVERSION=	0.88
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Test::Base - A Data Driven Testing Framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
		p5-Spiffy>=0.30:devel/p5-Spiffy \
		p5-Test-Simple>=0.86:devel/p5-Test-Simple \
		p5-Test-Deep>0:devel/p5-Test-Deep \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-YAML>=0:textproc/p5-YAML \

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

#pre-install:	test

.include <bsd.port.mk>
