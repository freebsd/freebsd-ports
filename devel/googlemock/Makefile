# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlemock
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	release-
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for writing and using C++ mock classes

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_pthread.m4:${PORTSDIR}/devel/autoconf-archive \
		googletest>=1.7.0:${PORTSDIR}/devel/googletest
LIB_DEPENDS=	libgtest.so:${PORTSDIR}/devel/googletest

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		autoreconf libtool shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	ac_cv_path_PYTHON=python2
python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	scripts/fuse_gmock_files.py scripts/gmock_doctor.py

OPTIONS_DEFINE=	TEST

TEST_USES=	python:2,build
TEST_ALL_TARGET=check

post-patch:
	${REINPLACE_CMD} '/acx_pthread.m4/d' ${WRKSRC}/configure.ac
# enable vendor make install again (revert 52277c9)
	${REINPLACE_CMD} -E 's/install-(exec|data)-local/&-dummy/' \
		${WRKSRC}/Makefile.am

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock_doctor.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
