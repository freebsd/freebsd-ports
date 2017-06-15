# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googletest
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.8.0-11
DISTVERSIONSUFFIX=	-ga2b8a8e
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		autoreconf libtool
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
# fused-src python tests are only useful for bundling. There's no point in
# running them before installing system-wide without source files.
CONFIGURE_ENV=	ac_cv_path_PYTHON=":"
TEST_TARGET=	check
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
# enable vendor make install again (revert 661758e)
	@${REINPLACE_CMD} -E 's/install-(exec|data)-local/&-dummy/' \
		${WRKSRC}/Makefile.am

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gtest-config ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
