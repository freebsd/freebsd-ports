# New ports collection makefile for:	yafray
# Date created:				18 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	yafray
PORTVERSION=	0.0.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.yafray.org/sec/2/downloads/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A fast XML based raytracer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_SCONS=	yes
USE_GETOPT_LONG=yes
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

pre-patch:
	@${MV} ${WRKSRC}/linux-settings.py ${WRKSRC}/freebsd-settings.py

.include <bsd.port.post.mk>
