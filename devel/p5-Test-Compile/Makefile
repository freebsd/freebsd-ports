# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Test-Compile
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EGILES
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check whether Perl module files compile correctly

BUILD_DEPENDS=	p5-Devel-CheckOS>=0:${PORTSDIR}/devel/p5-Devel-CheckOS \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Compile.3 Test::Compile::Internal.3

.include <bsd.port.mk>
