PORTNAME=	App-cpanminus-reporter
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkeenan@cpan.org
COMMENT=	Perl extension to send cpanm output to CPAN Testers database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
	p5-Config-Tiny>=2.08:devel/p5-Config-Tiny \
	p5-CPAN-Testers-Common-Client>=0.13:devel/p5-CPAN-Testers-Common-Client \
	p5-File-HomeDir>=0.58:devel/p5-File-HomeDir \
	p5-IO-Prompt-Tiny>=0:devel/p5-IO-Prompt-Tiny \
	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
	p5-Metabase-Fact>=0:devel/p5-Metabase-Fact \
	p5-Test-Reporter>=1.54:devel/p5-Test-Reporter \
	p5-Test-Reporter-Transport-Metabase>=0:devel/p5-Test-Reporter-Transport-Metabase \
	p5-Try-Tiny>=0:lang/p5-Try-Tiny \
	p5-URI>=0:net/p5-URI

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
