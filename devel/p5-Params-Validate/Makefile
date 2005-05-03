# New ports collection makefile for:	Params::Validate
# Date created:				10 April 2001
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	Params-Validate
PORTVERSION=	0.77
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	Validate method/function parameters

PERL_CONFIGURE=	yes

MAN3=		Attribute::Params::Validate.3 Params::ValidateXS.3 \
		Params::ValidatePP.3 Params::Validate.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600 && ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers
RUN_DEPENDS+=	${SITE_PERL}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers
.endif

.include <bsd.port.post.mk>
