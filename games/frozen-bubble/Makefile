# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	frozen-bubble
DISTVERSION=	2.213.g${SNAPDATE}
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot frozen bubbles to build groups of the same color

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-File-Slurp>=0:devel/p5-File-Slurp
RUN_DEPENDS=	p5-SDL>=2.511:devel/p5-SDL \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Locale-Maketext-Simple>=0:devel/p5-Locale-Maketext-Simple \
		p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-Alien-SDL>=1.413:devel/p5-Alien-SDL

USES=		compiler:features gettext-runtime gnome perl5 pkgconfig sdl \
		tar:bzip2
USE_GNOME=	glib20
USE_PERL5=	modbuild
USE_SDL=	mixer pango sdl ttf

USE_GITHUB=	yes
GH_ACCOUNT=	kthakore
GH_TAGNAME=	d6a0291
SNAPDATE=	20170702

DESKTOP_ENTRIES=	"Frozen Bubble" "" \
			"${PREFIX}/share/pixmaps/frozen-bubble.png" \
			"${PORTNAME}" "ArcadeGame;Game;" true

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE:Mclang}
CFLAGS+=	-Qunused-arguments
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/icons/frozen-bubble-icon-64x64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/frozen-bubble.png

.include <bsd.port.post.mk>
