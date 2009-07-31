# New ports collection makefile for:	upp
# Date created:				February, 8th 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	upp
PORTVERSION=	2008.1
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_XORG=	xft
USE_GNOME=	gtk20
USE_GMAKE=	yes

ALL_TARGET=	theide

WRKSRC=	${WRKDIR}

INSTALL_DIRS=	bazaar examples reference tutorial uppsrc

OPTIONS=	SDL	"Install with SDL library" off \
		GL	"Install wiht OpenGL library" off \
		MYSQL	"Install with MySQL database" off \
		PGSQL	"Install with PostreSQL database" off

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif
.if defined(WITH_GL)
USE_GL=	gl
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/uppsrc/ide/Makefile
	@${REINPLACE_CMD} -e 's|CINC =(.*)|$1 ${PTHREAD_CFLAGS}|' ${WRKSRC}/uppsrc/ide/Makefile

post-build:
	@${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_BLITZ = \"0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_OPTIONS = \"-O2 -ffunction-sections\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "INCLUDE = \"${LOCALBASE}/include;${LOCALBASE}/include/freetype2;${LOCALBASE}/include/gtk-2.0;${LOCALBASE}/include/glib-2.0;${LOCALBASE}/include/cairo;${LOCALBASE}/include/pango-1.0;${LOCALBASE}/include/atk-1.0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "LIB = \"${LOCALBASE}/lib\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_HOST = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_OS = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_TRANSFER = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_MAP = \"\";" >> ${WRKSRC}/GCC.bm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/out/ide/GCC-FREEBSD-Gcc-Gui-Main-Shared/ide ${PREFIX}/bin/theide
	@${MKDIR} ${PREFIX}/share/upp
	@${INSTALL_DATA} ${WRKSRC}/GCC.bm ${PREFIX}/share/upp/GCC.bm
	@(cd ${WRKSRC} && for d in ${INSTALL_DIRS};do ${FIND} $$d \! -empty -type d -print|${SORT} -r>>dirs.txt;done;)
	@(cd ${WRKSRC} && for d in ${INSTALL_DIRS};do ${FIND} $$d -type f -print|${SORT}>>files.txt;done;)
	@for d in `${CAT} ${WRKSRC}/dirs.txt`;do ${MKDIR} ${PREFIX}/share/upp/$$d;done;
	@for f in `${CAT} ${WRKSRC}/files.txt`;do ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/upp/$$f;done;

post-install:
	@${ECHO_CMD} bin/theide > ${TMPPLIST}
	@${ECHO_CMD} share/upp/GCC.bm >> ${TMPPLIST}
	@for f in `${CAT} ${WRKSRC}/files.txt`;do ${ECHO_CMD} share/upp/$$f >> ${TMPPLIST};done;
	@for d in `${CAT} ${WRKSRC}/dirs.txt`;do ${ECHO_CMD} @dirrm share/upp/$$d >> ${TMPPLIST};done;
	@${ECHO_CMD} @dirrm share/upp >> ${TMPPLIST}
	@${RM} ${WRKSRC}/*.txt

.include <bsd.port.post.mk>
