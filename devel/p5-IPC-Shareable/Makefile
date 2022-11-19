PORTNAME=	IPC-Shareable
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Share Perl variables between processes
WWW=		https://metacpan.org/release/IPC-Shareable

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-String-CRC32>=0:devel/p5-String-CRC32
TEST_DEPENDS=	p5-Mock-Sub>=0:devel/p5-Mock-Sub \
		p5-Test-SharedFork>=0.35:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
