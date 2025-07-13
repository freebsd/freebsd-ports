PORTNAME=	PAR-Packer
PORTVERSION=	1.064
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PAR Packager
WWW=		https://metacpan.org/release/PAR-Packer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=1.02:archivers/p5-Archive-Zip \
		p5-Getopt-ArgvFile>=1.07:devel/p5-Getopt-ArgvFile \
		p5-Module-ScanDeps>=1.21:devel/p5-Module-ScanDeps \
		p5-Module-Signature>=0:security/p5-Module-Signature \
		p5-PAR>=1.020:devel/p5-PAR \
		p5-PAR-Dist>=0.22:devel/p5-PAR-Dist
TEST_DEPENDS=	p5-IPC-Run3>=0.048:devel/p5-IPC-Run3

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/parl ${STAGEDIR}${PREFIX}/bin/parldyn

.include <bsd.port.mk>
