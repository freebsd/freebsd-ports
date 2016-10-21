# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	frozen-bubble
DISTVERSION=	2.2.1-beta1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

LICENSE=	GPLv2

BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-File-Slurp>=0:devel/p5-File-Slurp
RUN_DEPENDS=	p5-SDL>=2.511:devel/p5-SDL \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Locale-Maketext-Simple>=0:devel/p5-Locale-Maketext-Simple \
		p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-Alien-SDL>=1.413:devel/p5-Alien-SDL

USES=		compiler:features perl5 pkgconfig tar:bzip2
USE_PERL5=	modbuild
USE_SDL=	mixer pango sdl ttf

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE:Mclang}
CFLAGS+=	-Qunused-arguments
.endif

DESKTOP_ENTRIES=	"Frozen Bubble" "" \
			"${PREFIX}/share/pixmaps/frozen-bubble.png" \
			"${PORTNAME}" "ArcadeGame;Game;" true

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/icons/frozen-bubble-icon-64x64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/frozen-bubble.png

.include <bsd.port.post.mk>
