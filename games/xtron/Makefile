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

USE_X_PREFIX=	yes
USE_XPM=	yes

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xtronrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtron ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xtron
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/xtron
	${INSTALL_DATA} ${WRKSRC}/xtronrc ${PREFIX}/lib/X11/app-defaults/Tron
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xtron
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/xtron
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtron
.endif

.include <bsd.port.mk>
