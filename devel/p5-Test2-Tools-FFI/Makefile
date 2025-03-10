PORTNAME=	Test2-Tools-FFI
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for testing FFI
WWW=		https://metacpan.org/dist/Test2-Tools-FFI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-FFI-CheckLib>=0.11:devel/p5-FFI-CheckLib \
		p5-FFI-Platypus>=1.00:devel/p5-FFI-Platypus \
		p5-File-ShareDir-Dist>=0:devel/p5-File-ShareDir-Dist
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/share/dist/Test2-Tools-FFI/lib/libt2t.so

.include <bsd.port.mk>
