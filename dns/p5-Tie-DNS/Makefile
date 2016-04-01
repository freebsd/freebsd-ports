# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Tie-DNS
PORTVERSION=	1.151560
PORTEPOCH=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tie interface to Net::DNS

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Tie-Cache>=0:devel/p5-Tie-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckManifest>=0:devel/p5-Test-CheckManifest \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 shebangfix

PORTEXAMPLES=	*

SHEBANG_FILES=	eg/*.pl

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/eg/*.pl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
