# New ports collection makefile for:	mpeg_lib
# Version required:	1.1
# Date created:		16 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	mpeg_lib-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/mpeg_lib

GNU_CONFIGURE= yup

pre-install:
	@${MKDIR} ${PREFIX}/bin ${PREFIX}/lib ${PREFIX}/include

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
