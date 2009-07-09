# New ports collection makefile for:	B-Hooks-OP-Check
# Date created:	   11 Nov 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-OP-Check
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Wrap OP check callbacks

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
				${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent

PERL_CONFIGURE=	5.8.1+

MAN3=		B::Hooks::OP::Check.3

.include <bsd.port.mk>
