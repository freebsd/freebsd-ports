# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Luka
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Exception handling and reporting framework

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Std>=0:devel/p5-Class-Std \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles \
		p5-Error>=0:lang/p5-Error \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Mail-SendEasy>=0:mail/p5-Mail-SendEasy \
		p5-Sub-Uplevel>=0:devel/p5-Sub-Uplevel \
		p5-Sys-Hostname-Long>=0:sysutils/p5-Sys-Hostname-Long \
		p5-What>=0:net/p5-What
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
