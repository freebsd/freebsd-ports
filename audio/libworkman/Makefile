# New ports collection makefile for:	libworkman
# Version required:		1.4
# Date created:			8 August 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	libworkman-1999-06-20
PKGNAME=	libworkman-1.4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.midwinter.com/WorkMan/SNAPSHOTS/

MAINTAINER=	jim@FreeBSD.org

WRKSRC=		${WRKDIR}/libworkman
USE_IMAKE=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
