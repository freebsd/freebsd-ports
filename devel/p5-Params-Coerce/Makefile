# New ports collection makefile for:	p5-Params-Coerce
# Date created:		08 September 2007
# Whom:			Cory R. King <coryking@mozimedia.com>
#
# $FreeBSD$
#

PORTNAME=	Params-Coerce
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Allows your classes to do coercion of parameters  (Params::Coerce)

BUILD_DEPENDS=	p5-Params-Util>=0.20:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	p5-Params-Util>=0.20:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=		Params::Coerce.3

.include <bsd.port.mk>
