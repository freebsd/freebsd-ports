PORTNAME=	orjson
PORTVERSION=	3.8.0
PORTREVISION=	8
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Fast, correct JSON library for Python
WWW=		https://pypi.org/project/orjson/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.8.3:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=20.2.3:devel/py-pip@${PY_FLAVOR}

USES=		cargo python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils
USE_GITHUB=	yes
GH_ACCOUNT=	ijl

CARGO_CRATES=	ahash-0.8.0 \
		arrayvec-0.7.2 \
		associative-cache-1.0.1 \
		autocfg-1.1.0 \
		beef-0.5.2 \
		bytecount-0.6.3 \
		castaway-0.2.2 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		compact_str-0.6.1 \
		encoding_rs-0.8.31 \
		itoa-1.0.3 \
		libc-0.2.132 \
		libm-0.1.4 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.13.1 \
		packed_simd_2-0.3.8 \
		pyo3-build-config-0.17.0 \
		pyo3-ffi-0.17.0 \
		rustversion-1.0.9 \
		ryu-1.0.11 \
		serde-1.0.144 \
		simdutf8-0.1.4 \
		smallvec-1.9.0 \
		target-lexicon-0.12.4 \
		version_check-0.9.4

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=${WRKSRC}/target
MAKE_ENV=	${CARGO_ENV}
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

# This is to prevent Mk/Uses/python.mk do-configure target from firing.
do-configure:
	@${ECHO} 'No configure'

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} maturin build \
		--release \
		${WITH_DEBUG:D:U--strip} \
		--interpreter ${PYTHON_CMD})

# Due to upstream not supplying a setup.py file or other way to install
# using pip command for now...
do-install:
.if ${ARCH:Mpowerpc64*}
	@(cd ${INSTALL_WRKSRC}; \
		${FIND} . -name "*whl" -exec sh -c 'mv {} `echo {} | sed  -E -e "s/powerpc.*/powerpc.whl/"`' \;)
.endif
	@${SETENV} ${MAKE_ENV} pip install \
		--isolated \
		--root=${STAGEDIR} \
		--ignore-installed \
		--no-deps ${INSTALL_WRKSRC}/target/wheels/*.whl

post-install:
	@${RM} -r ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/__pycache__
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/liborjson.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/liborjson.so
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR} because the file that is generated in the first place
	# contains only the EGG files as a whole.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
