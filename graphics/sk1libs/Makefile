# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sk1libs
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	https://downloads.sk1project.net/uniconvertor/v1.1.5/ \
		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/uniconvertor/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Set of python libraries for sK1 Project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GNU_LGPL_v2

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libfreetype.so:print/freetype2

USES=		jpeg python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_BUILD_TARGET=build_ext
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib \
			-I${LOCALBASE}/include:${LOCALBASE}/include/freetype2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/src/utils/fs.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/ft2engine/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/pycms/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/imaging/*.so

.include <bsd.port.mk>
