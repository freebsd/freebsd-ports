# New ports collection makefile for:	lphoto
# Date created:		2004-06-03
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	lphoto
PORTVERSION=	1.0.26
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://software.linspire.com/emptypool/lindowsos/pool/main/l/lphoto/
DISTNAME=	${PORTNAME}_${PORTVERSION}-0.0.0.45.lindows0.1

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A complete desktop solution for digital photo management

BUILD_DEPENDS=	kdepyuic:${PORTSDIR}/x11-toolkits/py-kde
LIB_DEPENDS=	Magick.7:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	gphoto2:${PORTSDIR}/graphics/gphoto2 \
		kdepyuic:${PORTSDIR}/x11-toolkits/py-kde

USE_REINPLACE=	yes
USE_PYTHON=	2.3
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Hack to use OPTIONS since OPTIONS is listed below bsd.port.pre.mk
OPTIONS=

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS+=	JPEGMMX "Use JPEG with MMX optimization" off
.endif

.if defined(WITH_JPEGMMX)
RUN_DEPENDS+=	jpegtran-mmx:${PORTSDIR}/graphics/jpeg-mmx
.endif

post-patch:
.if defined(WITH_JPEGMMX)
	@${REINPLACE_CMD} -e 's|jpegtran|jpegtran-mmx|' \
		${WRKSRC}/Lphoto/photolibrary.py
.endif

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py -d ${PREFIX}/${PYTHON_SITELIBDIR:S/${PYTHONBASE}//} -b ${PREFIX}/bin

.include <bsd.port.post.mk>
