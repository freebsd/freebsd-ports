# New ports collection makefile for:	MouseX::Types
# Date created:		20 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Types
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to organize your Mouse types in libraries

RUN_DEPENDS=	\
	p5-Any-Moose>=0.15:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Mouse>=0.77:${PORTSDIR}/devel/p5-Mouse
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MouseX::Types.3 \
		MouseX::Types::Moose.3 \
		MouseX::Types::Mouse.3

.include <bsd.port.mk>
