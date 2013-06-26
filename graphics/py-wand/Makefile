# $FreeBSD$

PORTNAME=	Wand
PORTVERSION=	0.3.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	MagickWand Python binding

LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-patch:
	@${REINPLACE_CMD} -e "s|cmdclass={'upload_doc': upload_doc}||" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
