# Created by: alepulver
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20110627
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${PORTVERSION}-${SVNREVISION}/ \
		http://dukeworld.duke4.net/eduke32/synthesis/old/${PORTVERSION}-${SVNREVISION}/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}

MAINTAINER=	olivier@gid0.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GNU.TXT

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USES=		gmake
USE_CSTD=	gnu89
USE_BZIP2=	yes
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	1923

OPTIONS_DEFINE=	MIDI TIMIDITYPLUS VORBIS
MIDI_DESC=	Original MIDI music support
TIMIDITYPLUS_DESC=	Use Timidity++ instead of Timidity

OPTIONS_DEFAULT=	MIDI VORBIS

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MMIDI}
.if ${PORT_OPTIONS:MTIMIDITYPLUS}
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.else
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
.endif
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
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
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/samples/*.sample ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
. for f in cfg map m32 txt
	${INSTALL_DATA} ${WRKSRC}/samples/*.${f} ${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.post.mk>
