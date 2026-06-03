PORTNAME=	User-Identity
PORTVERSION=	4.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manage informational objects related to a physical person
WWW=		https://metacpan.org/release/User-Identity

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Geography-Countries>=2009041301:misc/p5-Geography-Countries \
		p5-Hash-Ordered>=0.014:devel/p5-Hash-Ordered \
		p5-Log-Report>=1.42:devel/p5-Log-Report

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
