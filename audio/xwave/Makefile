# New ports collection makefile for:	xwave
# Date created:				11 June 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xwave
PORTVERSION=	2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}${PORTVERSION:S/./v/}

MAINTAINER=	martin.kraft@fal.de
COMMENT=	Audio player/recorder/editor for the X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}2-981109
USE_IMAKE=	yes
USE_XPM=	yes

DOC_FILES=	README README-XWAVE2 README.v06 INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave ${PREFIX}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xwave
.for i in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/xwave
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
