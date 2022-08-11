PORTNAME=	gn
DISTVERSIONPREFIX=	v
DISTVERSION=	1962
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Gn meta build framework - standalone version

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_riscv64=		fails to build: ../src/util/build_config.h:168:2: Please add support for your architecture in build_config.h

USES=		alias compiler:c++17-lang ninja python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	cglogic # mirror
SHEBANG_FILES=	${CONFIGURE_SCRIPT}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	build/gen.py
CONFIGURE_ARGS=	--platform freebsd ${WITH_DEBUG:D--debug}
CONFIGURE_ENV=	GN_VERSION=${PORTVERSION}
CONFIGURE_OUTSOURCE=	yes
ALL_TARGET=	# empty

CONFLICTS_INSTALL=	chromium-gn

CONFIGURE_WRKSRC=	${WRKSRC}/out # --out-path breaks "make test"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's/"python3"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/src/gn/exec_process_unittest.cc

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-test:
	${TEST_WRKSRC}/gn_unittests

.include <bsd.port.mk>
