PORTNAME=	inotify-simple
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple wrapper around inotify
WWW=		https://github.com/chrisjbillington/inotify_simple

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.options.mk>

# Native inotify is in libc since FreeBSD 15 (OSVERSION 1500051); older releases need libinotify
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500051
LIB_DEPENDS=	libinotify.so:devel/libinotify
.endif

.include <bsd.port.mk>
