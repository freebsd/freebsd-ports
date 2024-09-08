PORTNAME=	Test-Simple
PORTVERSION=	1.302202
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Basic utilities for writing tests in perl
WWW=		https://metacpan.org/release/Test-Simple

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 504000
BUILD_DEPENDS+=	p5-Term-Table>=0.013:devel/p5-Term-Table
RUN_DEPENDS+=	p5-Term-Table>=0.013:devel/p5-Term-Table
.endif

.include <bsd.port.post.mk>
