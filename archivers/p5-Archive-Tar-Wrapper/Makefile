PORTNAME=	Archive-Tar-Wrapper
PORTVERSION=	0.42
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API wrapper around the 'tar' utility
WWW=		https://metacpan.org/release/Archive-Tar-Wrapper

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
TEST_DEPENDS=	p5-Dumbbench>=0.111:benchmarks/p5-Dumbbench

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
