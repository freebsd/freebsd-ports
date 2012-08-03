# New ports collection makefile for:	JSON-XS
# Date created:		25 Mar 2007
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-XS
PORTVERSION=	2.33
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

BUILD_DEPENDS=	p5-common-sense>0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		json_xs.1
MAN3=		JSON::XS.3 JSON::XS::Boolean.3

PORTSCOUT=	skipv:2.232

.include <bsd.port.mk>
