PORTNAME=	Shell-Config-Generate
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portably generate config for any shell
WWW=		https://metacpan.org/release/Shell-Config-Generate

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Shell-Guess>=0.09:devel/p5-Shell-Guess \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_FILES=	${SITE_PERL_REL}/Shell/Config/Generate.pm \
		${SITE_MAN3_REL}/Shell::Config::Generate.3.gz

.include <bsd.port.mk>
