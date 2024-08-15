PORTNAME=	FFI-C-Stat
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented FFI interface to native stat and lstat
WWW=		https://metacpan.org/dist/FFI-C-Stat

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FFI-Platypus>=1.00:devel/p5-FFI-Platypus \
		p5-Ref-Util>=0:devel/p5-Ref-Util
TEST_DEPENDS=	p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Script>=1.09:devel/p5-Test-Script \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/share/dist/FFI-C-Stat/lib/libFFI-C-Stat.so

.include <bsd.port.mk>
