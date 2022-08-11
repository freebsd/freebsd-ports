PORTNAME=	AnyEvent-DBI
PORTVERSION=	3.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous DBI access

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=4.15,1:devel/p5-AnyEvent \
		p5-AnyEvent-Fork>=1.31:devel/p5-AnyEvent-Fork \
		p5-CBOR-XS>=1.7:devel/p5-CBOR-XS \
		p5-Convert-Scalar>=1.12:devel/p5-Convert-Scalar \
		p5-DBI>=1.0:databases/p5-DBI \
		p5-common-sense>=3.3:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
