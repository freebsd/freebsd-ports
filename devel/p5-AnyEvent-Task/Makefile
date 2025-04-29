PORTNAME=	AnyEvent-Task
PORTVERSION=	0.805
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client/server-based asynchronous worker pool
WWW=		https://metacpan.org/release/AnyEvent-Task

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Callback-Frame>=0:devel/p5-Callback-Frame \
		p5-Guard>=0:devel/p5-Guard \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Log-Defer>=0.300:devel/p5-Log-Defer \
		p5-common-sense>=0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
