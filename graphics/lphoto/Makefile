# New ports collection makefile for:	lphoto
# Date created:		2004-06-03
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	lphoto
PORTVERSION=	1.0.13
CATEGORIES=	graphics
MASTER_SITES=	 http://software.linspire.com/emptypool/lindowsos/pool/main/l/lphoto/
DISTNAME=	${PORTNAME}_${PORTVERSION}-0.0.0.45.lindows0.1

MAINTAINER=	ahze@ahze.net
COMMENT=	A complete desktop solution for digital photo management

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	gphoto2:${PORTSDIR}/graphics/gphoto2 \
		pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_KDELIBS_VER=3
USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py -d ${PREFIX}/${PYTHON_SITELIBDIR:S/${PYTHONBASE}//} -b ${PREFIX}/bin

.include <bsd.port.mk>
