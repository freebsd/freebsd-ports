# New ports collection makefile for:	duke3d
# Date Created:				18 September 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	duke3d
PORTVERSION=	20012306
CATEGORIES=	games
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/

MAINTAINER=	arundel@gmx.net
COMMENT=	Icculus Duke Nukem 3D port for various Operating Systems

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	mixer sdl
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

TARGET_DIR=	${LOCALBASE}/${PORTNAME}

DATA_FILES=	defs.con game.con user.con
PROG_FILES=	${WRKSRC}/source/${PORTNAME} ${WRKSRC}/source/buildengine/build
DOC_FILES1=	README 	BUILDLIC.TXT CONTRIB TODO CHANGELOG ../../readme.txt ../../gnu.txt

pre-everything::
.ifndef(WITHOUT_DOSBOX)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITHOUT_DOSBOX to disable the dependency on dosbox."
	@${ECHO_MSG} "Then however you will not be able to change the Duke3D config."
	@${ECHO_MSG} ""

RUN_DEPENDS=	${LOCALBASE}/bin/dosbox:${PORTSDIR}/emulators/dosbox
.endif

post-patch:
	@${SED} -e 's|%%DUKEDIR%%|${PREFIX}/${PORTNAME}|g' ${FILESDIR}/fix.sh > \
		${WRKDIR}/fix.sh
	@${SED} -e 's|%%DUKEDIR%%|${PREFIX}/${PORTNAME}|g' ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|sdl-config|${SDL_CONFIG}|g ; s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%CFLAGS%%|${CFLAGS} -I${X11BASE}/include|g'

do-build:
	cd ${WRKSRC}/source/buildengine && ${GMAKE}
	cd ${WRKSRC}/source && ${GMAKE}

do-install:
	${INSTALL} -d ${TARGET_DIR}
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fix.sh ${TARGET_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${TARGET_DIR}/duke.sh
	${INSTALL} -d ${TARGET_DIR}/testdata

.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/testdata/${file} ${TARGET_DIR}/testdata
.endfor

	${LN} -s ${TARGET_DIR}/duke.sh ${LOCALBASE}/bin/duke3d

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}

.for file in ${DOC_FILES1}
	${INSTALL_MAN} ${WRKSRC}/source/buildengine/${file} ${DOCSDIR}
.endfor

	${REINPLACE_CMD}-e 's|%%DUKEDIR%%|${PREFIX}/${PORTNAME}|g' ${FILESDIR}/README.bsd > \
	${DOCSDIR}/README.bsd

.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
