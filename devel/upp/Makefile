# New ports collection makefile for:	upp
# Date created:				February, 8th 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	upp
PORTVERSION=	2007.1
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft\
		freetype.9:${PORTSDIR}/print/freetype2\
		expat.6:${PORTSDIR}/textproc/expat2\
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XLIB=	yes

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif

WRKSRC=	${WRKDIR}

INSTALL_DIRS=	Common examples reference tutorial uppsrc

pre-everything::
.if !defined(WITH_SDL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITH_SDL to install SDL library for running SDL example."
	@${ECHO_MSG} ""
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|C_FLAGS|' ${WRKSRC}/uppsrc/ide/Makefile

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/uppsrc/ide/Makefile
	@${REINPLACE_CMD} -e 's|-ldl|-lfreetype|g' ${WRKSRC}/uppsrc/ide/Makefile
	@${REINPLACE_CMD} -e 's|CINC =(.*)|$1 ${PTHREAD_CFLAGS}|' ${WRKSRC}/uppsrc/ide/Makefile

post-build:
	@${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_BLITZ = \"0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_LINKMODE = \"1\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "RELEASE_OPTIONS = \"-O3 -ffunction-sections\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "INCLUDE = \"${X11BASE}/include;${LOCALBASE}/include;${LOCALBASE}/include/freetype2;${LOCALBASE}/include/gtk-2.0;${LOCALBASE}/include/glib-2.0;${LOCALBASE}/include/cairo;${LOCALBASE}/include/pango-1.0;${LOCALBASE}/include/atk-1.0\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "LIB = \"${X11BASE}/lib;${LOCALBASE}/lib\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_HOST = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_OS = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_TRANSFER = \"\";" >> ${WRKSRC}/GCC.bm
	@${ECHO_CMD} "REMOTE_MAP = \"\";" >> ${WRKSRC}/GCC.bm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/out/ide/GCC-Gcc-Gui-Linux-Main-Shared/ide ${PREFIX}/bin/theide
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

.include <bsd.port.mk>
