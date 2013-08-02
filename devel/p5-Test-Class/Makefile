# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Class
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Class - Easily create test classes in an xUnit style

RUN_DEPENDS=	p5-MRO-Compat>=0.11:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Exception>=0.25:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Test::Class.3 \
		Test::Class::Load.3 \
		Test::Class::MethodInfo.3

.include <bsd.port.mk>
