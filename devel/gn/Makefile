# $FreeBSD$

PORTNAME=	gn
DISTVERSIONPREFIX=	v
DISTVERSION=	1592
CATEGORIES=	devel

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Gn meta build framework - standalone version

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang ninja python:2.7,build

USE_GITHUB=	yes
GH_ACCOUNT=	cglogic # mirror

CONFLICTS_INSTALL=	chromimum-gn*

PLIST_FILES=	bin/gn

do-configure:
	cd ${WRKSRC} && GN_VERSION=${PORTVERSION} ${PYTHON_CMD} build/gen.py

do-build:
	cd ${WRKSRC} && ninja -C out

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/gn ${STAGEDIR}${PREFIX}/bin

do-test: build
	cd ${WRKSRC} && ./out/gn_unittests

.include <bsd.port.mk>
