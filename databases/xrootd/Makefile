PORTNAME=	xrootd
DISTVERSION=	5.6.9
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://xrootd.slac.stanford.edu/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/xrootd/xrootd/commit/
PATCHFILES=	f9d573417e1abc263115a34fd5f95dca505379e5.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for fast, low latency, scalable data access
WWW=		https://xrootd.slac.stanford.edu/index.html

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libtinyxml.so:textproc/tinyxml \
		libuuid.so:misc/libuuid
TEST_DEPENDS=	cppunit>0:devel/cppunit \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++14-lang cpe gnome localbase:ldflags pkgconfig readline shebangfix ssl
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	utils/cms_monPerf
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

# options are defined in cmake/XRootDDefaults.cmake
CMAKE_ON=	FORCE_ENABLED
CMAKE_OFF=	ENABLE_PYTHON \
		ENABLE_SCITOKENS \
		ENABLE_FUSE
CMAKE_TESTING_ON=	ENABLE_TESTS

CXXFLAGS+=	-Ddirent64=dirent
LDFLAGS+=	-lexecinfo

TESTING_UNSAFE=	some tests hang on accept()

OPTIONS_DEFINE=		KERBEROS5
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	MACAROONS XRDCLHTTP
OPTIONS_DEFAULT=	KERBEROS5 XRDCLHTTP # MACAROONS
OPTIONS_SUB=		yes

KERBEROS5_CMAKE_BOOL=		ENABLE_KRB5
KERBEROS5_BUILD_DEPENDS=	${LOCALBASE}/lib/libkrb5.so:security/krb5
KERBEROS5_RUN_DEPENDS=		${LOCALBASE}/lib/libkrb5.so:security/krb5

MACAROONS_DESC=		Macaroons plugin
MACAROONS_CMAKE_BOOL=	ENABLE_MACAROONS
MACAROONS_BROKEN=	https://github.com/xrootd/xrootd/issues/2230

XRDCLHTTP_DESC=		xrdcl-http plugin
XRDCLHTTP_CMAKE_BOOL=	ENABLE_XRDCLHTTP
XRDCLHTTP_LIB_DEPENDS=	libdavix.so:www/davix

.include <bsd.port.mk>
