# New ports collection makefile for: BillardGL
# Date created:		02 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=		BillardGL
PORTVERSION=		1.75
PORTREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	billardgl

MAINTAINER=	tiamat@comset.net
COMMENT=	An OpenGL billiard simulator

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GL=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTNAME%%|${PORTNAME}|; \
			      s|%%X11BASE%%|${X11BASE}|' ${WRKSRC}/Namen.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/*.lang ${DATADIR}/lang
	@${MKDIR} ${DATADIR}/Texturen
.for i in 1 2 4 8
	@${MKDIR} ${DATADIR}/Texturen/${i}
	${INSTALL_DATA} ${WRKSRC}/Texturen/${i}/*.bmp ${DATADIR}/Texturen/${i}
.endfor

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TR} -d '\r' <${WRKSRC}/README >${DOCSDIR}/README
.endif

.include <bsd.port.mk>
