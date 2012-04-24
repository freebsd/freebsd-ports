# New ports collection makefile for:	p5-MooseX-TransactionalMethods
# Date created:		2012-04-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-TransactionalMethods
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Syntax sugar for transactional methods

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased
RUN_DEPENDS=	p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased

PERL_CONFIGURE=	yes

MAN3=		MooseX::TransactionalMethods.3 \
		MooseX::Meta::Method::Transactional.3

.include <bsd.port.mk>
