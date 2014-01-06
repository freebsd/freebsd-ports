# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Luka
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Exception handling and reporting framework

RUN_DEPENDS=	p5-Class-Std>=0:${PORTSDIR}/devel/p5-Class-Std \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Mail-SendEasy>=0:${PORTSDIR}/mail/p5-Mail-SendEasy \
		p5-Sub-Uplevel>=0:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-What>=0:${PORTSDIR}/net/p5-What
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
