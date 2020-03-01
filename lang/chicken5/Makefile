# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
DISTVERSION=	5.2.0
CATEGORIES=	lang scheme
MASTER_SITES=	https://code.call-cc.org/releases/${DISTVERSION}/
PKGNAMESUFFIX=	5

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Scheme-to-C compiler

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
		DOCDIR="${DOCSDIR}" \
		LIBDIR="${PREFIX}/lib" \
		LIBRARIAN="${AR}" \
		LINKER_OPTIONS="${LDFLAGS}" \
		MANDIR=${PREFIX}/man \
		PLATFORM=bsd \
		PREFIX=${PREFIX} \
		PROGRAM_SUFFIX="${PKGNAMESUFFIX}"
# parallel build not supported
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check

DATADIR=	${PREFIX}/share/chicken${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/chicken${PKGNAMESUFFIX}

PLIST_SUB=	BINARYVERSION=${_CHICKEN_BINARYVERSION} \
		SUFFIX=${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS FEATHERS
OPTIONS_SUB=	yes

# XXX: This should be a subpackage and on by default
FEATHERS_DESC=	Install the Feathers debugger (requires Tcl/Tk)

FEATHERS_USES=	tk:wrapper,run

_CHICKEN_BINARYVERSION=	11

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/c* \
		${STAGEDIR}${PREFIX}/lib/chicken${PKGNAMESUFFIX}/${_CHICKEN_BINARYVERSION}/*.so \
		${STAGEDIR}${PREFIX}/lib/libchicken${PKGNAMESUFFIX}.so

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
