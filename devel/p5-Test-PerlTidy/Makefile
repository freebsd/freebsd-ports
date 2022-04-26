PORTNAME=	Test-PerlTidy
PORTVERSION=	20210709
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to check that all your files are tidy

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Path-Tiny>=0.100:devel/p5-Path-Tiny \
		p5-Perl-Tidy>=20201001:devel/p5-Perl-Tidy \
		p5-Text-Diff>=0:textproc/p5-Text-Diff

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
