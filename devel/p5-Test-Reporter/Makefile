# $FreeBSD$

PORTNAME=	Test-Reporter
PORTVERSION=	1.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Sends test results to cpan-testers@perl.org

RUN_DEPENDS=	p5-Net>0:${PORTSDIR}/net/p5-Net
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN3=		Test::Reporter.3 \
		Test::Reporter::Transport.3 \
		Test::Reporter::Transport::File.3 \
		Test::Reporter::Transport::Null.3

.include <bsd.port.mk>
