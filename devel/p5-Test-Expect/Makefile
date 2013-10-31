# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Expect
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated driving and testing of terminal-based programs

BUILD_DEPENDS=	p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Expect-Simple>=0:${PORTSDIR}/devel/p5-Expect-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
