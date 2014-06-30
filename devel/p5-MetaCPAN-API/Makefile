# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MetaCPAN-API
PORTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Comprehensive, DWIM-featured API to MetaCPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-TinyMocker>=0:${PORTSDIR}/devel/p5-Test-TinyMocker

DEPRECATED=	Use devel/p5-MetaCPAN-Client instead
EXPIRATION_DATE=2014-07-27

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
