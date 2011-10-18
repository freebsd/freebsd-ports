# New ports collection makefile for:	battalion
# Date created:				17 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	battalion
PORTVERSION=	1.4b
CATEGORIES=	games
MASTER_SITES=	http://www.evl.uic.edu/aej/BATTALION/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} battalionSUN4.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monsters, explosions, destruction game for X Window System

USE_BZIP2=	yes
USE_GL=		glu
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include \
		-DLINUXVERSION -DLINUXAUDIO
LDFLAGS=	-L${LOCALBASE}/lib

MAN6=		battalion.6

post-extract:
	@${GZCAT} ${DISTDIR}/battalionSUN4.tar.gz | \
		(cd ${WRKDIR} && ${TAR} --unlink -xf -)
	@${RM} -f ${WRKSRC}/*.o

post-patch:
	@${REINPLACE_CMD} -e \
		'/dataPtr/s| = getenv.*| = "${DATADIR}";|' ${WRKSRC}/battalion.c
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>| ; \
		 s|<linux/soundcard\.h>|<sys/soundcard.h>|' ${WRKSRC}/soundIt.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battalion ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man \
		${MAN6PREFIX}/man/man6/battalion.6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho \
		${DATADIR}
	@${MKDIR} ${DATADIR}/DATA
	${INSTALL_DATA} ${WRKSRC}/DATA/*.data ${DATADIR}/DATA
	@${MKDIR} ${DATADIR}/MUSIC
	${INSTALL_DATA} ${WRKSRC}/MUSIC/*.au ${DATADIR}/MUSIC
	@${MKDIR} ${DATADIR}/SOUNDS
	${INSTALL_DATA} ${WRKSRC}/SOUNDS/*.au ${DATADIR}/SOUNDS
	@${MKDIR} ${DATADIR}/TEXTURES
	${INSTALL_DATA} ${WRKSRC}/TEXTURES/*.tex ${DATADIR}/TEXTURES
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/*.gif ${DOCSDIR}
.endif

.include <bsd.port.mk>
