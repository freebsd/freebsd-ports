# New ports collection makefile for:	wmGrabImage
# Date created:		4th November 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmGrabImage
PORTVERSION=	0.70
CATEGORIES=	graphics windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

WRKSRC=		${WRKDIR}/${DISTNAME}/wmGrabImage

USE_GMAKE=	YES
USE_X_PREFIX=	YES

MAN1=		wmGrabImage.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmGrabImage ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/GrabImage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmGrabImage.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
