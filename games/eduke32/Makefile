# Created by: alepulver
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20110627
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${PORTVERSION}-${SVNREVISION}/ \
		http://dukeworld.duke4.net/eduke32/synthesis/old/${PORTVERSION}-${SVNREVISION}/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GNU.TXT

USES=		execinfo gmake tar:bzip2
USE_GCC=	any
USE_CSTD=	gnu89
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	1923

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTDOCS=	*
PORTEXAMPLES=	*

BROKEN_sparc64=		Does not compile on sparc64

OPTIONS_DEFINE=	VORBIS
OPTIONS_RADIO=	MIDI
OPTIONS_RADIO_MIDI=	TIMIDITY TIMIDITYPLUS
OPTIONS_DEFAULT=TIMIDITY VORBIS

MIDI_DESC=	MIDI music support
TIMIDITY_DESC=	Use Timidity for music support
TIMIDITY_RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity
TIMIDITYPLUS_DESC=	Use Timidity++ for music support
TIMIDITYPLUS_RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity++
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

post-patch:
.if ! ${PORT_OPTIONS:MVORBIS}
	@${REINPLACE_CMD} '/+= -lvorbis/d' ${WRKSRC}/Makefile
.endif
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} '/^NOASM =/s/0/1/' ${WRKSRC}/Makefile.common
.endif
	@${REINPLACE_CMD} -e '/^CC=/s/gcc/${CC}/' -e '/^CXX=/s/g++/${CXX}/' \
		${WRKSRC}/Makefile.common
	@${REINPLACE_CMD} 's/ \$$(ARCH)//' ${WRKSRC}/Makefile \
		${WRKSRC}/build/Makefile
	@${REINPLACE_CMD} -Ee '/^ifeq/s/LINUX/BSD/' \
		-e 's/(\+= -lvorbisfile)/\1 -lexecinfo/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' -e 's/ -ldl//' \
		${WRKSRC}/build/Makefile
	@${REINPLACE_CMD} -E 's|(SDLCONFIG[[:space:]]*=).*|\1${SDL_CONFIG}|' \
		${WRKSRC}/build/Makefile.shared
	@${REINPLACE_CMD} 's|/usr/share/games/eduke32|${DN3DDIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/astub.c
	@${REINPLACE_CMD} -E 's|(-DHAVE_VORBIS)|-I${LOCALBASE}/include \1|' \
		${WRKSRC}/source/jaudiolib/Makefile

do-install:
.for f in eduke32 mapster32
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/samples/*.sample ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for f in cfg map m32 txt
	${INSTALL_DATA} ${WRKSRC}/samples/*.${f} ${STAGEDIR}${EXAMPLESDIR}
. endfor

.include <bsd.port.post.mk>
