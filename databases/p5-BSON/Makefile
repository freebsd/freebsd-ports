# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSON
PORTVERSION=	0.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MINIMAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl implementation of MongoDB BSON serialization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-Int64>=0:${PORTSDIR}/math/p5-Math-Int64 \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5

MAN3=		BSON.3 \
		BSON::Binary.3 \
		BSON::Bool.3 \
		BSON::Code.3 \
		BSON::MaxKey.3 \
		BSON::MinKey.3 \
		BSON::ObjectId.3 \
		BSON::String.3 \
		BSON::Time.3 \
		BSON::Timestamp.3

.include <bsd.port.mk>
