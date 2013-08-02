# New ports collection makefile for:	Metadata
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Metadata
PORTVERSION=	0.24
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl implementation of Dublin Core compatible metadata

BUILD_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Metadata::Base.3 \
	Metadata::HTTP.3 \
	Metadata::IAFA.3 \
	Metadata::SOIF.3

.include <bsd.port.mk>
