# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jfsw
PORTVERSION=	20200116
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Jonathon Fowler's Shadow Warrior Port

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
GH_TAGNAME=	282b31a2335b2b5cac91d30044ff6b92053d1094 \
		31e2b842629f52227fd1291f5228a806704b0cbc:build \
		8e28fe3bc41bf809391461697cd0ecb7027cb7f6:audio \
		dbbf346d78334c6907ad9014958305309d4df7a0:mact
GH_SUBDIR=	jfbuild:build jfaudiolib:audio jfmact:mact

NO_CDROM=	Must be distributed only through the Internet and free of charge

MAKE_ENV+=	DATADIR="${DATADIR}"

SUB_FILES=	pkg-message

PORTDOCS=	readme.txt releasenotes.html

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
