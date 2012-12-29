# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Test-Strict
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test and report on use strict/warnings coverage

BUILD_DEPENDS=	p5-Devel-Cover>=0.43:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Modern-Perl>=0:${PORTSDIR}/lang/p5-Modern-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Strict.3

.include <bsd.port.mk>
