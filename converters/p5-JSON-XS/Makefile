# Created by: Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-XS
PORTVERSION=	2.34
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

BUILD_DEPENDS=	p5-common-sense>0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PORTSCOUT=	skipv:2.232

.include <bsd.port.mk>
