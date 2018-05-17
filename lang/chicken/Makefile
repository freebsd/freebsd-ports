# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
PORTVERSION=	4.12.0
PORTEPOCH=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://code.call-cc.org/releases/${PORTVERSION}/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme-to-C compiler

USES=		cpe gmake
CPE_VENDOR=	call-cc
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_ARGS+=	PLATFORM=bsd \
		PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/man \
		LIBDIR="${PREFIX}/lib" \
		DOCDIR="${DOCSDIR}" \
		ARCH=${NEW_ARCH} \
		C_COMPILER="${CC}" \
		CXX_COMPILER="${CXX}" \
		LIBRARIAN="${AR}" \
		C_COMPILER_OPTIMIZATION_OPTIONS="${CFLAGS}"
TEST_TARGET=	check

NEW_ARCH=	${ARCH:S/i386/x86/:S/amd64/x86-64/}

OPTIONS_DEFINE=	DOCS FEATHERS
FEATHERS_DESC=	Install the Feathers debugger (requires Tcl/Tk)

FEATHERS_RUN_DEPENDS=\
		wish:x11-toolkits/tk-wrapper

OPTIONS_SUB=	yes

post-patch-FEATHERS-off:
	@${REINPLACE_CMD} \
		-e 's/feathers.1//g' \
		-e '/INSTALL_PROGRAM.*_DEBUGGER_/{N;d;}' \
		-e '/INSTALL_PROGRAM.*feathers/d' \
		${WRKSRC}/rules.make

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken-bug
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken-install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken-profile
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken-status
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chicken-uninstall
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/csc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/csi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/chicken/8/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libchicken.so.8

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
