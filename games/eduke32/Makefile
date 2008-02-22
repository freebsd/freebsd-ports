# New ports collection makefile for:	eduke32
# Date Created:				1 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20080206
CATEGORIES=	games
MASTER_SITES=	http://wiki.eduke32.com/stuff/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olivier@gid0.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_src_${PORTVERSION}/${PORTNAME}

OPTIONS=	MIDI "Enable MIDI support" on

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

.if !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
.endif

post-patch:
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -Ee 's|^(NOASM =).*|\1 1|' ${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -Ee \
		's|^(CC=).*|\1${CC}|; \
		 s|^(CXX=).*|\1${CXX}|; \
		 s|/usr/X11R6|${X11BASE}|; \
		 s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/../build/Makefile \
		${WRKSRC}/../build/Makefile.shared
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
