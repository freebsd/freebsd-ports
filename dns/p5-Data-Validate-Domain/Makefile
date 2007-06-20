# New ports collection makefile for:	dns/p5-Data-Validate-Domain
# Date created:				30 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate-Domain
PORTVERSION=	0.08
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::Validate::Domain - domain validation methods

BUILD_DEPENDS=	${SITE_PERL}/Net/Domain/TLD.pm:${PORTSDIR}/dns/p5-Net-Domain-TLD
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::Validate::Domain.3

.include <bsd.port.mk>
