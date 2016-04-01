# Created by: ijliao
# $FreeBSD$

PORTNAME=	POE-Component-IRC
PORTVERSION=	6.88
PORTREVISION=	1
CATEGORIES=	irc devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fully event-driven IRC client module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-POE>=1.311:devel/p5-POE \
		p5-POE-Component-Syndicator>=0.01:devel/p5-POE-Component-Syndicator \
		p5-POE-Filter-IRCD>=2.42:irc/p5-POE-Filter-IRCD \
		p5-POE-Component-Client-DNS>=0.99:dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-SSLify>0:security/p5-POE-Component-SSLify \
		p5-IRC-Utils>=0.12:irc/p5-IRC-Utils \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
