# New ports collection makefile for:	p5-GD-TextUtil
# Date created:				21 February 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	GD-TextUtil
PORTVERSION=	0.86
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GDTextUtil-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text utilities for use with GD drawing package

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

PERL_CONFIGURE=	YES

MAN3=		GD::Text.3 GD::Text::Wrap.3 GD::Text::Align.3

.include <bsd.port.mk>
