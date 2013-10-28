# Created by: gahr
# $FreeBSD$

PORTNAME=	seed7
DISTVERSION=	05_20131027
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-level, extensible programming language

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64 sparc64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
MAKE_ENV+=	S7_LIB_DIR=${S7_LIB_DIR} \
		SEED7_LIBRARY=${SEED7_LIBRARY} \
		C_COMPILER=${CC} \
		CPLUSPLUS_COMPILER=${CPP}

SEED7_LIBRARY=	${PREFIX}/lib/${PORTNAME}/lib
S7_LIB_DIR=	${PREFIX}/lib/${PORTNAME}/bin
S7_LIBS=	s7_comp.a s7_con.a s7_draw.a s7_data.a seed7_05.a

PORTEXAMPLES=	*
PORTDOCS=	*

.include <bsd.port.options.mk>

MAKEFILE=	mk_freebsd.mk

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;' ${WRKSRC}/${MAKEFILE}
#	${REINPLACE_CMD} -e '/FLOATTYPE_DOUBLE/s|undef|define|' ${WRKSRC}/config.h

do-build:
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} depend
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} s7 s7c

do-install:
#	install interpreter and compiler
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/s7 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/../prg/s7c ${STAGEDIR}${PREFIX}/bin
#	install seed7 library
	${INSTALL} -d ${STAGEDIR}${SEED7_LIBRARY}
	cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} '*.s7i' ${STAGEDIR}${SEED7_LIBRARY}
#	install static libraries
	${INSTALL} -d ${STAGEDIR}${S7_LIB_DIR}
.for s7_lib in ${S7_LIBS}
	${INSTALL_DATA} ${WRKSRC}/../bin/${s7_lib} ${STAGEDIR}${S7_LIB_DIR}
.endfor
#	install PORTDOCS
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif
#	install PORTEXAMPLES
.if ${PORT_OPTIONS:MEXAMPLES}
	${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} '*.dna *.sd7 *.dat *.s7i' ${STAGEDIR}${EXAMPLESDIR}
.endif
#	insall man pages
	${INSTALL_DATA} ${WRKSRC}/../doc/s7.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/../doc/s7c.1 ${STAGEDIR}${PREFIX}/man/man1

regression-test: build
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} test

.include <bsd.port.mk>
