# New ports collection makefile for:	lang/p5-Switch
# Date created:				26 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Switch
PORTVERSION=	2.10
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RG/RGARCIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Switch - A switch statement for Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter \
		${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Switch.3

.include <bsd.port.mk>
