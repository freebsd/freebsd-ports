PORTNAME=	Net-IDN-Nameprep
PORTVERSION=	1.102
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Normalization of domain names (Nameprep, RFC 3491)

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings
RUN_DEPENDS=	p5-Unicode-Stringprep>=0:converters/p5-Unicode-Stringprep

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
