PORTNAME=	espeakng_loader
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
CATEGORIES=	audio python
#MASTER_SITES=	PYPI # no latest version on PyPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shared library loader for eSpeak NG
WWW=		https://github.com/thewh1teagle/espeakng-loader

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	espeak-ng>0:audio/espeak-ng

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	thewh1teagle
GH_PROJECT=	espeakng-loader
GH_TAGNAME=	0ddc87adf77e5850d7eeb542ac8a87d421b64daa

NO_ARCH=	yes

post-patch: # patch to change %%PREFIX%% in __init__.py to the actual prefix
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/espeakng_loader/__init__.py

.include <bsd.port.mk>
