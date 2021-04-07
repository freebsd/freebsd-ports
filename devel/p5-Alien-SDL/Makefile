PORTNAME=	Alien-SDL
PORTVERSION=	1.446
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Detect and get configuration setting for SDL

LICENSE=	GPLv1 ART10
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Text-Patch>=1.4:textproc/p5-Text-Patch
RUN_DEPENDS=	p5-Archive-Extract>=0:archivers/p5-Archive-Extract \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Capture-Tiny>=0:devel/p5-Capture-Tiny

USES=		perl5 sdl
USE_PERL5=	modbuild
USE_SDL=	gfx image mixer pango sdl ttf
CONFIGURE_ARGS=	--with-sdl-config=${SDL_CONFIG}

.include <bsd.port.mk>
