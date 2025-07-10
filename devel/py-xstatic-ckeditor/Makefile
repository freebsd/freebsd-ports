PORTNAME=	xstatic-ckeditor
DISTVERSION=	3.6.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-CKEditor-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CKEditor 3.6.4 (XStatic packaging standard)
WWW=		https://ckeditor.com

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-ckeditor'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
