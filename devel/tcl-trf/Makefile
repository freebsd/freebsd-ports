# New ports collection makefile for:	tcl-Trf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Trf
PORTVERSION=	2.1p2
PORTREVISION=	4
CATEGORIES=	devel tcl${TCL_VER:S/.//}
MASTER_SITES=	http://www.oche.de/~akupries/soft/trf/download/
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Data conversion, digests, compression, error-correction for Tcl

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//} \
		${LOCALBASE}/lib/tcl${TCL_VER}/Memchan/pkgIndex.tcl:${PORTSDIR}/devel/tcl-memchan

USE_BZIP2=	yes

ALL_TARGET=	all test

TCL_VER?=	8.4
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TCL_VER} \
		--enable-static-zlib --enable-static-bzlib \
		--enable-static-md5

post-extract:
	${RM} -rf ${WRKSRC}/compat

post-patch:
	# Make direct calls to -lbz2
	${REINPLACE_CMD} -E 's,bz\.([^(]+),BZ2_bz\1,g' \
		${WRKSRC}/generic/bz2.c
	${REINPLACE_CMD} -E \
		's,BZ2_bzcomp,BZ2_bzComp,g;s,BZ2_bzdecomp,BZ2_bzDecomp,g' \
		${WRKSRC}/generic/bz2.c
	# Make direct calls to -lz
	${REINPLACE_CMD} -E 's,zf\.([^(]+),\1,g' ${WRKSRC}/generic/adler.c \
		${WRKSRC}/generic/crc_zlib.c ${WRKSRC}/generic/zip.c
	# Don't re-invent the dynamic linker:
	${REINPLACE_CMD} 's,"loadman\.h","transformInt.h",' ${WRKSRC}/generic/*.c
.ifdef TRF_USE_MD
	#
	# Using FreeBSD's own -lmd instead of OpenSSL's -lcrypto
	#
	${REINPLACE_CMD} -E -e 's,openssl/,,'		\
		-e 's,(MD[25])_([A-Z][a-z]),\1\2,g'	\
		${WRKSRC}/generic/*.[ch]
	${REINPLACE_CMD} 's,-lcrypto,-lmd,' ${WRKSRC}/Makefile.in
.else
	#
	# Using OpenSSL's impelemtations of for message digests (-lcrypto)
	# To use FreeBSD's own -lmd, stop now and restart make with:
	#
	#	-DTRF_USE_MD
	#
USE_OPENSSL=	yes
.endif

post-install:
	${LN} -sf ${SHLIB_NAME} ${PREFIX}/lib/${SHLIB_LINK}
.ifndef(NOPORTDOCS)
	${RM} -f ${WRKSRC}/doc/html/*.orig
	${MKDIR} ${DOCSDIR}
	${CP} -pR ${WRKSRC}/doc/html/* ${DOCSDIR}
	${CHMOD} -R +r ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/painless-guide-to-crc.txt ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

SHLIB_NAME=	libTrf2.so.1
SHLIB_LINK=	${SHLIB_NAME:C/\.so\..*/.so/}

PLIST_SUB+=	SHLIB_NAME=${SHLIB_NAME} SHLIB_LINK=${SHLIB_LINK} \
		TCL_DVER=${TCL_VER:C/\.//}

.include <bsd.port.post.mk>
