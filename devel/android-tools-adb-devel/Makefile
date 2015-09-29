# $FreeBSD$

DISTVERSION=	m-preview-1212
DISTVERSIONSUFFIX=	-g94c617ccbba4
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
MAKEFILE=	${.CURDIR}/files/Makefile
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files

USES=		compiler:c++11-lib
BUILD_WRKSRC=	${WRKSRC}/adb
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV=	FILESDIR="${FILESDIR}"
CPPFLAGS+=	-DADB_REVISION='\"${DISTVERSIONSUFFIX:S/-g//}-android\"'
ALL_TARGET=	all

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=googletest>=1.6.0:${PORTSDIR}/devel/googletest \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock
TEST_USES=	python:2.7,build
TEST_ALL_TARGET=adb_test

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
# XXX python tests may leave behind running adb server
	PATH=${BUILD_WRKSRC}:${PATH} PYTHONPATH=${WRKSRC} \
		${PYTHON_CMD} ${BUILD_WRKSRC}/test_adb.py
	PATH=${BUILD_WRKSRC}:${PATH} PYTHONPATH=${WRKSRC} \
		${PYTHON_CMD} ${BUILD_WRKSRC}/test_device.py

.include "${MASTERDIR}/Makefile"
