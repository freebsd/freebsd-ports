# New ports collection makefile for:	eduke32
# Date Created:				1 Aug 2006
# Whom:					alepulver
#
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

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	1923

OPTIONS=	MIDI		"Enable original MIDI music support"	On \
		TIMIDITYPLUS	"Use Timidity++ instead of Timidity"	Off \
		VORBIS		"Enable Ogg Vorbis music files support"	On

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if defined(WITH_MIDI)
.if defined(WITH_TIMIDITYPLUS)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.else
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
.endif
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

post-patch:
.if defined(WITHOUT_VORBIS)
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/samples/*.sample ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
. for f in cfg map m32 txt
	${INSTALL_DATA} ${WRKSRC}/samples/*.${f} ${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.post.mk>
