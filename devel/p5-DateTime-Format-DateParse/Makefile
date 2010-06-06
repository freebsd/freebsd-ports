# New ports collection makefile for:	p5-DateTime-Format-DateParse
# Date created:				21 Jun 2008
# Whom:					svysh@pn.sinp.msu.ru
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-DateParse
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	This module is a compatibility wrapper around Date::Parse

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

PERL_MODBUILD=	yes

MAN3=	DateTime::Format::DateParse.3

.include <bsd.port.mk>
