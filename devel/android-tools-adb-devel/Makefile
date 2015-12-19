# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-5956
DISTVERSIONSUFFIX=	-g461a29540c01
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

OPTIONS_DEFINE=	TEST_PYTHON

TEST_PYTHON_DESC=	${TEST_DESC:S/tests/python &/}
TEST_PYTHON_GH_PROJECT=	platform_development:development
TEST_PYTHON_GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-2510-g72f24a0:development
TEST_PYTHON_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock
TEST_PYTHON_USES=	python:2.7,build

pre-install-TEST_PYTHON-on:
# XXX python tests may leave behind running adb server
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} -m unittest discover -vs ${BUILD_WRKSRC}

.include "${MASTERDIR}/Makefile"
