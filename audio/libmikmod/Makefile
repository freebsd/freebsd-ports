# ports collection makefile for:   libmikmod
# Version required:    3.1.9
# Date created:        Sun Apr 11 13:06:01 PDT 1999
# Whom:                Michael Haro <mharo@area51.fremont.ca.us>
#
# $FreeBSD$
#

DISTNAME=	libmikmod-3.1.9
CATEGORIES=	audio
MASTER_SITES=	http://www.mikmod.darkorb.net/libmikmod/

MAINTAINER=	mharo@FreeBSD.org

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

USE_LIBTOOL=	yes
USE_GMAKE=	yes

MAN1=	libmikmod-config.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/mikmod.info-*

.include <bsd.port.mk>
