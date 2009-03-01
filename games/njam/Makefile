# New ports collection makefile for: njam
# Date created:		10 November 2003
# Whom:			<janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	njam
PORTVERSION=	1.25
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	 ${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Fast paced multiplayer pac-man clone

BROKEN=		does not build

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CPPFLAGS=-I${LOCALBASE}/include"
USE_SDL=	mixer image net sdl
DOC_FILES=	assassin.gif award-2.gif cookie.gif doc-editor.html \
		doc.html doc2.html door.gif freezer.gif ghactive.gif \
		ghinactive.gif hunter.gif invisible.gif juice.gif \
		sample.gif shaddy.gif skin000.gif skin001.gif skin003.gif \
		teleport.gif thinline.gif trap.gif

post-install:
	${CP} ${FILESDIR}/njam.sh ${WRKDIR}/njam.sh
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/njam.sh
	${INSTALL_SCRIPT} ${WRKDIR}/njam.sh ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
