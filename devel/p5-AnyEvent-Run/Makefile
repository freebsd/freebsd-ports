# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	AnyEvent-Run
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Run a process or coderef asynchronously

RUN_DEPENDS=	p5-AnyEvent>=4.15:${PORTSDIR}/devel/p5-AnyEvent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		AnyEvent::Run.3

.include <bsd.port.mk>
