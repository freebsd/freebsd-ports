PORTNAME=	tcltls
PORTVERSION=	1.7.22
PORTREVISION=	1
CATEGORIES=	devel security tcl
MASTER_SITES=	http://core.tcl.tk/tcltls/uv/ \
		http://tcltls.rkeene.org/uv/

MAINTAINER=	ports@virtual-estates.net
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

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

post-patch:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken
	${REINPLACE_CMD} '/^#define CONST84/s|$$| const|' ${WRKSRC}/tlsInt.h

# Newer openssl-dhparam has no "-C" option, we emulate it here :-/
post-configure:
	${CP} ${FILESDIR}/dh_params.h ${WRKSRC}/
	${OPENSSLBASE}/bin/openssl dhparam -text 2048 | \
	    ${OPENSSLBASE}/bin/openssl asn1parse | \
	    ${SED} -E \
		-e '/hl=4 l= 257 prim/bp' \
		-e d -e :p \
		-e 's/    4:d=1.*INTEGER *://' \
		-e 's/([0-9A-H]{2})/0x\1, /g' \
		-e 'w${WRKSRC}/generateddh.txt'

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
