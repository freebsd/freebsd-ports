# Created by: gahr
# $FreeBSD$

PORTNAME=	seed7
DISTVERSION=	05_20161231
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-level, extensible programming language

# The language libraries are licensed under the LGPL21 license. Starting from
# version 05_20140601, the compiler libraries are also distributed. These are
# licensed under the GPLv2 and can be found in ${PREFIX}/lib/seed7/lib/comp.
LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		ncurses tar:tgz
USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64 sparc64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKE_ENV+=	S7_LIB_DIR=${S7_LIB_DIR} \
		SEED7_LIBRARY=${SEED7_LIBRARY} \
		C_COMPILER=${CC} \
		CPLUSPLUS_COMPILER=${CPP}

SEED7_LIBRARY=	${PREFIX}/lib/${PORTNAME}/lib
S7_LIB_DIR=	${PREFIX}/lib/${PORTNAME}/bin
S7_LIBS=	s7_comp.a s7_con.a s7_draw.a s7_data.a seed7_05.a

PORTEXAMPLES=	*
PORTDOCS=	*

MAKEFILE=	mk_freebsd.mk

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;' \
		-e 's|^CFLAGS = |CFLAGS = -I${NCURSESINC} |' \
		${WRKSRC}/${MAKEFILE}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} depend
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} s7 s7c

do-install:
#	install interpreter and compiler
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/s7 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/../prg/s7c ${STAGEDIR}${PREFIX}/bin
#	install seed7 library
	${INSTALL} -d ${STAGEDIR}${SEED7_LIBRARY}/comp
	cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} '*.s7i' ${STAGEDIR}${SEED7_LIBRARY}
	cd ${WRKSRC}/../lib/comp && ${COPYTREE_SHARE} '*.s7i' ${STAGEDIR}${SEED7_LIBRARY}/comp
#	install static libraries
	${INSTALL} -d ${STAGEDIR}${S7_LIB_DIR}
.for s7_lib in ${S7_LIBS}
	${INSTALL_DATA} ${WRKSRC}/../bin/${s7_lib} ${STAGEDIR}${S7_LIB_DIR}
.endfor
#	install PORTDOCS
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
#	install PORTEXAMPLES
	${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} '*.dna *.sd7 *.dat *.s7i' ${STAGEDIR}${EXAMPLESDIR}
#	insall man pages
	${INSTALL_DATA} ${WRKSRC}/../doc/s7.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/../doc/s7c.1 ${STAGEDIR}${PREFIX}/man/man1

do-test:
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} test

.include <bsd.port.mk>
