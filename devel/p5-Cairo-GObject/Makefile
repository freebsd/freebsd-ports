# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Cairo-GObject
PORTVERSION=	1.004
PORTREVISION=	2
CATEGORIES=	devel graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XAOC
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate Cairo into the Glib type system

LICENSE=	LGPL21

BUILD_DEPENDS=	cairo>=1.10.0:graphics/cairo \
		p5-Cairo>=1.080:graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0.200:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.224:devel/p5-Glib2
RUN_DEPENDS=	cairo>=1.10.0:graphics/cairo \
		p5-Cairo>=1.080:graphics/p5-Cairo \
		p5-Glib2>=1.224:devel/p5-Glib2

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cairo/GObject/GObject.so

.include <bsd.port.mk>
