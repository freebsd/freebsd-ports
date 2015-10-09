# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-1280
DISTVERSIONSUFFIX=	-g659f5ade04a5
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files

USES=		compiler:c++11-lib
BUILD_WRKSRC=	${WRKSRC}/adb
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV=	FILESDIR="${FILESDIR}"
CPPFLAGS+=	-DADB_REVISION='\"${DISTVERSIONSUFFIX:S/-g//}-android\"'
ALL_TARGET=	all

OPTIONS_DEFINE=	TEST TEST_PYTHON

TEST_BUILD_DEPENDS=	googletest>=1.6.0:${PORTSDIR}/devel/googletest
TEST_ALL_TARGET=	adb_test

TEST_PYTHON_DESC=	${TEST_DESC:S/tests/python &/}
TEST_PYTHON_GH_PROJECT=	platform_development:development
TEST_PYTHON_GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-66-ge4cded6:development
TEST_PYTHON_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock
TEST_PYTHON_USES=	python:2.7,build

post-patch:	slave-post-patch
slave-post-patch:
# XXX C++ exception with description "regex_error" thrown in the test body.
	@if [ ${OPSYS} = FreeBSD -a ${OSREL:R} -lt 10 ]; then \
		${REINPLACE_CMD} -Ee '/^TEST/\
			s/ (LOG|PLOG|UNIMPLEMENTED)/ DISABLED_\1/' \
		${WRKSRC}/base/logging_test.cpp; \
	fi
.if defined(PACKAGE_BUILDING)
# XXX /dev/full isn't mounted by poudriere/tinderbox
	@${REINPLACE_CMD} -e '/^TEST/s/[^ ]*ENOSPC/DISABLED_&/' \
		${WRKSRC}/adb/adb_io_test.cpp
.endif

pre-install-TEST-on:
	${BUILD_WRKSRC}/adb_test

pre-install-TEST_PYTHON-on:
# XXX python tests may leave behind running adb server
# test_adb.py remains in core repository for some reason
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} ${BUILD_WRKSRC}/test_adb.py
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} ${WRKSRC_development}/python-packages/adb/test_device.py

.include "${MASTERDIR}/Makefile"
