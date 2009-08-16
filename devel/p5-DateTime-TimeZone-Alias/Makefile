# New ports collection makefile for:	p5-DateTime-TimeZone-Alias
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-TimeZone-Alias
PORTVERSION=	0.05.01
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create aliases for DateTime timezones

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/DateTime/TimeZone.pm:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime

PERL_MODBUILD=	yes

MAN3=		DateTime::TimeZone::Alias.3

.include <bsd.port.mk>
