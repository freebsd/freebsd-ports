# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-MaybeXS
PORTVERSION=	1.003008
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cpanel-JSON-XS>=2.3310:converters/p5-Cpanel-JSON-XS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Test-Without-Module>=0.17:devel/p5-Test-Without-Module

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
