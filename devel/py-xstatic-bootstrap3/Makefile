PORTNAME=	xstatic-bootstrap
DISTVERSION=	3.1.1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	XStatic-Bootstrap-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Bootstrap 3.1.1 (XStatic packaging standard)
WWW=		https://getbootstrap.com/

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

#post-patch:
#	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-bootstrap'|g" \
#		${WRKSRC}/setup.py

.include <bsd.port.mk>
