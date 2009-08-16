# New ports collection makefile for:	devel/p5-MooseX-Types-Path-Class
# Date created:				28 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Path-Class
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Path::Class type library for Moose

RUN_DEPENDS=	p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP \
		p5-Moose>=0.39:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::Types::Path::Class.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
