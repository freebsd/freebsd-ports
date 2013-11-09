# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Tie-DNS
PORTVERSION=	1.132.260
PORTEPOCH=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tie interface to Net::DNS

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Tie-Cache>=0:${PORTSDIR}/devel/p5-Tie-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckManifest>=0:${PORTSDIR}/devel/p5-Test-CheckManifest \
		p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-PerlTidy>=0:${PORTSDIR}/devel/p5-Test-PerlTidy

OPTIONS_DEFINE=	EXAMPLES

USE_PERL5=	configure
USES=		perl5 shebangfix

PORTEXAMPLES=	*

SHEBANG_FILES=	eg/*.pl

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/eg/*.pl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
