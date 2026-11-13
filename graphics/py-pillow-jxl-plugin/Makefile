PORTNAME=	pillow-jxl-plugin
DISTVERSION=	1.3.8
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pillow_jxl_plugin-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Pillow plugin for JPEG XL
WWW=		https://github.com/Isotr0py/pillow-jpegxl-plugin

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.2<2:devel/py-maturin@${PY_FLAVOR}
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libhwy.so:devel/highway \
		libjxl.so:graphics/libjxl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

CARGO_CRATES=	bon-3.9.3 \
		bon-macros-3.9.3 \
		bytemuck-1.25.1 \
		byteorder-1.5.0 \
		cc-1.2.67 \
		cfg-if-1.0.4 \
		cmake-0.1.58 \
		crunchy-0.2.4 \
		darling-0.23.0 \
		darling_core-0.23.0 \
		darling_macro-0.23.0 \
		find-msvc-tools-0.1.9 \
		half-2.7.1 \
		heck-0.5.0 \
		ident_case-1.0.1 \
		jpegxl-rs-0.15.0+libjxl-0.12.0 \
		jpegxl-src-0.12.0 \
		jpegxl-sys-0.13.0+libjxl-0.12.0 \
		libc-0.2.186 \
		once_cell-1.21.4 \
		pkg-config-0.3.33 \
		portable-atomic-1.13.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quote-1.0.46 \
		rustversion-1.0.23 \
		shlex-2.0.1 \
		strsim-0.11.1 \
		syn-2.0.119 \
		target-lexicon-0.13.5 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		unicode-ident-1.0.24 \
		zerocopy-0.8.54 \
		zerocopy-derive-0.8.54

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
