# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>

PORTNAME=	jfsw
PORTVERSION=	20210130
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Jonathon Fowler's Shadow Warrior Port

# Must be distributed only through the Internet and free of charge
LICENSE=	GPLv2 BuildLic
LICENSE_COMB=	multi
LICENSE_NAME_BuildLic=	Build source code license
LICENSE_FILE_BuildLic=	${WRKSRC}/jfbuild/buildlic.txt
LICENSE_PERMS_BuildLic=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libfluidsynth.so:audio/fluidsynth

USES=		alias compiler:c++11-lang dos2unix gl gmake gnome \
		perl5 pkgconfig:build sdl
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer2 sdl2
USE_PERL5=	build

DOS2UNIX_REGEX=	.*(\.(c|h)|Makefile)(\.deps)?

USE_GITHUB=	yes
GH_ACCOUNT=	jonof
GH_PROJECT=	jfbuild:build jfaudiolib:audio jfmact:mact
# See GH listing to get current (tested) submodule hashes:
# https://github.com/jonof/jfsw
GH_TAGNAME=	c434002 \
		ed8c505:build \
		0b82be9:audio \
		1149eb1:mact
GH_SUBDIR=	jfbuild:build jfaudiolib:audio jfmact:mact

MAKE_ENV+=	DATADIR="${DATADIR}"

SUB_FILES=	pkg-message

PORTDOCS=	README.md releasenotes.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/jfbuild/Makefile
	@${REINPLACE_CMD} 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/jfaudiolib/src/driver_fluidsynth.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sw ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-build
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
