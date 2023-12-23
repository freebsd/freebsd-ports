PORTNAME=	vosk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.45-20231214
CATEGORIES=	audio # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vosk: Offline open source speech recognition toolkit (Py + App)
WWW=		https://alphacephei.com/vosk/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../COPYING

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srt>0:multimedia/py-srt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS} \
		vosk-api>0:audio/vosk-api

USES=		python
USE_PYTHON=	distutils concurrent # autoplist is broken

USE_GITHUB=	yes
GH_ACCOUNT=	alphacep
GH_PROJECT=	vosk-api
GH_TAGNAME=	aba8497

WRKSRC_SUBDIR=	python

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e ' \
			s|elif sys.platform == "linux":|elif sys.platform == "linux" or sys.platform.startswith("freebsd"):|; \
			s|dlldir = .*|dlldir = "${LOCALBASE}/lib"| \
		' \
		${WRKSRC}/vosk/__init__.py

.include <bsd.port.mk>
