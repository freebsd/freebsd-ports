# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ats
PORTVERSION=	${ATS_VER}
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}-lang/${PORTNAME}-lang/${ATS_IMPL}-${PORTVERSION}
DISTNAME=	${PORTNAME}-lang-${ATS_IMPL}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	Language with a type system rooted in the Applied Type System

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PORTDOCS=	FAQ.txt
PORTEXAMPLES=	AUP INTRO KernighanRitchie MISC MULTICORE TEST

OPTIONS_DEFINE=		GMP PCRE
OPTIONS_DEFAULT=	GMP PCRE

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	LIBDIR="lib64"
.else
PLIST_SUB+=	LIBDIR="lib"
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	gmp:${PORTSDIR}/math/gmp
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.endif

post-patch:
	${SED} -i '' -e 's/gcc/${CC}/' \
	    ${WRKSRC}/ccomp/runtime/GCATS/Makefile \
	    ${WRKSRC}/utils/scripts/Makefile \
	    ${WRKSRC}/libatsdoc/Makefile
	${SED} -i '' -e 's/ATSCCOMP_def "gcc"/ATSCCOMP_def "${CC}"/' \
	    ${WRKSRC}/utils/scripts/basics.dats
	${SED} -i '' -e 's/argv_p = "gcc"/argv_p = "${CC}"/' \
	             -e 's/execvp("gcc", argv)/execvp("${CC}", argv)/' \
	    ${WRKSRC}/utils/scripts/atslib.dats

post-configure:
.if empty(PORT_OPTIONS:MGMP)
	${SED} -i '' -e '/HAVE_GMP_H/d' ${WRKSRC}/config.h
.endif
.if empty(PORT_OPTIONS:MPCRE)
	${SED} -i '' -e '/HAVE_PCRE_H/d' ${WRKSRC}/config.h
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && \
	${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/doc/EXAMPLE && \
	${COPYTREE_SHARE} "${PORTEXAMPLES}" ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -name Makefile \
	    -exec ${SED} -i '' -e 's|^ATSUSRQ=.*|ATSUSRQ="${PREFIX}"|' {} \;
.endif

.include "bsd.ats.mk"
.include <bsd.port.post.mk>
