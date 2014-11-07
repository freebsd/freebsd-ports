# $FreeBSD$

PORTNAME=	Wand
PORTVERSION=	0.3.8
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	MagickWand Python binding

LICENSE=	MIT

LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data ${DATADIR}

.include <bsd.port.post.mk>
