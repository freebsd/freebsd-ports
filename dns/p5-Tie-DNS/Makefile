PORTNAME=	Tie-DNS
PORTVERSION=	1.151560
PORTEPOCH=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tie interface to Net::DNS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Tie-Cache>=0:devel/p5-Tie-Cache
TEST_DEPENDS=	p5-Test-CheckManifest>=0:devel/p5-Test-CheckManifest \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	eg/*.pl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/eg/*.pl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
