PORTNAME=		MACS3
DISTVERSIONPREFIX=	v
DISTVERSION=		3.0.3
CATEGORIES=		biology python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Peak caller aimed at transcription factor binding sites
WWW=		https://github.com/taoliu/MACS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=Requires _Float16

COMMON_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>1.11.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cykhash>=2.0,<3.0:devel/py-cykhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.3:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hmmlearn>=0.3.2:math/py-hmmlearn@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		simde>0:devel/simde \
		${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		bash:shells/bash

USES=		localbase perl5 python shebangfix
USE_GITHUB=	yes
USE_PERL5=	test
USE_PYTHON=	autoplist concurrent cython distutils

GH_ACCOUNT=	macs3-project
GH_PROJECT=	MACS
SHEBANG_FILES=	test/cmdlinetest* test/prockreport test/*.py test/pyprofile*

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/MACS3/*/*.so

# FIXME: Some tests fail due to a py-threadpoolctl issue
# https://github.com/joblib/threadpoolctl/pull/148
do-test: deinstall reinstall
	@${RM} -rf ${WRKSRC}/temp
	@cd ${WRKSRC}/test && ./cmdlinetest tag

.include <bsd.port.mk>
