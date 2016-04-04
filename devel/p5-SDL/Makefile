# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	SDL
PORTVERSION=	2.540
PORTREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Perl Bindings for SDL

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Alien-SDL>=1.426:devel/p5-Alien-SDL
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libsmpeg.so:multimedia/smpeg
RUN_DEPENDS=	p5-Alien-SDL>=1.426:devel/p5-Alien-SDL \
		p5-Tie-Simple>=0:devel/p5-Tie-Simple

USES=		jpeg perl5
USE_GL=		glu
USE_PERL5=	modbuild
USE_SDL=	gfx image mixer pango sdl ttf

.include <bsd.port.mk>
