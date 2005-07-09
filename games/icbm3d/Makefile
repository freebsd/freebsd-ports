# New ports collection makefile for:	icbm3d
# Date created:				20 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	icbm3d
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/icbm3d/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Inter-Continental Ballistic Missiles, 3D" - 3D game of defense

WRKSRC=		${WRKDIR}/icbm3d
USE_X_PREFIX=	yes
MAKEFILE=	makefile
ALL_TARGET=	icbm3d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbm3d ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/icbm3d
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d
.endif

.include <bsd.port.mk>
