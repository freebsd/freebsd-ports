# New ports collection makefile for:	Context-Preserve
# Date created:	   12 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Context-Preserve
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Run code after a subroutine call, preserving the context the subroutine

TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Context::Preserve.3

.include <bsd.port.mk>
