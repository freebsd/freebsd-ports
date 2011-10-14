# New ports collection makefile for: ats
# Date created: September 29 2011
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ats
PORTVERSION=	${ATS_VER}
CATEGORIES?=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-lang/${PORTNAME}-lang/${ATS_IMPL}-${PORTVERSION}
DISTNAME=	${PORTNAME}-lang-${ATS_IMPL}-${PORTVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a type system rooted in the Applied Type System

OPTIONS=	GMP	"Build with GMP support" on \
		PCRE	"Build with PCRE support" on

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PORTDOCS=	FAQ.txt BOOK TUTORIAL
PORTEXAMPLES=	AUP INTRO KernighanRitchie MISC MULTICORE TEST

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	LIBDIR="lib64"
.else
PLIST_SUB+=	LIBDIR="lib"
.endif

.if !defined(WITHOUT_GMP)
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

post-configure:
.if defined(WITHOUT_GMP)
	${SED} -i '' -e '/HAVE_GMP_H/d' ${WRKSRC}/config.h
.endif
.if defined(WITHOUT_PCRE)
	${SED} -i '' -e '/HAVE_PCRE_H/d' ${WRKSRC}/config.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for x in ${PORTDOCS}
	cd ${WRKSRC}/doc; \
	${FIND} ${x} -type d -exec ${INSTALL} -d ${DOCSDIR}/{} \;
.endfor
.for x in ${PORTDOCS}
	cd ${WRKSRC}/doc; \
	${FIND} ${x} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for x in ${PORTEXAMPLES}
	cd ${WRKSRC}/doc/EXAMPLE; \
	${FIND} ${x} -type d -exec ${INSTALL} -d ${EXAMPLESDIR}/{} \;
.endfor
.for x in ${PORTEXAMPLES}
	cd ${WRKSRC}/doc/EXAMPLE; \
	${FIND} ${x} -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endfor
	${FIND} ${EXAMPLESDIR} -name Makefile \
	    -exec ${SED} -i '' -e 's|^ATSUSRQ=.*|ATSUSRQ="${PREFIX}"|' {} \;
.endif

.include "bsd.ats.mk"
.include <bsd.port.post.mk>
