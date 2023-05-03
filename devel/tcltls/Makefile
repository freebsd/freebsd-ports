PORTNAME=	tcltls
PORTVERSION=	1.7.18
CATEGORIES=	devel security tcl
MASTER_SITES=	http://core.tcl.tk/tcltls/uv/ \
		http://tcltls.rkeene.org/uv/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Dynamically loadable SSL extensions for TCL
WWW=		https://core.tcl.tk/tcltls

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tcl:tea ssl

CONFIGURE_ARGS+=--with-ssl-dir=${OPENSSLBASE}	\
		--enable-ssl-fastpath	\
		--disable-rpath
CONFIGURE_ENV+=	PATH=${OPENSSLBASE}/bin:${PATH}

MAKE_ARGS+=	"PACKAGE_INSTALL_DIR=${PREFIX}/lib/${TCL_PKG}"
MAKE_ENV+=	PATH=${OPENSSLBASE}/bin:${PATH}
TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/tcltls.so \
		lib/${TCL_PKG}/pkgIndex.tcl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=       -Wno-error=int-conversion
.endif

post-patch:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
