# New ports collection makefile for:	Test::LoadAllModules
# Date created:		27 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-LoadAllModules
PORTVERSION=	0.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to do use_ok for modules in search path

RUN_DEPENDS=	\
	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::LoadAllModules.3

.include <bsd.port.mk>
