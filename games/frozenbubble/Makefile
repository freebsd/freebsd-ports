# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	frozen-bubble
DISTVERSION=	2.2.1-beta1
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

LICENSE=	GPLv2

BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS=	p5-SDL>=2.511:${PORTSDIR}/devel/p5-SDL \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-IPC-System-Simple>=0:${PORTSDIR}/devel/p5-IPC-System-Simple \
		p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-Alien-SDL>=1.413:${PORTSDIR}/devel/p5-Alien-SDL

USES=		perl5 pkgconfig
USE_BZIP2=	yes
USE_PERL5=	modbuild
USE_SDL=	mixer pango sdl ttf

.include <bsd.port.mk>
