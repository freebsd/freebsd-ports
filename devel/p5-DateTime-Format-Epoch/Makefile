# New ports collection makefile for:	p5-DateTime-Format-Epoch
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Epoch
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net
COMMENT=	Convert DateTimes to/from epoch seconds

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Epoch.3 DateTime::Format::Epoch::MacOS.3 \
		DateTime::Format::Epoch::TAI64.3 DateTime::Format::Epoch::Unix.3

.include <bsd.port.mk>
