# ports collection makefile for:	libmikmod
# Date created:		Sun Apr 11 13:06:01 PDT 1999
# Whom:			Michael Haro <mharo@area51.fremont.ca.us>
#
# $FreeBSD$
#

PORTNAME=	libmikmod
PORTVERSION=	3.1.9
CATEGORIES=	audio
MASTER_SITES=	http://www.mikmod.org/files/libmikmod/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada

MAINTAINER=	ports@FreeBSD.org

USE_ESOUND=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=	libmikmod-config.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

pre-build:
	${RM} -rf ${WRKSRC}/docs/mikmod.info-*

.include <bsd.port.mk>
