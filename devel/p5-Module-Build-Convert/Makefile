PORTNAME=	Module-Build-Convert
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makefile.PL to Build.PL converter
WWW=		https://metacpan.org/release/Module-Build-Convert

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-IO-Prompt>=0:devel/p5-IO-Prompt \
		p5-PPI>=0:textproc/p5-PPI

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
