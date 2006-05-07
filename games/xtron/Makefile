# New ports collection makefile for:	xtron
# Date created:				29 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xtron
PORTVERSION=	1.1a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Avoid running into walls, your own tail, and that of your opponent

USE_X_PREFIX=	yes
USE_XPM=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xtronrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtron ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xtron
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/xtron
	${INSTALL_DATA} ${WRKSRC}/xtronrc ${PREFIX}/lib/X11/app-defaults/Tron
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
