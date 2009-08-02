# New ports collection makefile for:	Config::ApacheFormat
# Date created:				26 Jul 2006
# Whom:					Martin Tournoij <carpetsmoker@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Config-ApacheFormat
PORTVERSION=	1.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse a configuration file in the same syntax as the Apache web server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/auto/Class/MethodMaker/MethodMaker.so:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/${PERL_ARCH}/auto/List/Util/Util.so:${PORTSDIR}/lang/p5-Scalar-List-Utils

PERL_CONFIGURE=	yes
MAN3=		Config::ApacheFormat.3

.include <bsd.port.mk>
