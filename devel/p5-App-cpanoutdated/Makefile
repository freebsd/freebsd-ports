PORTNAME=	App-cpanoutdated
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect outdated CPAN modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-DistnameInfo>=0.10:devel/p5-CPAN-DistnameInfo \
		p5-libwww>=0:www/p5-libwww \
		p5-local-lib>=0:devel/p5-local-lib

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
