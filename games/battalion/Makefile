# Created by: Andrey Zakhvatov

PORTNAME=	battalion
PORTVERSION=	1.4b
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.evl.uic.edu/aej/BATTALION/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} battalionSUN4.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monsters, explosions, destruction game for X Window System

LICENSE=	batallion
LICENSE_NAME=	batallion license
LICENSE_FILE=	${WRKSRC}/README
# non-commercial and prohibits distribution of modified versions
LICENSE_PERMS=	dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		gl localbase tar:bzip2 xorg
USE_GL=		gl glu
USE_XORG=	x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LIBS}"

CFLAGS+=	-I${LOCALBASE}/include/X11 \
		-DLINUXVERSION -DLINUXAUDIO
LIBS+=		-lX11 -lm

PLIST_FILES=	bin/${PORTNAME} man/man6/${PORTNAME}.6.gz
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${GZCAT} ${DISTDIR}/battalionSUN4.tar.gz | \
		(cd ${WRKDIR} && ${TAR} --unlink -xf -)
	@${RM} ${WRKSRC}/*.o

post-patch:
	@${REINPLACE_CMD} -e \
		'/dataPtr/s| = getenv.*| = "${DATADIR}";|' ${WRKSRC}/battalion.c
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>| ; \
		 s|<linux/soundcard\.h>|<sys/soundcard.h>|' ${WRKSRC}/soundIt.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battalion ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man \
		${STAGEDIR}${MAN6PREFIX}/man/man6/battalion.6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho \
		${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/DATA
	${INSTALL_DATA} ${WRKSRC}/DATA/*.data ${STAGEDIR}${DATADIR}/DATA
	@${MKDIR} ${STAGEDIR}${DATADIR}/MUSIC
	${INSTALL_DATA} ${WRKSRC}/MUSIC/*.au ${STAGEDIR}${DATADIR}/MUSIC
	@${MKDIR} ${STAGEDIR}${DATADIR}/SOUNDS
	${INSTALL_DATA} ${WRKSRC}/SOUNDS/*.au ${STAGEDIR}${DATADIR}/SOUNDS
	@${MKDIR} ${STAGEDIR}${DATADIR}/TEXTURES
	${INSTALL_DATA} ${WRKSRC}/TEXTURES/*.tex ${STAGEDIR}${DATADIR}/TEXTURES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/*.gif ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
