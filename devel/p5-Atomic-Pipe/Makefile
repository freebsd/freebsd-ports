PORTNAME=	Atomic-Pipe
PORTVERSION=	0.029
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Send atomic messages from multiple writers across a POSIX pipe
WWW=		https://metacpan.org/dist/Atomic-Pipe

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

TEST_DEPENDS=	py-Test-Simple>=1.302200:devel/py-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Compress-Zstd>=0:archivers/p5-Compress-Zstd
RECOMMENDED_RUN_DEPENDS=p5-Compress-Zstd>=0:archivers/p5-Compress-Zstd

.include <bsd.port.mk>
