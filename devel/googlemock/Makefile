# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlemock
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.8.0-358
DISTVERSIONSUFFIX=	-gf1a87d7
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for writing and using C++ mock classes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_pthread.m4:devel/autoconf-archive \
		googletest>=1.8.0:devel/googletest
LIB_DEPENDS=	libgtest.so:devel/googletest

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	googletest

USES=		autoreconf libtool localbase python:run shebangfix
SHEBANG_FILES=	scripts/gmock_doctor.py
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
# fused-src python tests are only useful for bundling. There's no point in
# running them before installing system-wide without source files.
CONFIGURE_ENV=	ac_cv_path_PYTHON=":"
TEST_TARGET=	check
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} '/acx_pthread.m4/d' ${WRKSRC}/configure.ac
# enable vendor make install again (revert 52277c9)
	@${REINPLACE_CMD} -E 's/install-(exec|data)-local/&-dummy/' \
		${WRKSRC}/Makefile.am

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock_doctor.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
