# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	opennurbs
PORTVERSION=	20130711
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://files.na.mcneel.com/opennurbs/5.0/2013-07-11/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Tools to accurately transfer 3-D geometry between applications

LICENSE_FILE=	${WRKSRC}/readme.txt

USES=		iconv:build dos2unix gmake zip
MAKE_ARGS=	CC="${CC}" CCC="${CXX}"

MAKEFILE=	makefile
BINEXAMPLESDIR=	${PREFIX}/libexec/openNURBS
MKFILE=		${EXAMPLESDIR}/bsd.openNURBS.mk

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/lib/libz)
IGNORE=	needs SRC_BASE to compile. Install base system sources and try again
.endif

.if ${ARCH} != i386
MAKE_ARGS+=	ON_GNU_OPTIMIZER_FLAGS="-g -fPIC"
.endif

pre-build:
	${ICONV_CMD} -c -f utf-8 -t ascii ${WRKSRC}/opennurbs_version.h \
		> ${WRKSRC}/opennurbs_version.h.tmp || ${TRUE}
	${MV} ${WRKSRC}/opennurbs_version.h.tmp ${WRKSRC}/opennurbs_version.h
	${MV} ${WRKSRC}/zlib ${WRKSRC}/zlib_
	${CP} -R ${SRC_BASE}/lib/libz ${WRKSRC}/zlib

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${BINEXAMPLESDIR} \
		${STAGEDIR}${PREFIX}/include/openNURBS/zlib
	${INSTALL_DATA} ${WRKSRC}/libopenNURBS.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/examples_linking_pragmas.h \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/opennurbs.h ${STAGEDIR}${EXAMPLESDIR}
	${PRINTF} "CFLAGS+=-I${PREFIX}/include/openNURBS -I$$\{.CURDIR\}\n" \
		> ${STAGEDIR}${MKFILE}
	@echo "LDADD+=-L${PREFIX}/lib -lm -lopenNURBS" >> ${STAGEDIR}${MKFILE}
	${PRINTF} ".PATH: $$\{.CURDIR\}/../example_userdata\n" \
		>> ${STAGEDIR}${MKFILE}
	echo "NO_MAN=YES" >> ${STAGEDIR}${MKFILE}
	echo ".include <bsd.prog.mk>" >> ${STAGEDIR}${MKFILE}
	${PRINTF} "SUBDIR =" > ${STAGEDIR}${EXAMPLESDIR}/Makefile
.for i in brep read roundtrip userdata write
	${PRINTF} " example_${i}" >> ${STAGEDIR}${EXAMPLESDIR}/Makefile
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_${i}
	${INSTALL_DATA} ${WRKSRC}/example_${i}/example_${i}.cpp \
		${STAGEDIR}${EXAMPLESDIR}/example_${i}/example_${i}.cc
	echo "PROG_CXX=example_${i}" \
		> ${STAGEDIR}${EXAMPLESDIR}/example_${i}/Makefile
	echo "SRCS=example_${i}.cc example_ud.cc" \
		>> ${STAGEDIR}${EXAMPLESDIR}/example_${i}/Makefile
	echo ".include \"../bsd.openNURBS.mk\"" \
		>> ${STAGEDIR}${EXAMPLESDIR}/example_${i}/Makefile
	${INSTALL_PROGRAM} ${WRKSRC}/example_${i}/example_${i} \
		${STAGEDIR}${BINEXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/example_userdata/example_ud.cpp \
		${STAGEDIR}${EXAMPLESDIR}/example_userdata/example_ud.cc
	${INSTALL_DATA} ${WRKSRC}/example_userdata/example_ud.h \
		${STAGEDIR}${EXAMPLESDIR}/example_userdata/example_ud.h
	${PRINTF} "\n.include <bsd.subdir.mk>\n" \
		>> ${STAGEDIR}${EXAMPLESDIR}/Makefile
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/openNURBS/
	${INSTALL_DATA} ${WRKSRC}/zlib/*.h \
		${STAGEDIR}${PREFIX}/include/openNURBS/zlib

.include <bsd.port.post.mk>
