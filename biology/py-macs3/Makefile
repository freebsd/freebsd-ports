PORTNAME=		MACS3
DISTVERSIONPREFIX=	v
DISTVERSION=		3.0.1
CATEGORIES=		biology python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Peak caller aimed at transcription factor binding sites
WWW=		https://github.com/taoliu/MACS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=Requires _Float16

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYNUMPY} \
		simde>0:devel/simde \
		${PYTHON_PKGNAMEPREFIX}cykhash>0:devel/py-cykhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hmmlearn>0:math/py-hmmlearn@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cykhash>0:devel/py-cykhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hmmlearn>0:math/py-hmmlearn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		bash:shells/bash

USES=		localbase perl5 python shebangfix
USE_GITHUB=	yes
USE_PERL5=	test
USE_PYTHON=	autoplist concurrent cython pep517

GH_ACCOUNT=	macs3-project
GH_PROJECT=	MACS
SHEBANG_FILES=	test/cmdlinetest* test/prockreport test/*.py test/pyprofile*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1302509
IGNORE=		does not run properly on FreeBSD 13.2 and earlier due to use of dynamically loaded libc by py-threadpoolctl.  Please upgrade to a newer FreeBSD or use py-macs2 instead.  See PR 276231
.endif

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/MACS3/*/*.so

# FIXME: Some tests fail due to a py-threadpoolctl issue
# https://github.com/joblib/threadpoolctl/pull/148
do-test: deinstall reinstall
	@${RM} -rf ${WRKSRC}/temp
	@cd ${WRKSRC}/test && ./cmdlinetest tag

.include <bsd.port.mk>
