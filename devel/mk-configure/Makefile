PORTNAME=	mk-configure
PORTVERSION=	0.40.0
CATEGORIES=	devel
MASTER_SITES=	SF/mk-configure/mk-configure/mk-configure-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight, easy to use replacement for GNU autotools
WWW=		https://sourceforge.net/projects/mk-configure/ \
		https://github.com/cheusov/mk-configure

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

INSTALL_TARGET=	installdirs install install-doc
MAKE_ARGS=	MANDIR=${PREFIX}/share/man
MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	${SETENV} NOSUBDIR="tests/pkg_config_2 tests/predopost_targets \
		tests/lua_dirs examples/hello_lua examples/hello_lua2 \
		examples/hello_lua3" CPPFLAGS='-I/usr/local/include' \
		LDFLAGS='-L/usr/local/lib -Wl,-rpath /usr/local/lib' \
		${INSTALL_WRKSRC}/scripts/mkcmake -C ${INSTALL_WRKSRC} test

.include <bsd.port.mk>
