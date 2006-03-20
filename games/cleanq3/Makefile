# New ports collection makefile for:	CleanQ3
# Date created:				17 Mar 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cleanq3
PORTVERSION=	0.5.2
CATEGORIES=	games
MASTER_SITES=	http://tremor.quakedev.com/
DISTNAME=	CleanQ3_v${PORTVERSION}-srcbin

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cleaned up copy of the original Quake III Arena source code

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_ZIP=	yes
USE_PERL5_BUILD=yes
USE_DOS2UNIX=	yes
USE_GCC=	3.2+
USE_GL=		yes

WRKSRC=		${WRKDIR}/CleanQ3
INSTDIR=	${WRKSRC}/code/install

PLIST_FILES=	bin/cleanq3 bin/cleanq3ded \
		lib/cleanq3/baseq3/cgame.so \
		lib/cleanq3/baseq3/qagame.so \
		lib/cleanq3/baseq3/ui.so \
		lib/cleanq3/missionpack/cgame.so \
		lib/cleanq3/missionpack/qagame.so \
		lib/cleanq3/missionpack/ui.so
PLIST_DIRS=	lib/cleanq3/baseq3 lib/cleanq3/missionpack lib/cleanq3

OPTIONS=	OPTIMIZED_CFLAGS "Build with extra optimization options" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS=		-O6 -fomit-frame-pointer -ffast-math -falign-loops=2 -falign-jumps=2 \
		-falign-functions=2 -fno-strict-aliasing -fstrength-reduce
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; s|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/code/Construct ${WRKSRC}/code/unix/Conscript-client
	${REINPLACE_CMD} -e 's|-ldl || ; s|i386\.so|\.so|' \
		${WRKSRC}/code/cgame/Conscript \
		${WRKSRC}/code/game/Conscript ${WRKSRC}/code/q3_ui/Conscript \
		${WRKSRC}/code/unix/Conscript-dedicated \
		${WRKSRC}/code/ui/Conscript
	${REINPLACE_CMD} -e 's|%%Q3DIR%%|"${Q3DIR}"|' \
		${WRKSRC}/code/unix/unix_shared.c
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/code/unix/unix_main.c
	${REINPLACE_CMD} -e 's|botlib.log|/dev/null|' \
		${WRKSRC}/code/botlib/be_interface.c

do-build:
	cd ${WRKSRC}/code && ${MAKE_ENV} ${PERL} unix/cons

do-install:
	${INSTALL_PROGRAM} ${INSTDIR}/linuxquake3 ${PREFIX}/bin/cleanq3
	${INSTALL_PROGRAM} ${INSTDIR}/linuxq3ded ${PREFIX}/bin/cleanq3ded
.for d in baseq3 missionpack
	@${MKDIR} ${PREFIX}/lib/cleanq3/${d}
	${INSTALL_PROGRAM} ${INSTDIR}/${d}/cgame.so ${PREFIX}/lib/cleanq3/${d}
	${INSTALL_PROGRAM} ${INSTDIR}/${d}/qagame.so ${PREFIX}/lib/cleanq3/${d}
	${INSTALL_PROGRAM} ${INSTDIR}/${d}/ui.so ${PREFIX}/lib/cleanq3/${d}
.endfor

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.post.mk>
