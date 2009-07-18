# New ports collection makefile for:	yafray
# Date created:				18 May 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	yafray
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.yafray.org/sec/2/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast XML based raytracer

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_SCONS=	yes
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

pre-patch:
	@${MV} ${WRKSRC}/linux-settings.py ${WRKSRC}/freebsd-settings.py

.include <bsd.port.mk>
