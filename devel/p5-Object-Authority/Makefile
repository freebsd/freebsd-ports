PORTNAME=	Object-AUTHORITY
PORTVERSION=	0.004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that adds an AUTHORITY method to your class
WWW=		https://metacpan.org/release/TOBYINK/Object-AUTHORITY-0.004

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Object-Role>=0:devel/p5-Object-Role
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

# Remove old, broken, bundled Scalar::Util
post-extract:
	${RM} -rf ${WRKSRC}/inc/Scalar

.include <bsd.port.mk>
