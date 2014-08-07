# Created by: Muhammad Moinur Rahman<5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	MooX-Cmd
PORTVERSION=	0.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Giving an easy Moo style way to make command organized CLI apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-TieCombine>=0:${PORTSDIR}/devel/p5-IO-TieCombine \
		p5-Module-Pluggable>=4.8:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Moo>=0.009013:${PORTSDIR}/devel/p5-Moo \
		p5-Package-Stash>=0.33:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Regexp-Common>=2011121001:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Test-LoadAllModules>=0.021:${PORTSDIR}/devel/p5-Test-LoadAllModules
RUN_DEPENDS:=	p5-IO-TieCombine>=0:${PORTSDIR}/devel/p5-IO-TieCombine \
		p5-Module-Pluggable>=4.8:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Moo>=0.009013:${PORTSDIR}/devel/p5-Moo \
		p5-Package-Stash>=0.33:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Regexp-Common>=2011121001:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Test-LoadAllModules>=0.021:${PORTSDIR}/devel/p5-Test-LoadAllModules

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
