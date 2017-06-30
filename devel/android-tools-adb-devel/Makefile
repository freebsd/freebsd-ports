# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-o-preview-2
DISTVERSION=	o-preview-2-332
DISTVERSIONSUFFIX=	-gd1e9e7bc06f0
PORTREVISION=	1
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}

USES=		compiler:c++14-lang

OPTIONS_DEFAULT=MDNSRESPONDER
OPTIONS_DEFINE=	MDNSRESPONDER TEST_PYTHON

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_USES=		localbase:ldflags
MDNSRESPONDER_LDFLAGS=		-ldns_sd
MDNSRESPONDER_MAKE_ENV_OFF=	MDNSEXT=_unsupported

TEST_BROKEN=	logging.* tests always fail after 4e5fd111d84d

TEST_PYTHON_DESC=	${TEST_DESC:S/tests/python &/}
TEST_PYTHON_GH_PROJECT=	platform_development:development
TEST_PYTHON_GH_TAGNAME=	${GH_MYTAG}-83-gc5efdcc74:development
TEST_PYTHON_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
TEST_PYTHON_USES=	python:2.7,build

pre-install-TEST_PYTHON-on:
# XXX python tests may leave behind running adb server
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} -m unittest discover -vs ${BUILD_WRKSRC}

.include "${MASTERDIR}/Makefile"
