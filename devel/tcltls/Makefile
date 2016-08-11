# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	tcltls
PORTVERSION=	1.6.7
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tls/tls/${PORTVERSION}
DISTNAME=	tls${PORTVERSION}-src

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	SSL extensions for TCL; dynamicly loadable

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	DOCS

USES+=		tcl:tea
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl-dir=${OPENSSLBASE}

WRKSRC=		${WRKDIR}/${TCL_PKG}
PLIST_FILES=	lib/${TCL_PKG}/libtls.so.1 \
		lib/${TCL_PKG}/pkgIndex.tcl \
		lib/${TCL_PKG}/tls.tcl
PORTDOCS=	*
INSTALL_TARGET=	install-binaries install-doc

post-patch:
	${REINPLACE_CMD} -e \
		's,package require tls.*,load ${WRKSRC}/libtls.so.1;\
			source ${WRKSRC}/tls.tcl,' \
		${WRKSRC}/tests/*.test
	# The tests in ciphers.test are meaningless so far:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${STAGEDIR}${DOCSDIR}

xregression-test test check: build
	cd ${WRKSRC}/tests && ${SETENV} TCL_LIBRARY="${WRKSRC}" \
		tclsh${TCL_VER} all.tcl

.include <bsd.port.mk>
