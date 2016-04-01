# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sk1libs
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Set of python libraries for sK1 Project

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libfreetype.so:print/freetype2

PROJECTHOST=	uniconvertor

USES=		jpeg python
USE_PYTHON=	distutils
PYDISTUTILS_BUILD_TARGET=build_ext
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib \
			-I${LOCALBASE}/include:${LOCALBASE}/include/freetype2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/src/utils/fs.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/ft2engine/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/pycms/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sk1libs/imaging/*.so

.include <bsd.port.mk>
