# New ports collection makefile for:	wolf3d
# Date created:			13 Jan 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wolf3d
PORTVERSION=	20011028
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/wolf3d/:wolf \
		http://www.liquidx.org/distfiles/:wolfdata
DISTFILES=	wolf3d-20011028.tar.gz:wolf wolfdata.tar.gz:wolfdata

MAINTAINER=	tlp@liquidx.org
COMMENT=	"Wolfenstein 3D Linux" by Steven Fuller (1992)

USE_SDL=	sdl
USE_GZIP=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|OBJS += sd_null.o|#OBJS += sd_null.o|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|#OBJS += sd_oss.o fmopl.o|OBJS += sd_oss.o fmopl.o|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib|${X11BASE}/lib|' ${WRKSRC}/Makefile
	@${CAT} ${FILESDIR}/wolf3d.in | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' > ${WRKDIR}/wolf3d

do-install:
	${MKDIR} ${PREFIX}/libexec/wolf3d
	${INSTALL_SCRIPT} ${WRKDIR}/wolf3d ${PREFIX}/bin/wolf3d
	${INSTALL_PROGRAM} ${WRKSRC}/sdlwolf3d ${PREFIX}/libexec/wolf3d/sdlwolf3d
	${INSTALL_DATA} ${WRKDIR}/wolfdata/* ${PREFIX}/libexec/wolf3d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/docs
	${INSTALL_DATA}	${WRKSRC}/IDEAS ${DOCSDIR}/IDEAS
	${INSTALL_DATA} ${WRKSRC}/NOTES ${DOCSDIR}/NOTES
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/TODO
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
