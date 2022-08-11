PORTNAME=	File-Find-Object-Rule
PORTVERSION=	0.0313
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative interface to File::Find::Object

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor \
		p5-File-Find-Object>=0:devel/p5-File-Find-Object \
		p5-Number-Compare>=0:math/p5-Number-Compare \
		p5-Text-Glob>=0:textproc/p5-Text-Glob
TEST_DEPENDS=	p5-File-TreeCreate>=0:devel/p5-File-TreeCreate

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
