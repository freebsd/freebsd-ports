# New ports collection makefile for:	chromium
# Date created:				17 Dec, 2003
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
PORTVERSION=	0.9.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.reptilelabour.com/software/files/chromium/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tar.gz \
		${PORTNAME}-data-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An arcade-style, top-scrolling space shooter

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		smpeg.1:${PORTSDIR}/multimedia/smpeg \
		openal.0:${PORTSDIR}/audio/openal

USE_GL=		yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/Chromium-0.9

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chromium ${PREFIX}/bin
	${MKDIR} ${DATADIR}/data
	(cd ${WRKSRC}/data && \
		${TAR} -c -f - png fonts wav --exclude "*CVS*" --exclude "*xvpics*") | \
		(cd ${DATADIR}/data && ${TAR} -x -f - )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/data/doc && ${TAR} -c -f - * --exclude "*CVS*") | \
		(cd ${DOCSDIR} && ${TAR} -x -f - )
.endif

.include <bsd.port.mk>
