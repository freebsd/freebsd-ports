PORTNAME=	Complete-Util
PORTVERSION=	0.618
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	General completion Perl routines
WWW=		https://metacpan.org/release/Complete-Util

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Complete-Common>=0.22:devel/p5-Complete-Common \
		p5-Log-ger>=0.038:devel/p5-Log-ger

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
