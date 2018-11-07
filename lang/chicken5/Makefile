# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
DISTVERSION=	5.0.0
CATEGORIES=	lang scheme
MASTER_SITES=	https://code.call-cc.org/releases/${DISTVERSION}/
PKGNAMESUFFIX=	5

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Scheme-to-C compiler

USES=		cpe gmake
CPE_VENDOR=	call-cc
DATADIR=	${PREFIX}/share/chicken${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/chicken${PKGNAMESUFFIX}
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_ARGS=	PLATFORM=bsd \
		PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/man \
		LIBDIR="${PREFIX}/lib" \
		DOCDIR="${DOCSDIR}" \
		C_COMPILER="${CC}" \
		CXX_COMPILER="${CXX}" \
		LIBRARIAN="${AR}" \
		C_COMPILER_OPTIMIZATION_OPTIONS="${CFLAGS}" \
		LINKER_OPTIONS="${LDFLAGS}" \
		PROGRAM_SUFFIX="${PKGNAMESUFFIX}"
MAKE_JOBS_UNSAFE=	yes # parallel build not supported
PLIST_SUB=	SUFFIX=${PKGNAMESUFFIX}
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS FEATHERS
OPTIONS_SUB=	yes

# XXX: This should be a subpackage and on by default
FEATHERS_DESC=	Install the Feathers debugger (requires Tcl/Tk)

FEATHERS_USES=	tk:wrapper,run

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/c* \
		${STAGEDIR}${PREFIX}/lib/chicken${PKGNAMESUFFIX}/?/*.so \
		${STAGEDIR}${PREFIX}/lib/libchicken${PKGNAMESUFFIX}.so

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
