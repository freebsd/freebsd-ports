# ports collection makefile for:   libmikmod
# Version required:    3.1.7
# Date created:        Sun Apr 11 13:06:01 PDT 1999
# Whom:                Michael Haro <mharo@area51.fremont.ca.us>
#
# $FreeBSD$
#

DISTNAME=	libmikmod-3.1.7
CATEGORIES=	audio
# The files at multimania.com seem to be corrupted
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/

MAINTAINER=	mharo@FreeBSD.org

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

USE_LIBTOOL=	yes
USE_GMAKE=	yes

pre-build:
	${RM} -rf ${WRKSRC}/info/mikmod.info-*

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
