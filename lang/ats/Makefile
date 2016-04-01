# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ats
PORTVERSION=	${ATS_VER}
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-lang/${PORTNAME}-lang/${ATS_IMPL}-${PORTVERSION}
DISTNAME=	${PORTNAME}-lang-${ATS_IMPL}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language with a type system rooted in the Applied Type System

ONLY_FOR_ARCHS=	i386 amd64
USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=yes
PORTDOCS=	FAQ.txt
PORTEXAMPLES=	AUP INTRO KernighanRitchie MISC MULTICORE TEST

OPTIONS_DEFINE=	GMP PCRE DOCS EXAMPLES
OPTIONS_DEFAULT=	GMP PCRE
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	LIBDIR="lib64"
.else
PLIST_SUB+=	LIBDIR="lib"
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${ATS_LIBDIR_REL}/bin/*
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
	${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc/EXAMPLE && \
	${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${STAGEDIR}${EXAMPLESDIR} -name Makefile \
	    -exec ${SED} -i '' -e 's|^ATSUSRQ=.*|ATSUSRQ="${PREFIX}"|' {} \;

.include "bsd.ats.mk"
.include <bsd.port.post.mk>
