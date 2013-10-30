# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Module-Inspector
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An integrated API for inspecting Perl distributions

BUILD_DEPENDS=	p5-File-Find-Rule-VCS>=0:${PORTSDIR}/devel/p5-File-Find-Rule-VCS \
		p5-File-Find-Rule-Perl>=0:${PORTSDIR}/devel/p5-File-Find-Rule-Perl \
		p5-Module-Extract>=0:${PORTSDIR}/devel/p5-Module-Extract \
		p5-Module-Manifest>=0:${PORTSDIR}/devel/p5-Module-Manifest \
		p5-Module-Math-Depends>=0:${PORTSDIR}/devel/p5-Module-Math-Depends \
		p5-PPI>=0:${PORTSDIR}/textproc/p5-PPI \
		p5-YAML-Tiny>=0:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
