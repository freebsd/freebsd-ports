# New ports collection makefile for:	xwave
# Date created:				2000-06-11
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.8 2000/04/24 14:52:33 hubertf Exp $
# $FreeBSD$
#

PORTNAME=	xwave
PORTVERSION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.vex.net/pub/software/
DISTNAME=	xwave2

MAINTAINER=	trevor@jpj.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

DOC_FILES=	README README-XWAVE2 README.v06 COPYING INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave ${PREFIX}/lib/X11/app-defaults/

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwave2
.for i in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/xwave2
.endfor
.endif

.include <bsd.port.mk>
