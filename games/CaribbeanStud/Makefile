# New ports collection makefile for:	CaribbeanStud
# Date created:				4 July 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		CaribbeanStud
PORTVERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=		CS

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Caribbean Stud gambling game for X Window System

MAKEFILE=		Xmakefile
USE_MOTIF=		yes
USE_X_PREFIX=		yes
CFLAGS+=		-Wno-deprecated

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/CaribbeanStud ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/CaribbeanStud.res ${PREFIX}/lib/X11/app-defaults/CaribbeanStud
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/CaribbeanStud
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/CaribbeanStud
	@ ${INSTALL_DATA} ${WRKSRC}/class.ps ${PREFIX}/share/doc/CaribbeanStud
.endif

.include <bsd.port.mk>
