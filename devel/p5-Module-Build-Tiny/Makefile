# If you have compelling evidence that some ports need at least this version of
# p5-Module-Build-Tiny to build, be sure to update the BUILD_DEPENDS version in
# Mk/Uses/perl5.mk.

PORTNAME=	Module-Build-Tiny
PORTVERSION=	0.052
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny replacement for Module::Build
WWW=		https://metacpan.org/release/Module-Build-Tiny

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-Requirements-Dynamic>=0:devel/p5-CPAN-Requirements-Dynamic \
		p5-ExtUtils-Config>=0.003:devel/p5-ExtUtils-Config \
		p5-ExtUtils-Helpers>=0.020:devel/p5-ExtUtils-Helpers \
		p5-ExtUtils-InstallPaths>=0.002:devel/p5-ExtUtils-InstallPaths

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
