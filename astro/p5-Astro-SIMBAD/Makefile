# Created by: ijliao
# $FreeBSD$

PORTNAME=	Astro-SIMBAD
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO Perl interface to the SIMBAD astronomical database

LICENSE=	GPLv2+

BUILD_DEPENDS=	p5-HTML-Parser>=3.36:www/p5-HTML-Parser \
		p5-HTML-Tree>=3.17:www/p5-HTML-Tree \
		p5-libwww>=5.53:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
