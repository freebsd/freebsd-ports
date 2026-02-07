PORTNAME=	POE-Component-IRC
PORTVERSION=	6.95
CATEGORIES=	irc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fully event-driven IRC client module
WWW=		https://metacpan.org/release/POE-Component-IRC

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IRC-Utils>=0.12:irc/p5-IRC-Utils \
		p5-POE-Component-Client-DNS>=0.99:dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-SSLify>=0:security/p5-POE-Component-SSLify \
		p5-POE-Component-Syndicator>=0.01:devel/p5-POE-Component-Syndicator \
		p5-POE-Filter-IRCD>=2.42:irc/p5-POE-Filter-IRCD \
		p5-POE>=1.311:devel/p5-POE
TEST_DEPENDS=	p5-Test-Differences>=0.610:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
