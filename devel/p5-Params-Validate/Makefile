# New ports collection makefile for:	Params::Validate
# Date created:				10 April 2001
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	Params-Validate
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	Validate method/function parameters

PERL_MODBUILD=	yes

MAN3=		Attribute::Params::Validate.3 Params::ValidateXS.3 \
		Params::ValidatePP.3 Params::Validate.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Attribute-Handlers>=0.79:${PORTSDIR}/devel/p5-Attribute-Handlers
BUILD_DEPENDS+=	p5-Attribute-Handlers>=0.79:${PORTSDIR}/devel/p5-Attribute-Handlers
.endif

.include <bsd.port.post.mk>
