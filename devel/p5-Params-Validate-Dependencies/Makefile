# New ports collection makefile for:	p5-Params-Validate-Dependencies
# Date created:		2011-09-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Params-Validate-Dependencies
PORTVERSION=	1.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validate combinations of parameters

BUILD_DEPENDS=	p5-Data-Domain>=0.13:${PORTSDIR}/devel/p5-Data-Domain \
		p5-PadWalker>=1.90:${PORTSDIR}/devel/p5-PadWalker \
		p5-Params-Validate>=0.91:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	p5-Data-Domain>=0.13:${PORTSDIR}/devel/p5-Data-Domain \
		p5-PadWalker>=1.90:${PORTSDIR}/devel/p5-PadWalker \
		p5-Params-Validate>=0.91:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		Data::Domain::Dependencies.3 \
		Params::Validate::Dependencies.3 \
		Params::Validate::Dependencies::Extending.3

.include <bsd.port.mk>
