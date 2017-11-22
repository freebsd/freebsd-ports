# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	mk-configure
PORTVERSION=	0.29.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Lightweight, easy to use replacement for GNU autotools

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${BMAKE}:devel/bmake
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		bmkdep:devel/bmkdep

BMAKE?=		${LOCALBASE}/bin/bmake
INSTALL_TARGET=	installdirs install install-doc

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${ECHO_CMD} "MKDEP ?= bmkdep" >> ${WRKSRC}/mk/sys.mk

do-build:
	${SETENV} ${MAKE_ENV} ${BMAKE} -C ${BUILD_WRKSRC} ${MAKE_FLAGS} \
		${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${SETENV} ${MAKE_ENV} ${BMAKE} -C ${INSTALL_WRKSRC} ${MAKE_FLAGS} \
		${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${INSTALL_TARGET}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	${SETENV} NOSUBDIR="tests/pkg_config_2 tests/predopost_targets \
		tests/lua_dirs examples/hello_lua examples/hello_lua2 \
		examples/hello_lua3" CPPFLAGS='-I/usr/local/include' \
		LDFLAGS='-L/usr/local/lib -Wl,-rpath /usr/local/lib' \
		${INSTALL_WRKSRC}/scripts/mkcmake -C ${INSTALL_WRKSRC} test

.include <bsd.port.mk>
