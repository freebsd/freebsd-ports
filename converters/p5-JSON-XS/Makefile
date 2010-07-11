# New ports collection makefile for:	JSON-XS
# Date created:		25 Mar 2007
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-XS
PORTVERSION=	2.29
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

RUN_DEPENDS=	p5-common-sense>0:${PORTSDIR}/devel/p5-common-sense
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+
MAN1=		json_xs.1
MAN3=		JSON::XS.3 JSON::XS::Boolean.3

.include <bsd.port.mk>
