PORTNAME=	Gravatar-URL
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHWERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make URLs for Gravatars from an email address

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-URI>=0:net/p5-URI

TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
