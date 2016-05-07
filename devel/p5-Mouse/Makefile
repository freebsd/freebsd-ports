# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mouse
PORTVERSION=	2.4.5
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SYOHEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose minus the antlers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build-XSUtil>=0:devel/p5-Module-Build-XSUtil
TEST_DEPENDS=	p5-Declare-Constraints-Simple>=0:devel/p5-Declare-Constraints-Simple \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Locale-US>=0:misc/p5-Locale-US \
		p5-Params-Coerce>=0:devel/p5-Params-Coerce \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Mouse/Mouse.so

.include <bsd.port.mk>
