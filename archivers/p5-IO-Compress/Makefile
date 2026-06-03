PORTNAME=	IO-Compress
PORTVERSION=	2.220
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 compression modules (bzip2, deflate, gzip, zlib, zip)
WWW=		https://metacpan.org/release/IO-Compress

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Compress-Raw-Bzip2>=2.218:archivers/p5-Compress-Raw-Bzip2 \
		p5-Compress-Raw-Zlib>=2.218:archivers/p5-Compress-Raw-Zlib
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
