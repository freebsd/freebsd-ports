# New ports collection makefile for:	p5-DateTime-TimeZone
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-TimeZone
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net
COMMENT=	Time zone object base class and factory

BUILD_DEPENDS=	${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::TimeZone.3 \
		DateTime::TimeZone::UTC.3 \
		DateTime::TimeZoneCatalog.3 \
		DateTime::TimeZone::OlsonDB.3 \
		DateTime::TimeZone::Floating.3

.include <bsd.port.mk>
