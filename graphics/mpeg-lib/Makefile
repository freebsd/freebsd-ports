# New ports collection makefile for:	mpeg_lib
# Version required:	1.3.1
# Date created:		16 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	mpeg_lib-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.bic.mni.mcgill.ca/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTIMIZE="${CFLAGS}"

pre-install:
	@${MKDIR} ${PREFIX}/bin ${PREFIX}/lib ${PREFIX}/include

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
