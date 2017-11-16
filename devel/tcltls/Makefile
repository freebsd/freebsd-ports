# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	tcltls
PORTVERSION=	1.7.14
CATEGORIES=	devel security tcl
MASTER_SITES=	http://core.tcl.tk/tcltls/uv/ \
		http://tcltls.rkeene.org/uv/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	SSL extensions for TCL; dynamicly loadable

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	DOCS

USES+=		tcl:tea ssl
CONFIGURE_ARGS+=--with-ssl-dir=${OPENSSLBASE}	\
		--enable-ssl-fastpath	\
		--disable-rpath

PLIST_FILES=	lib/${TCL_PKG}/tcltls.so \
		lib/${TCL_PKG}/pkgIndex.tcl
PORTDOCS=	*
MAKE_ARGS+=	"PACKAGE_INSTALL_DIR=${PREFIX}/lib/${TCL_PKG}"
TEST_TARGET=	test
MAKE_ENV+=	PATH=${OPENSSLBASE}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${OPENSSLBASE}/bin:${PATH}

post-patch:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
