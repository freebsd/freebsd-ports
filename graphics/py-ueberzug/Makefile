PORTNAME=	ueberzug
DISTVERSION=	18.1.8
PORTREVISION=	3
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw images on terminals with X11 child windows
WWW=		https://github.com/ueber-devel/ueberzug

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}attrs>=18.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xlib>=0:x11-toolkits/py-python-xlib@${PY_FLAVOR}

USES=		localbase python shebangfix xorg
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	ueber-devel
USE_PYTHON=	autoplist concurrent distutils
USE_XORG=	x11 xext
SHEBANG_GLOB=	*.py *.sh

PORTEXAMPLES=	fzfimg.sh mastodon.sh

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Xshm*.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
