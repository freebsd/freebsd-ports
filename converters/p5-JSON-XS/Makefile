# Created by: Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-XS
PORTVERSION=	3.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Types-Serialiser>=0:${PORTSDIR}/devel/p5-Types-Serialiser \
		p5-common-sense>0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
