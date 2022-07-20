PORTNAME=	Data-Random
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for generating random data

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install
TEST_DEPENDS=	p5-Test-MockTime>=0:devel/p5-Test-MockTime

OPTIONS_DEFINE=	GD
GD_DESC=	Support for rand_image()

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

GD_BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD
GD_RUN_DEPENDS=		p5-GD>=0:graphics/p5-GD

.include <bsd.port.mk>
