# ex:ts=8
# Ports collection makefile for:	Astro-DSS
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-DSS
PORTVERSION=	1.6.1
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.estar.org.uk/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OO interface to the 1st and 2nd Digital Sky Surveys

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Astro::DSS.3

.include <bsd.port.mk>
