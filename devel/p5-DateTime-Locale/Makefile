# New ports collection makefile for:	p5-DateTime-Locale
# Date created:	   30 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Locale
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Localization support for DateTime

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate

PERL_MODBUILD=	yes

MAN3=		DateTime::Locale.3 DateTime::Locale::Alias::ISO639_2.3 \
		DateTime::Locale::Base.3 DateTime::LocaleCatalog.3

.include <bsd.port.mk>
