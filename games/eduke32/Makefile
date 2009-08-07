# New ports collection makefile for:	eduke32
# Date Created:				1 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20090313
DISTVERSION=	20090131
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/source_code/
DISTFILES=	${PORTNAME}_src_${DISTVERSION}${EXTRACT_SUFX}
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_src_${PORTVERSION}.diff

MAINTAINER=	olivier@gid0.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_src_${DISTVERSION}
PATCH_ARGS=	-d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_STRIP} -l

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
	@${REINPLACE_CMD} -e '/LIBS+= -lvorbis/d' ${WRKSRC}/Makefile
.endif
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -Ee 's|^(NOASM =).*|\1 1|' ${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -Ee \
		's|^(CC=).*|\1${CC}|; \
		 s|^(CXX=).*|\1${CXX}|; \
		 /debug=/d; \
		 s|/usr/X11R6|${LOCALBASE}|; \
		 s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/build/Makefile \
		${WRKSRC}/build/Makefile.shared
	@${REINPLACE_CMD} -e 's|LINUX|BSD|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/games/eduke32|${DN3DDIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/astub.c

do-install:
.for f in eduke32 mapster32
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
. for f in ChangeLog *.sample
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
