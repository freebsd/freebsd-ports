PORTNAME=	CPAN-Requirements-Dynamic
PORTVERSION=	0.002
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dynamic prerequisites in meta files
WWW=		https://metacpan.org/dist/CPAN-Requirements-Dynamic

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 504000
BUILD_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.142:devel/p5-CPAN-Meta-Requirements
RUN_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.142:devel/p5-CPAN-Meta-Requirements
.endif

.include <bsd.port.post.mk>
