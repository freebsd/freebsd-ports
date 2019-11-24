# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Image-Sane
PORTVERSION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Perl extension for the SANE (Scanner Access Now Easy) Project

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig
RUN_DEPENDS=	p5-Exception-Class>=1.43:devel/p5-Exception-Class \
		p5-Try-Tiny>=0.28:lang/p5-Try-Tiny
LIB_DEPENDS=	libsane.so:graphics/sane-backends

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
