# $FreeBSD$

PORTNAME=	Wand
PORTVERSION=	0.3.5
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	MagickWand Python binding

LICENSE=	MIT

LIB_DEPENDS=	libMagickWand.so:${PORTSDIR}/graphics/ImageMagick

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|cmdclass={'upload_doc': upload_doc}||" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
