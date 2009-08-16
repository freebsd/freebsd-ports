# New ports collection makefile for:	devel/p5-MooseX-Async
# Date created:				27 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Async
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Orphanange of Asynchronous Love Children

RUN_DEPENDS=	p5-Moose>=0.56:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.13:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::Async.3 \
	MooseX::Async::Meta::Class.3 \
	MooseX::Async::Meta::Method::State.3

post-extract:
	@${RM} -f ${WRKSRC}/lib/MooseX/._Async.pm

.include <bsd.port.mk>
