# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	namespace-sweep
PORTVERSION=	0.006
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Sweep up imported subs in your classes

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.09:devel/p5-B-Hooks-EndOfScope \
		p5-Package-Stash>=0.33:devel/p5-Package-Stash \
		p5-Sub-Identify>=0.04:devel/p5-Sub-Identify \
		p5-Sub-Name>=0:devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
