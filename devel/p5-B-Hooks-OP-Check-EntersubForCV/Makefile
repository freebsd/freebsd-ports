# New ports collection makefile for:	B::Hooks::OP::Check::EntersubForCV
# Date created:		22 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-OP-Check-EntersubForCV
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to invoke callback on construction of entersub OPs

RUN_DEPENDS=	\
	p5-B-Hooks-OP-Check>=0.19:${PORTSDIR}/devel/p5-B-Hooks-OP-Check \
	p5-B-Utils>0:${PORTSDIR}/devel/p5-B-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	B::Hooks::OP::Check::EntersubForCV.3

.include <bsd.port.mk>
