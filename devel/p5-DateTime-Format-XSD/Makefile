# New ports collection makefile for:    DateTime-Format-XSD
# Date created:         29 oct 2009
# Whom:                 Sergey V. Dyatko <Sergey.Dyatko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-XSD
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Format DateTime according to xsd:dateTime

BUILD_DEPENDS=	${SITE_PERL}/DateTime/Format/ISO8601.pm:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601
RUN_DEPENDS=	${SITE_PERL}/DateTime/Format/ISO8601.pm:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::XSD.3

.include <bsd.port.mk>
