# New ports collection makefile for:	upp
# Date created:				February, 8th 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	upp
PORTVERSION=	605
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	m.sund@arcor.de
COMMENT=	Ultimate++, a BSD-licensed, cross-platform, C/C++ RAD suite

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft\
		freetype.9:${PORTSDIR}/print/freetype2\
		expat.6:${PORTSDIR}/textproc/expat2

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XLIB=	yes

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif

EXTRACT_AFTER_ARGS=	"-d${DISTNAME}"

BUILD_WRKSRC=	${WRKSRC}/uppsrc/ide

INSTALL_DIRS=	Common examples reference uppsrc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Ultimate++ is not supported on FreeBSD 4.x
.endif

pre-everything::
.if !defined(WITH_SDL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITH_SDL to install SDL library for running SDL example."
	@${ECHO_MSG} ""
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|C_FLAGS|' ${BUILD_WRKSRC}/Makefile

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${BUILD_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-ldl|-lfreetype|g' ${BUILD_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CINC =(.*)|$1 ${PTHREAD_CFLAGS}|' ${BUILD_WRKSRC}/Makefile

post-build:
	@${RM} ${BUILD_WRKSRC}/Makefile.*
	@${ECHO_CMD} "BUILDER = \"GCC\"" > ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "COMPILER = \"\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "DEBUG_INFO = \"0\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "DEBUG_BLITZ = \"1\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "DEBUG_LINKMODE = \"0\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "DEBUG_OPTIONS = \"-O0\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "RELEASE_BLITZ = \"1\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "RELEASE_LINKMODE = \"0\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "RELEASE_OPTIONS = \"-O2\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "RELEASE_SIZE_OPTIONS = \"-O1\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "DEBUGGER = \"gdb\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "PATH = \"\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "INCLUDE = \"${X11BASE}/include;${LOCALBASE}/include;${LOCALBASE}/include/freetype2\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "LIB = \"${X11BASE}/lib;${LOCALBASE}/lib\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "REMOTE_HOST = \"\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "REMOTE_OS = \"FREEBSD\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "REMOTE_TRANSFER = \"\";" >> ${WRKSRC}/GCC32.bm
	@${ECHO_CMD} "REMOTE_MAP = \"\";" >> ${WRKSRC}/GCC32.bm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ide ${PREFIX}/bin/theide
	@${MKDIR} ${PREFIX}/share/upp
	@${INSTALL_DATA} ${WRKSRC}/GCC32.bm ${PREFIX}/share/upp/GCC32.bm
	@(cd ${WRKSRC} && for d in ${INSTALL_DIRS};do ${FIND} $$d \! -empty -type d -print|${SORT} -r>>dirs.txt;done;)
	@(cd ${WRKSRC} && for d in ${INSTALL_DIRS};do ${FIND} $$d -type f -print|${SORT}>>files.txt;done;)
	@for d in `${CAT} ${WRKSRC}/dirs.txt`;do ${MKDIR} ${PREFIX}/share/upp/$$d;done;
	@for f in `${CAT} ${WRKSRC}/files.txt`;do ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/upp/$$f;done;

post-install:
	@${ECHO_CMD} bin/theide > ${TMPPLIST}
	@${ECHO_CMD} share/upp/GCC32.bm >> ${TMPPLIST}
	@for f in `${CAT} ${WRKSRC}/files.txt`;do ${ECHO_CMD} share/upp/$$f >> ${TMPPLIST};done;
	@for d in `${CAT} ${WRKSRC}/dirs.txt`;do ${ECHO_CMD} @dirrm share/upp/$$d >> ${TMPPLIST};done;
	@${ECHO_CMD} @dirrm share/upp >> ${TMPPLIST}
	@${RM} ${WRKSRC}/*.txt
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
