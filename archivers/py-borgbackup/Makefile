PORTNAME=	borgbackup
DISTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	https://github.com/borgbackup/borg/releases/download/${DISTVERSION}/ \
		PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Deduplicating backup program
WWW=		https://pypi.org/project/borgbackup/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# note that borgbackup pins the msgpack version range per patchlevel version!
_BB_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.3<1.1.1_99:devel/py-msgpack@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=1.7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${_BB_DEPENDS}
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libxxhash.so:devel/xxhash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=19.0:devel/py-packaging@${PY_FLAVOR} \
		${_BB_DEPENDS}
TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}tox>3.2:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		fakeroot:security/fakeroot

USES=		pkgconfig python ssl
USE_PYTHON=	autoplist distutils
MAKE_ENV=	BORG_OPENSSL_PREFIX=${OPENSSLBASE}

OPTIONS_DEFINE=		FUSE
OPTIONS_DEFAULT=	FUSE

FUSE_DESC=	Support to mount locally borg backup files
FUSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llfuse>0:filesystems/py-llfuse@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if (${OPSYS} == FreeBSD) && ${OSVERSION} < 1400033 # why 1400033?
# 1. check for the OLDEST (last in list) history entry on the file, when it was added:
#    git -C /usr/src hist lib/libc/posix1e/acl_extended_file_np.c
# 2. check for the version you have obtained what __FreeBSD_version was
#    and increment by one. This is inaccurate for the interim between file addition
#    and __FreeBSD_version bump back then, but those versions were no releases and
#    should no longer be in the field.
EXTRA_PATCHES	+= ${FILESDIR}/extrapatch-setup.py
post-patch:
	${CP} ${FILESDIR}/acl_extended_file_np.c ${WRKSRC}/src/borg/platform/
.endif

_BORGHOME=${WRKDIR}/testhome
_BORGENV=-i BORG_PASSPHRASE=secret123 PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} HOME=${_BORGHOME}
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
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg compact --progress ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg check --verify-data ${WRKDIR}/borgrepo
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg extract --dry-run --progress ${WRKDIR}/borgrepo::test2
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg export-tar ${WRKDIR}/borgrepo::test2 - >/dev/null
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg list ${WRKDIR}/borgrepo
	# long output - ${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg list ${WRKDIR}/borgrepo::test2 | ${GREP} -v ^d
	${SETENV} ${_BORGENV} ${STAGEDIR}${PREFIX}/bin/borg info ${WRKDIR}/borgrepo

do-test:
	cd ${WRKSRC} && ${SETENV} ${_BORGENV} ${TEST_ENV} tox-${PYTHON_VER} -e ${PY_FLAVOR} -vv

.include <bsd.port.post.mk>
