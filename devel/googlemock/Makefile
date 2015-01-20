# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlemock
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE \
		https://googlemock.googlecode.com/svn-history/r407/trunk/scripts/:svn
DISTNAME=	gmock-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gmock_doctor.py:svn
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for writing and using C++ mock classes

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	googletest>=1.7.0:${PORTSDIR}/devel/googletest
LIB_DEPENDS=	libgtest.so:${PORTSDIR}/devel/googletest

USES=		libtool shebangfix zip
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

post-extract:
# XXX gmock_doctor.py is missing from distfile before r455 or 1.8.0
	${CP} ${DISTDIR}/gmock_doctor.py ${WRKSRC}/scripts

post-patch:
# enable vendor make install again (revert r562)
	${REINPLACE_CMD} -E 's/ install-(exec|data)-local//' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock_doctor.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
