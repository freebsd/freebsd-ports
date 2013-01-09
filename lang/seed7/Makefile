# Created by: gahr
# $FreeBSD$

PORTNAME=	seed7
DISTVERSION=	05_20130105
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-level, extensible programming language

LICENSE=	LGPL21

USE_GMAKE=	yes
USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64 sparc64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
MAKE_ENV+=	S7_LIB_DIR=${S7_LIB_DIR} \
		SEED7_LIBRARY=${SEED7_LIBRARY} \
		C_COMPILER=${CC} \
		CPLUSPLUS_COMPILER=${CPP}
ALL_TARGET=	depend s7

SEED7_LIBRARY=	${PREFIX}/lib/${PORTNAME}/lib
S7_LIB_DIR=	${PREFIX}/lib/${PORTNAME}/bin
S7_LIBS=	s7_comp.a s7_con.a s7_draw.a s7_data.a seed7_05.a

PORTEXAMPLES=	*
PORTDOCS=	*

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;' ${WRKSRC}/makefile
	${REINPLACE_CMD} -e '/FLOATTYPE_DOUBLE/s|undef|define|' ${WRKSRC}/config.h
	${REINPLACE_CMD} -i '' -e 's|./s7|${PREFIX}/bin/s7|g' ${WRKSRC}/../prg/chk_all.sd7

do-install:
#	install interpreter
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/s7 ${PREFIX}/bin
#	install seed7 library
	${INSTALL} -d ${SEED7_LIBRARY}
	cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} '*.s7i' ${SEED7_LIBRARY}
#	install static libraries
	${INSTALL} -d ${S7_LIB_DIR}
.for s7_lib in ${S7_LIBS}
	${INSTALL_DATA} ${WRKSRC}/../bin/${s7_lib} ${S7_LIB_DIR}
.endfor
#	compile the seed7 compiler (needs the libraries to be installed)
	cd ${WRKSRC} && ${GMAKE} s7c
	${INSTALL_PROGRAM} ${WRKSRC}/../prg/s7c ${PREFIX}/bin/s7c
	${RM} ${WRKSRC}/../prg/tmp_s7c.c ${WRKSRC}/../prg/s7c
#	install PORTDOCS
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
#	install PORTEXAMPLES
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} '*.dna *.sd7 *.dat *.s7i' ${EXAMPLESDIR}
.endif

regression-test: ${INSTALL_TARGET}
	@echo ""
	@echo "Testing the ${PORTNAME} installation"
	@(cd ${WRKSRC}/../prg && ${PREFIX}/bin/s7 chk_all)

.include <bsd.port.post.mk>
