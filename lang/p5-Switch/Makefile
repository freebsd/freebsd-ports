# New ports collection makefile for:	lang/p5-Switch
# Date created:				26 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Switch
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RG/RGARCIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Switch - A switch statement for Perl

BUILD_DEPENDS=	p5-Filter>0:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Switch.3

.include <bsd.port.mk>
