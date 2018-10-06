# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Archive-Tar-Wrapper
PORTVERSION=	0.33
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API wrapper around the 'tar' utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
TEST_DEPENDS=	p5-Dumbbench>=0.111:benchmarks/p5-Dumbbench

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502508
TEST_DEPENDS+=	p5-Test-Simple>=1.302073:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
