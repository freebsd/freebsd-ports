# New ports collection makefile for:	sk1libs
# Date created:		30 Jun 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sk1libs
PORTVERSION=	0.9.1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A set of python libraries for sK1 Project

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg

PROJECTHOST=	uniconvertor

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_BUILD_TARGET=build_ext
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib \
			-I${LOCALBASE}/include:${LOCALBASE}/include/freetype2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/src/utils/fs.py

.include <bsd.port.mk>
