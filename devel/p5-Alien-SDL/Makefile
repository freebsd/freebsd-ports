# $FreeBSD$

PORTNAME=	Alien-SDL
PORTVERSION=	1.440
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Detect and get configuration setting for SDL

LICENSE=	GPLv2

BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Text-Patch>=1.4:${PORTSDIR}/textproc/p5-Text-Patch
RUN_DEPENDS=	p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	modbuild
USE_SDL=	gfx image mixer pango sdl ttf
CONFIGURE_ARGS=	--with-sdl-config=${SDL_CONFIG}

.include <bsd.port.mk>
