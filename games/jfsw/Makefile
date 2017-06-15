# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jfsw
PORTVERSION=	20131019
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/jonof/${PORTNAME}/archive/${JFSW_COMMIT}.tar.gz?dummy=/ \
		https://github.com/jonof/jfbuild/archive/${JFBUILD_COMMIT}.tar.gz?dummy=/ \
		https://github.com/jonof/jfaudiolib/archive/${JFAUDIO_COMMIT}.tar.gz?dummy=/ \
		https://github.com/jonof/jfmact/archive/${JFMACT_COMMIT}.tar.gz?dummy=/
DISTFILES=	${PORTNAME}-${JFSW_COMMIT}.tar.gz \
		jfbuild-${JFBUILD_COMMIT}.tar.gz \
		jfaudiolib-${JFAUDIO_COMMIT}.tar.gz \
		jfmact-${JFMACT_COMMIT}.tar.gz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Jonathon Fowler's Shadow Warrior Port

LICENSE=	GPLv2 BuildLic
LICENSE_COMB=	multi
LICENSE_NAME_BuildLic=	Build source code license
LICENSE_FILE_BuildLic=	${WRKSRC}/jfbuild/buildlic.txt
LICENSE_PERMS_BuildLic=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

JFSW_COMMIT=	5cff6a81708ff053b569ba4400fba073afe207fe
JFBUILD_COMMIT=	a73583184aca466cebde152db2ce1020591d7049
JFAUDIO_COMMIT=	a39ccf5e95961952d27754a255940be1d76ce85e
JFMACT_COMMIT=	b1071da75cd465f59257240e5dbc60a014580190

USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl

USES=		alias dos2unix gmake pkgconfig:build
DOS2UNIX_REGEX=	.*(\.(c|h)|Makefile)(\.deps)?

NO_CDROM=	Must be distributed only through the Internet and free of charge

WRKSRC=	${WRKDIR}/${PORTNAME}-${JFSW_COMMIT}
MAKE_ENV+=	DATADIR="${DATADIR}" \
		NOASM=1 \
		LINKED_GTK=1

SUB_FILES=	pkg-message

PORTDOCS=	readme.txt releasenotes.html

post-extract:
	@(cd ${WRKSRC} && \
		${RMDIR} jfbuild jfaudiolib jfmact && \
		${LN} -sf ${WRKDIR}/jfbuild-${JFBUILD_COMMIT} jfbuild && \
		${LN} -sf ${WRKDIR}/jfaudiolib-${JFAUDIO_COMMIT} jfaudiolib && \
		${LN} -sf ${WRKDIR}/jfmact-${JFMACT_COMMIT} jfmact)

post-patch:
	@${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/jfbuild/Makefile
	@${REINPLACE_CMD} 's|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/jfbuild/Makefile.shared
	@${REINPLACE_CMD} 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/jfaudiolib/src/driver_fluidsynth.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sw ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-build
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
