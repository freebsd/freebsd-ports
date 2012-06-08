# New ports collection makefile for:	Devel-EvalContext
# Date created:	   			26 August 2007
# Whom:		   			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-EvalContext
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Save lexicals and hints between calls to eval

RUN_DEPENDS=	p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Data-Alias>=0:${PORTSDIR}/devel/p5-Data-Alias \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::EvalContext.3

.include <bsd.port.mk>
