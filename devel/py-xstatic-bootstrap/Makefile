PORTNAME=	xstatic-bootstrap
DISTVERSION=	5.3.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Bootstrap 5.X (XStatic packaging standard)
WWW=		https://getbootstrap.com/

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-bootstrap'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
