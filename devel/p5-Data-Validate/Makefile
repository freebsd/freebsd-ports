# New ports collection makefile for:	devel/p5-Data-Validate
# Date created:				06 August 2007
# Whom:					Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Common data validation methods

BUILD_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt

PERL_CONFIGURE=	yes

MAN3=	Data::Validate.3

.include <bsd.port.mk>
