# New ports collection makefile for: tenebrae
# Date created:		14 Mar 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	tenebrae
PORTVERSION=	1.04
CATEGORIES=	games
MASTER_SITES=	http://tenebrae.sourceforge.net/downloads/
DISTFILES=	${PORTNAME}_src${EXTRACT_SUFX} \
		${PORTNAME}data${EXTRACT_SUFX}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Quake 1 source port with advanced graphics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_XLIB=	yes
USE_SDL=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}_0
BUILD_WRKSRC=	${WRKSRC}/linux
MAKE_ENV=	DATADIR="${DATADIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
	@${REINPLACE_CMD} -e "s|$$(${PRINTF} '\r')||g" `${FIND} ${WRKSRC} -type f`

pre-build:
	@${LN} -sf ${WRKSRC}/linux/Makefile.i386linux ${WRKSRC}/linux/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/debugi386.glibc/bin/${PORTNAME}.run \
		${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Pak0.pak ${DATADIR}/${PORTNAME}
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TR} -d '\r' <${WRKDIR}/Tenebrae_Readme.txt \
		>${DOCSDIR}/Tenebrae_Readme.txt
.endif

post-install:
	@${SED} -e 's|%%DATADIR%%|${DATADIR}|' <${PKGMESSAGE}

.include <bsd.port.mk>
