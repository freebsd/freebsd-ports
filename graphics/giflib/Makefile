# New ports collection makefile for:	giflib
# Version required:	4.1.0
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	giflib-4.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/giflib

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/giflib
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/giflib
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${PREFIX}/share/doc/giflib
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/giflib
.endif

.include <bsd.port.mk>
