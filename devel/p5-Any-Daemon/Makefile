# Created by: Martin Waschbuesch <martin@waschbuesch.de>
# $FreeBSD$

PORTNAME=	Any-Daemon
PORTVERSION=	0.94
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Provides basic needs for a daemon

LICENSE=	ART10

RUN_DEPENDS:=	p5-Log-Report-Optional>=0:devel/p5-Log-Report-Optional \
		p5-File-Spec-Native>=0:devel/p5-File-Spec-Native

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
