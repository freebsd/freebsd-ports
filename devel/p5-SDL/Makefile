# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	SDL
PORTVERSION=	2.548
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Bindings for SDL

LICENSE=	GPLv2

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libsmpeg.so:multimedia/smpeg
RUN_DEPENDS=	p5-Alien-SDL>=1.446:devel/p5-Alien-SDL \
		p5-File-ShareDir>=1.0:devel/p5-File-ShareDir \
		p5-Tie-Simple>=0:devel/p5-Tie-Simple
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Test-Most>=0.21:devel/p5-Test-Most

USES=		gl jpeg perl5 sdl
USE_GL=		glu
USE_PERL5=	modbuild
USE_SDL=	gfx image mixer pango sdl ttf

.include <bsd.port.mk>
