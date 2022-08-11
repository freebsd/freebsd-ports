PORTNAME=	Archive-Extract-Libarchive
PORTVERSION=	0.38
PORTREVISION=	4
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic archive extracting mechanism (using libarchive)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Object-Tiny>=0:devel/p5-Object-Tiny
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-Pod>=1.04:devel/p5-Test-Pod

USES=		libarchive perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Archive/Extract/Libarchive/Libarchive.so

.include <bsd.port.mk>
