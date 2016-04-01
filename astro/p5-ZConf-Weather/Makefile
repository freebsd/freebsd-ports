# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-Weather
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	ZConf module to assist with fetching/printing weather information

BUILD_DEPENDS=	p5-ZConf>=6.1.0:net/p5-ZConf \
		p5-Text-NeatTemplate>=0.10.01:textproc/p5-Text-NeatTemplate \
		p5-Weather-Underground>=3.03:astro/p5-Weather-Underground
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/zcweather
USE_PERL5=	configure

.include <bsd.port.mk>
