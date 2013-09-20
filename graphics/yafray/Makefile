# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	yafray
PORTVERSION=	0.0.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		#http://www.yafaray.org/sites/default/files/download/builds/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast XML based raytracer

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_SCONS=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
pre-patch:
	@${MV} ${WRKSRC}/linux-settings.py ${WRKSRC}/freebsd-settings.py

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
