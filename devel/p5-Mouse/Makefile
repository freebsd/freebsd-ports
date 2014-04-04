# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mouse
PORTVERSION=	2.1.1
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose minus the antlers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build-XSUtil>=0:${PORTSDIR}/devel/p5-Module-Build-XSUtil
TEST_DEPENDS=	p5-Declare-Constraints-Simple>=0:${PORTSDIR}/devel/p5-Declare-Constraints-Simple \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Locale-US>=0:${PORTSDIR}/misc/p5-Locale-US \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception-LessClever>=0:${PORTSDIR}/devel/p5-Test-Exception-LessClever \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-LeakTrace>=0:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=3.16:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
