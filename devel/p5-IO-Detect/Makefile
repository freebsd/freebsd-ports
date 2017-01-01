# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Detect
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect if a given scalar is a filehandle

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-All>=0:devel/p5-IO-All \
		p5-Path-Class>=0:devel/p5-Path-Class

CONFLICTS_INSTALL=	p5-Scalar-Does-0.[1-9]*

DEPRECATED=	Use devel/p5-Scalar-Does instead
EXPIRATION_DATE=2017-01-31

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
