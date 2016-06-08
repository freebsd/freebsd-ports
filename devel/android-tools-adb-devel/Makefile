# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-n-preview-3
DISTVERSION=	n-preview-3-101
DISTVERSIONSUFFIX=	-g35d84096e9a5
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}

OPTIONS_DEFINE=	TEST_PYTHON

TEST_PYTHON_DESC=	${TEST_DESC:S/tests/python &/}
TEST_PYTHON_GH_PROJECT=	platform_development:development
TEST_PYTHON_GH_TAGNAME=	${GH_MYTAG}-47-g6925e3e:development
TEST_PYTHON_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
TEST_PYTHON_USES=	python:2.7,build

pre-install-TEST_PYTHON-on:
# XXX python tests may leave behind running adb server
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} -m unittest discover -vs ${BUILD_WRKSRC}

.include "${MASTERDIR}/Makefile"
