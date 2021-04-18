# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Test2-Plugin-MemUsage
PORTVERSION=	0.002003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collect and display memory usage information

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test2-Suite>=0.000124:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503200
BUILD_DEPENDS+=	p5-Test-Simple>=1.302165:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302165:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
