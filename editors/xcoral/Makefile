# New ports collection makefile for:    xcoral
# Date created:         1995/10/02
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	xcoral
PORTVERSION=	3.40
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
