# Created by: chinsan
# $FreeBSD$

PORTNAME=	Check-ISA
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MANWAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DWIM, correct checking of an object's class #'

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Sub-Exporter>=0:devel/p5-Sub-Exporter
BUILD_DEPENDS:=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
