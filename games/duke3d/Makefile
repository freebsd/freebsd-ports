# New ports collection makefile for:	duke3d
# Date Created:				18 September 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	duke3d
PORTVERSION=	20041505
CATEGORIES=	games
MASTER_SITES=	http://520061600655-0001.bei.t-online.de/ports/${PORTNAME}/

MAINTAINER=	arundel@h3c.de
COMMENT=	Icculus Duke Nukem 3D port for various Operating Systems

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	mixer sdl
USE_REINPLACE=	yes
CONFLICTS=	jfduke3d-200[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}

TARGET_DIR=	${LOCALBASE}/${PORTNAME}

PROG_FILES=	${WRKSRC}/source/${PORTNAME} ${WRKSRC}/source/buildengine/build
DATA_FILES=	defs.con game.con user.con
BUILD_FILES=	${WRKSRC}/source/buildengine/stuff.dat
SCRIPT_FILES=	${WRKDIR}/fix.sh ${WRKDIR}/duke3d.sh ${WRKDIR}/build.sh
PORTDOCS=	README BUILDLIC.TXT CONTRIB TODO CHANGELOG
MOREDOCS=	readme.txt gnu.txt

OPTIONS=	DOSBOX "Dependency on dosbox (required by SETUP.EXE and\
		SETMAIN.EXE to edit the config file)" on

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 499999
DEPRECATED=	Please use games/jfduke3d. This port is being kept for RELENG_4 users
.endif

.if !defined(WITHOUT_DOSBOX)
RUN_DEPENDS+=	dosbox:${PORTSDIR}/emulators/dosbox
.endif

post-patch:
	@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/fix.sh > \
		${WRKDIR}/fix.sh
	@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/duke3d.sh
	@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/build-wrapper.sh > \
		${WRKDIR}/build.sh
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|sdl-config|${SDL_CONFIG}|g ; s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%CFLAGS%%|${CFLAGS} -I${X11BASE}/include|g'

do-build:
	cd ${WRKSRC}/source/buildengine && ${GMAKE}
	cd ${WRKSRC}/source && ${GMAKE}

do-install:
	${INSTALL} -d ${DATADIR}
	${INSTALL_PROGRAM} ${PROG_FILES} ${DATADIR}
	${INSTALL_DATA}	${BUILD_FILES} ${DATADIR}
	${INSTALL} -d ${DATADIR}/testdata

.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/testdata/${file} ${DATADIR}/testdata
.endfor

	${INSTALL_SCRIPT} ${SCRIPT_FILES} ${DATADIR}
	${LN} -fs ${DATADIR}/duke3d.sh ${LOCALBASE}/bin/duke3d
	${LN} -fs ${DATADIR}/build.sh ${LOCALBASE}/bin/duke3d-build

post-install:
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}

.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/source/buildengine/${file} ${DOCSDIR}
.endfor

.for file in ${MOREDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
