# ex:ts=8
# Ports collection makefile for:	Astro-Catalog
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-Catalog
PORTVERSION=	2.1.3
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.estar.org.uk/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic stellar catalogue object

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	catalogs.1 supercosmos.1 finder.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Astro::Catalog.3 \
	Astro::Catalog::GSC::Query.3 \
	Astro::Catalog::Star.3 \
	Astro::Catalog::SuperCOSMOS::Query.3 \
	Astro::Catalog::USNOA2::Query.3

.include <bsd.port.mk>
