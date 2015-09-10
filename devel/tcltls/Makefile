# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	tcltls
PORTVERSION=	1.6.4
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

USES+=		tcl
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-ssl-dir=${OPENSSLBASE}

TCLPKG=		tls${PORTVERSION}
WRKSRC=		${WRKDIR}/${TCLPKG}
PLIST_FILES=	include/tls.h \
		lib/${TCLPKG}/libtls.so.1 \
		lib/${TCLPKG}/pkgIndex.tcl \
		lib/${TCLPKG}/tls.tcl
PORTDOCS=	*

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
