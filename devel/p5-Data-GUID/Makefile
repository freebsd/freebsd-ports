# New ports collection makefile for:	devel/p5-Data-GUID
# Date created:				05 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-GUID
PORTVERSION=	0.045
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Generate globally unique identifiers

BUILD_DEPENDS=	${SITE_PERL}/Sub/Install.pm:${PORTSDIR}/devel/p5-Sub-Install \
		${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Data-UUID>=1.148:${PORTSDIR}/devel/p5-Data-UUID
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Data::GUID.3

.include <bsd.port.mk>
