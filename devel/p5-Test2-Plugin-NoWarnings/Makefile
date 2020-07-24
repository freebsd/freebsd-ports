# $FreeBSD$

PORTNAME=	Test2-Plugin-NoWarnings
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fail if tests warn

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test2-Suite>=0:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503200
BUILD_DEPENDS+=	p5-Test-Simple>=1.302167:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302167:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
