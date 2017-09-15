# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	Test-Script
PORTVERSION=	1.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Script - Cross-platform basic tests for scripts

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Probe-Perl>=0.01:sysutils/p5-Probe-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test2-Suite>=0.000060:devel/p5-Test2-Suite

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502501
BUILD_DEPENDS+=	p5-Test-Simple>=1.302015:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302015:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
