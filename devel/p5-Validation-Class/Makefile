# New ports collection makefile for:	Validation::Class
# Date created:		27 Jul 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Validation-Class
PORTVERSION=	1.112570
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for any application

RUN_DEPENDS=	\
	p5-Array-Unique>0:${PORTSDIR}/devel/p5-Array-Unique \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Validation::Class.3

.include <bsd.port.mk>
