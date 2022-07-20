PORTNAME=	Archive-Any
PORTVERSION=	0.0946
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Single interface to deal with file archives

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=1.07:archivers/p5-Archive-Zip \
		p5-File-MMagic>=1.27:devel/p5-File-MMagic \
		p5-MIME-Types>=1.16:mail/p5-MIME-Types \
		p5-Module-Find>=0.05:devel/p5-Module-Find
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
