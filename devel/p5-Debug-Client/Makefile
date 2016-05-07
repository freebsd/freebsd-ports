# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	Debug-Client
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client for the standard Perl debugger

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PadWalker>=1.96:devel/p5-PadWalker \
		p5-ReadLine-Perl>=1.0303:devel/p5-ReadLine-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-HomeDir>=1:devel/p5-File-HomeDir \
		p5-ReadLine-Gnu>=1.20:devel/p5-ReadLine-Gnu \
		p5-Test-CheckDeps>=0.006:devel/p5-Test-CheckDeps \
		p5-Test-Class>=0.39:devel/p5-Test-Class \
		p5-Test-Deep>=0.110:devel/p5-Test-Deep \
		p5-Test-Requires>=0.07:devel/p5-Test-Requires

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.21:net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.21:net/p5-IO-Socket-IP
.endif

.include <bsd.port.post.mk>
