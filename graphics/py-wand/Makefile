# $FreeBSD$

PORTNAME=	Wand
PORTVERSION=	0.3.7
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	MagickWand Python binding

LICENSE=	MIT

LIB_DEPENDS=	libMagickWand-6.Q*.so:${PORTSDIR}/graphics/ImageMagick

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data ${DATADIR}

.include <bsd.port.post.mk>
