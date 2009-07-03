# New ports collection makefile for:	p5-DateTime-Format-Natural
# Date created:				22 Jul 2008
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Natural
PORTVERSION=	0.77
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Create machine readable date/time with natural parsing logic

BUILD_DEPENDS=	\
		${SITE_PERL}/boolean.pm:${PORTSDIR}/devel/p5-boolean \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		dateparse.1

MAN3=		DateTime::Format::Natural.3 \
  			DateTime::Format::Natural::Base.3 \
  			DateTime::Format::Natural::Compat.3 \
  			DateTime::Format::Natural::Helpers.3 \
			DateTime::Format::Natural::Lang::Base.3 \
			DateTime::Format::Natural::Lang::EN.3

.include <bsd.port.mk>
