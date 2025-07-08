PORTNAME=	xstatic-jquery-file-upload
DISTVERSION=	10.31.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-jQuery-File-Upload-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	jQuery-File-Upload (XStatic packaging standard)
WWW=		https://github.com/blueimp/jQuery-File-Upload

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-jquery-file-upload'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
