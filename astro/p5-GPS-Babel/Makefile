# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	GPS-Babel
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to gpsbabel

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0.05:sysutils/p5-File-Which \
		p5-Geo-Gpx>=0.25:graphics/p5-Geo-Gpx

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
