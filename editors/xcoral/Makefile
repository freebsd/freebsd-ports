# New ports collection makefile for:    xcoral
# Date created:         1995/10/02
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	xcoral
PORTVERSION=	3.42b
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiwindow mouse-based text editor for X

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/b//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
