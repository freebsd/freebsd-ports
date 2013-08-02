# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Devel-Profiler
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl profiler compatible with dprofpp

BUILD_DEPENDS=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Devel::Profiler.3 Devel::Profiler::Apache.3 \
		Devel::Profiler::Test.3

.include <bsd.port.mk>
