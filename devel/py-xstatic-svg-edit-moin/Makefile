PORTNAME=	xstatic-svg-edit-moin
DISTVERSION=	2012.11.27.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-svg-edit-moin-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	svg-edit-moin 2012.11.27 (XStatic packaging standard)
WWW=		https://code.google.com/archive/p/svg-edit/

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-svg-edit-moin'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
