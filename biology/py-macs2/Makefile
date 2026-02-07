PORTNAME=		macs2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2.9.1
PORTREVISION=	1
CATEGORIES=		biology python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify transcription factor binding sites
WWW=		https://github.com/taoliu/MACS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cykhash>0:devel/py-cykhash@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		bash:shells/bash

USES=		python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent cython0 distutils

GH_ACCOUNT=	taoliu
GH_PROJECT=	MACS
SHEBANG_FILES=	test/cmdlinetest_update test/cmdlinetest test/prockreport

post-stage:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

do-test: install
	@cd ${WRKSRC}/test && ./cmdlinetest tag

.include <bsd.port.mk>
