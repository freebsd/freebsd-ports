# Created by: Yuan-Chung Hsiao & <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	Module-Build-Kwalitee
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Module::Build subclass with prepackaged tests

BUILD_DEPENDS=	p5-YAML>=0:textproc/p5-YAML \
		p5-Module-Build>=0.26.09:devel/p5-Module-Build \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-File-Find-Rule>=0:devel/p5-File-Find-Rule

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
