# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Archive-Any
PORTVERSION=	0.0945
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Single interface to deal with file archives

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Archive-Zip>=1.07:archivers/p5-Archive-Zip \
		p5-File-MMagic>=1.27:devel/p5-File-MMagic \
		p5-MIME-Types>=1.16:mail/p5-MIME-Types \
		p5-Module-Find>=0.05:devel/p5-Module-Find
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic \
		p5-Test-Warn>=0:devel/p5-Test-Warn

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
