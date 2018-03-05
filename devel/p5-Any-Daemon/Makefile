# Created by: Martin Waschbuesch <martin@waschbuesch.de>
# $FreeBSD$

PORTNAME=	Any-Daemon
PORTVERSION=	0.95
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Provides basic needs for a daemon

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report-Optional>=1.06:devel/p5-Log-Report-Optional
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
