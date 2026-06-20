PORTNAME=	cbmc
DISTVERSIONPREFIX=	cbmc-
DISTVERSION=	6.9.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	DEBIAN/pool/main/m/minisat2:minisat
DISTFILES=	minisat2_2.2.1.orig.tar.gz:minisat

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Bounded Model Checker for C and C++ programs
WWW=		https://github.com/diffblue/cbmc

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	flex:textproc/flex \
		bash:shells/bash \
		git:devel/git@lite \
		jq:textproc/jq
RUN_DEPENDS=	cvc5:math/cvc5 \
		z3:math/z3

USES=		cmake bison python shebangfix perl5
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	diffblue
SHEBANG_FILES=	${WRKSRC}/scripts/ls_parse.py

CMAKE_OFF=	WITH_JBMC

pre-extract:
	${MKDIR} ${BUILD_WRKSRC}/minisat2-download/minisat2-download-prefix/src
	${CP} ${DISTDIR}/minisat2_2.2.1.orig.tar.gz ${BUILD_WRKSRC}/minisat2-download/minisat2-download-prefix/src/

do-test:
	cd ${BUILD_WRKSRC} && ctest . -V -L CORE

.include <bsd.port.mk>
