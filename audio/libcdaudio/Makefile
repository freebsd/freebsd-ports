# New ports collection makefile for:	libcdaudio
# Version required:	0.7.0
# Date created:		01 June 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	libcdaudio_0.7.0
PKGNAME=	libcdaudio-0.7.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.debian.org/pub/debian/dists/potato/main/source/libs/
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_LIBTOOL=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
