PORTNAME=	PAR
PORTVERSION=	1.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Archive Toolkit
WWW=		https://metacpan.org/release/PAR

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=1:archivers/p5-Archive-Zip \
		p5-PAR-Dist>=0.32:devel/p5-PAR-Dist

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
