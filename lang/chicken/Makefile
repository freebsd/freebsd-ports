PORTNAME=	chicken
DISTVERSION=	5.4.0
PORTEPOCH=	1
CATEGORIES=	lang scheme
MASTER_SITES=	https://code.call-cc.org/releases/${DISTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Scheme-to-C compiler
WWW=		https://www.call-cc.org/

LICENSE=	BSD3CLAUSE PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake
CPE_VENDOR=	call-cc
USE_LDCONFIG=	yes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	C_COMPILER="${CC}" \
		C_COMPILER_OPTIMIZATION_OPTIONS="${CFLAGS}" \
		CXX_COMPILER="${CXX}" \
		CSC_PROGRAM=chicken-csc \
		CSI_PROGRAM=chicken-csi \
		DOCDIR="${DOCSDIR}" \
		LIBDIR="${PREFIX}/lib" \
		LIBRARIAN="${AR}" \
		LINKER_OPTIONS="${LDFLAGS}" \
		MANDIR=${PREFIX}/share/man \
		PREFIX=${PREFIX}

TEST_TARGET=	check
TEST_ARGS=	${MAKE_ARGS} PROGRAM_PREFIX=chicken-

DATADIR=	${PREFIX}/share/chicken
DOCSDIR=	${PREFIX}/share/doc/chicken

PLIST_SUB=	BINARYVERSION=${_CHICKEN_BINARYVERSION}

OPTIONS_DEFINE=	DOCS FEATHERS
OPTIONS_SUB=	yes

# XXX: This should be a subpackage and on by default
FEATHERS_DESC=	Install the Feathers debugger (requires Tcl/Tk)

FEATHERS_USES=	tk:wrapper,run

_CHICKEN_BINARYVERSION=	11

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/c* \
		${STAGEDIR}${PREFIX}/lib/chicken/${_CHICKEN_BINARYVERSION}/*.so \
		${STAGEDIR}${PREFIX}/lib/libchicken.so

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
