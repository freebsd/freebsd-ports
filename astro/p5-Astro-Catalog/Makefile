# ex:ts=8
# Ports collection makefile for:	Astro-Catalog
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-Catalog
PORTVERSION=	1.8.1
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.astro.ex.ac.uk/estar/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Astro::Catalog.3 \
	Astro::Catalog::GSC::Query.3 \
	Astro::Catalog::Star.3 \
	Astro::Catalog::USNOA2::Query.3

.include <bsd.port.mk>
