# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
DISTVERSION=	4.13.0
PORTEPOCH=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://code.call-cc.org/releases/${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Scheme-to-C compiler

DEPRECATED=	Old release; please migrate to lang/chicken5
EXPIRATION_DATE=	2019-12-20

USES=		cpe gmake
CPE_VENDOR=	call-cc
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
		LINKER_OPTIONS="${LDFLAGS}"
TEST_TARGET=	check

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS FEATHERS
OPTIONS_SUB=	yes

# XXX: This should be a subpackage and on by default
FEATHERS_DESC=	Install the Feathers debugger (requires Tcl/Tk)

FEATHERS_USES=	tk:wrapper,run

post-patch-FEATHERS-off:
	@${REINPLACE_CMD} \
		-e 's/feathers.1//g' \
		-e '/INSTALL_PROGRAM.*_DEBUGGER_/{N;d;}' \
		-e '/INSTALL_PROGRAM.*feathers/d' \
		${WRKSRC}/rules.make

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/c* \
		${STAGEDIR}${PREFIX}/lib/chicken/?/*.so \
		${STAGEDIR}${PREFIX}/lib/libchicken.so

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
