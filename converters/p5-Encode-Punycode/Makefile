PORTNAME=	Encode-Punycode
PORTVERSION=	1.002
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Encode plugin for Punycode

LICENSE=	GPLv1

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings
RUN_DEPENDS=	p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
