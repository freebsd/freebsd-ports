# New ports collection makefile for:	Devel-EvalContext
# Date created:	   			26 August 2007
# Whom:		   			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-EvalContext
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Save lexicals and hints between calls to eval

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/${PERL_ARCH}/Data/Alias.pm:${PORTSDIR}/devel/p5-Data-Alias \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::EvalContext.3

.include <bsd.port.mk>
