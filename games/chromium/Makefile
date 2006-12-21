# New ports collection makefile for:	chromium
# Date created:				17 Dec, 2003
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
PORTVERSION=	0.9.12
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.reptilelabour.com/software/files/chromium/ \
		http://www.amdmi3.ru/distfiles/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tar.gz \
		${PORTNAME}-data-${PORTVERSION}.tar.gz

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	An arcade-style, top-scrolling space shooter

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		smpeg.1:${PORTSDIR}/multimedia/smpeg \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut

USE_GL=		yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/Chromium-0.9

post-patch:
	@${REINPLACE_CMD} -e 's|-lopenal|& -lalut|g' \
			  -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/src/CHROMIUM.pro
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/src-setup/Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/support/glpng/src/Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/support/glpng/src/glpng.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chromium ${PREFIX}/bin
	${MKDIR} ${DATADIR}/data
	(cd ${WRKSRC}/data && \
		${TAR} -c -f - --exclude "*CVS*" --exclude "*xvpics*" png fonts wav) | \
		(cd ${DATADIR}/data && ${TAR} -x -f - )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/data/doc && ${TAR} -c -f - --exclude "*CVS*" *) | \
		(cd ${DOCSDIR} && ${TAR} -x -f - )
.endif

.include <bsd.port.mk>
