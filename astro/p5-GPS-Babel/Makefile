# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	GPS-Babel
PORTVERSION=	0.11
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to gpsbabel

BUILD_DEPENDS=	p5-Geo-Gpx>=0.25:${PORTSDIR}/graphics/p5-Geo-Gpx \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS=	p5-Geo-Gpx>=0.25:${PORTSDIR}/graphics/p5-Geo-Gpx \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which

USES=		perl5
USE_PERL5=	configure

MAN3=	GPS::Babel.3

.include <bsd.port.mk>
