# $FreeBSD$

PORTNAME=	android-tools-adb
DISTVERSIONPREFIX=	platform-tools-
DISTVERSION?=	29.0.5
PORTREVISION?=	0
CATEGORIES=	devel comms

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_TUPLE=	aosp-mirror:platform_system_core:${DISTVERSIONFULL}

CONFLICTS_INSTALL?=	${PORTNAME}-devel-*

USES=		compiler:c++17-lang pkgconfig ssl uidfix
BUILD_WRKSRC=	${WRKSRC}/adb
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE?=	${.CURDIR}/files/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin" FILESDIR="${DOCSDIR}" \
		VERSION="${DISTVERSION}${DISTVERSIONSUFFIX}"
ALL_TARGET=	all
TEST_TARGET=	test
PLIST_FILES=	bin/adb
PORTDOCS=	*

# XXX Remove after FreeBSD 11.2/12.0 reach EOL i.e., around 2020-02-01
# XXX Switch to bundled libc++ to avoid error-prone reverts
.if !exists(/usr/include/c++/v1/charconv) && exists(/usr/lib/libc++.so)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-revert-d3d650628c8c
.endif

OPTIONS_DEFINE+=MDNSRESPONDER BASH DOCS TEST TEST_PYTHON
OPTIONS_DEFAULT=MDNSRESPONDER
OPTIONS_SUB=	yes

.if make(makesum) # for optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}"
.endif

BASH_GH_TUPLE=		mbrubeck:android-completion:c1b0656:bashcomp
BASH_PLIST_FILES=	etc/bash_completion.d/adb
BASH_VARS=		LICENSE+=MIT LICENSE_COMB=multi

DOCS_MAKE_ARGS_OFF=	FILES="" FILESDIR=""

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_USES=		localbase:ldflags
MDNSRESPONDER_LDFLAGS=		-ldns_sd
MDNSRESPONDER_MAKE_ENV_OFF=	MDNSEXT=_unsupported

TEST_BUILD_DEPENDS+=	googletest>=1.6.0:devel/googletest
TEST_ALL_TARGET=	adb_test

TEST_PYTHON_DESC=	${TEST_DESC:S/tests/python &/}
TEST_PYTHON_GH_TUPLE=	aosp-mirror:platform_development:${DISTVERSIONFULL}:development
TEST_PYTHON_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}
TEST_PYTHON_USES=	python:2.7,build

post-patch:
# XXX Hidden by poudriere/tinderbox, see lindev(4) for FreeBSD < 11.0
	@if [ ! -e /dev/full ]; then \
		${REINPLACE_CMD} -e '/TEST/s/[^ ]*ENOSPC/DISABLED_&/' \
			${WRKSRC}/adb/adb_io_test.cpp; \
	fi
# XXX getcwd fails and not connected upstream
	@${REINPLACE_CMD} -e '/TEST/s/, /&DISABLED_/' \
		${WRKSRC}/adb/bugreport_test.cpp

pre-install-TEST-on: do-test

pre-install-TEST_PYTHON-on:
# XXX python tests may leave behind running adb server
	${SETENV} PATH=${BUILD_WRKSRC}:${PATH} \
		PYTHONPATH=${WRKSRC_development}/python-packages \
		${PYTHON_CMD} -m unittest discover -vs ${BUILD_WRKSRC}

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${BASH_PLIST_FILES:H}
	${INSTALL_DATA} ${WRKSRC_bashcomp}/android \
		${STAGEDIR}${PREFIX}/${BASH_PLIST_FILES}

.include <bsd.port.mk>
