# New ports collection makefile for:	MooseX-Singleton
# Date created:	   04 Jun 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Singleton
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Turn Moose class into a singleton

BUILD_DEPENDS=	p5-Moose>=1.10:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-NoWarnings>=0.01:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Warn>=0.01:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		MooseX::Singleton.3 \
		MooseX::Singleton::Role::Meta::Class.3 \
		MooseX::Singleton::Role::Meta::Instance.3 \
		MooseX::Singleton::Role::Meta::Method::Constructor.3 \
		MooseX::Singleton::Role::Object.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
