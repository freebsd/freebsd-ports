# New ports collection makefile for:	lphoto
# Date created:		2004-06-03
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	lphoto
PORTVERSION=	2.0.42
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://software.linspire.com/emptypool/lindowsos/pool/main/l/lphoto/
DISTNAME=	${PORTNAME}_${PORTVERSION}-0.0.0.45.lindows0.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete desktop solution for digital photo management

BUILD_DEPENDS=	kdepyuic:${PORTSDIR}/x11-toolkits/py-kde
# libs for burning cd/vcd in lphoto, does not work in freebsd.
#LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick \
#		vcdinfo.0:${PORTSDIR}/multimedia/vcdimager \
#		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	gphoto2:${PORTSDIR}/graphics/gphoto2 \
		kdepyuic:${PORTSDIR}/x11-toolkits/py-kde \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl
#USE_CDRTOOLS=	yes

USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py -d ${PREFIX}/${PYTHON_SITELIBDIR:S/${PYTHONBASE}//} -b ${PREFIX}/bin

.include <bsd.port.post.mk>
