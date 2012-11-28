# Created by: gahr
# $FreeBSD$

PORTNAME=	seed7
DISTVERSION=	05_20121125
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A high-level, extensible programming language

LICENSE=	LGPL21

USE_GMAKE=	yes
USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64 sparc64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
MAKE_ENV+=	S7_LIB_DIR=${PREFIX}/lib/seed7 \
		SEED7_LIBRARY=${PREFIX}/lib/seed7 \
		C_COMPILER=${CC} \
		CPLUSPLUS_COMPILER=${CPP}
ALL_TARGET=	depend hi

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;' ${WRKSRC}/makefile
	${REINPLACE_CMD} -i '' -e 's|./hi|${PREFIX}/bin/hi|g' ${WRKSRC}/../prg/chk_all.sd7

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/hi ${PREFIX}/bin
	${INSTALL} -d ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} \* ${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/../bin/s7_comp.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/../bin/s7_con.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/../bin/s7_draw.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/../bin/s7_data.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/../bin/seed7_05.a ${PREFIX}/lib/${PORTNAME}

post-install:
#	compile the seed7 compiler (needs the libraries to be installed)
	cd ${WRKSRC}/../prg && ./hi comp -O2 comp
	${INSTALL_PROGRAM} ${WRKSRC}/../prg/comp ${PREFIX}/bin/hi_comp
	${RM} ${WRKSRC}/../prg/tmp_comp.c ${WRKSRC}/../prg/comp
#	install PORTDOCS
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
#	install PORTEXAMPLES
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

test: ${INSTALL_TARGET}
	@echo ""
	@echo "Testing the ${PORTNAME} installation"
	@(cd ${WRKSRC}/../prg && ${PREFIX}/bin/hi chk_all)

.include <bsd.port.post.mk>
