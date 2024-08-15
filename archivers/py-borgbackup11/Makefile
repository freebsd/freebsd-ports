PORTNAME=	borgbackup
DISTVERSION=	1.1.18
PORTREVISION=	3
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	11

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Deduplicating backup program
WWW=		https://pypi.org/project/borgbackup/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	No longer supported upstream, use borgbackup 1.2 (oldstable) or 1.4 (stable) instead.
EXPIRATION_DATE=2024-09-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=1.7:devel/py-setuptools-scm@${PY_FLAVOR}
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libxxhash.so:devel/xxhash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=19.0:devel/py-packaging@${PY_FLAVOR}
MAKE_ENV=	BORG_OPENSSL_PREFIX=${OPENSSLBASE}
TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}tox>3.2:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		fakeroot:security/fakeroot
USES=		pkgconfig python ssl
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		FUSE
OPTIONS_DEFAULT=	FUSE

FUSE_DESC=	Support to mount locally borg backup files
FUSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llfuse>0:devel/py-llfuse@${PY_FLAVOR}

_BORGHOME=${WRKDIR}/testhome
_BORGENV=BORG_PASSPHRASE=secret123 PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} HOME=${_BORGHOME}
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}${PREFIX}/share/man/man1/
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/borg/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;
	@${ECHO_MSG} "----> running borg smoke tests"
	${MKDIR} ${_BORGHOME}
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/borg -V
	${RM} -r ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg init --encryption=repokey ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg key export ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg create ${WRKDIR}/borgrepo::test1 ${WRKSRC}
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg create ${WRKDIR}/borgrepo::test2 ${WRKSRC} ${STAGEDIR}
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg check --verify-data ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg info ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg prune --keep-last 1 ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg check --verify-data ${WRKDIR}/borgrepo
	${ECHO_CMD} YES \
	| ${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg check --repair ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg check --verify-data ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg extract --dry-run --progress ${WRKDIR}/borgrepo::test2
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg export-tar ${WRKDIR}/borgrepo::test2 - >/dev/null
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg list ${WRKDIR}/borgrepo
	# long output - ${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg list ${WRKDIR}/borgrepo::test2 | ${GREP} -v ^d
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg info ${WRKDIR}/borgrepo

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${_BORGENV} tox-${PYTHON_VER} -e ${PY_FLAVOR} -vv

.include <bsd.port.mk>
