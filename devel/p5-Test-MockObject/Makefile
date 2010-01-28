# New ports collection makefile for:	p5-Test-MockObject
# Date Created:				16 Jul, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-MockObject
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

RUN_DEPENDS=	p5-UNIVERSAL-can>=1.11:${PORTSDIR}/devel/p5-UNIVERSAL-can \
		p5-UNIVERSAL-isa>=0.06:${PORTSDIR}/devel/p5-UNIVERSAL-isa

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::MockObject.3 Test::MockObject::Extends.3

.include <bsd.port.mk>
