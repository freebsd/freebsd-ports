PORTNAME=	User-Identity
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manage informational objects related to a physical person
WWW=		https://metacpan.org/release/User-Identity

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Geography-Countries>=1.4:misc/p5-Geography-Countries \
		p5-Hash-Ordered>=0.014:devel/p5-Hash-Ordered

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
