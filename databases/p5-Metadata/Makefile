# New ports collection makefile for:	Metadata
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Metadata
PORTVERSION=	0.24
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Metadata
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Perl implementation of Dublin Core compatible metadata

BUILD_DEPENDS=	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Metadata::Base.3 \
	Metadata::HTTP.3 \
	Metadata::IAFA.3 \
	Metadata::SOIF.3

.include <bsd.port.mk>
