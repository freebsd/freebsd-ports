# New ports collection makefile for:	tcl-Trf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Trf
PORTVERSION=	2.1p2
PORTREVISION=	1
CATEGORIES=	devel tcl83
MASTER_SITES=	http://www.oche.de/~akupries/soft/trf/download/
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}

USE_BZIP2=	yes

ALL_TARGET=	all test
MAKE_ARGS+=	-j2

TCL_VER?=		8.3
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TCL_VER} \
		--enable-static-zlib --enable-static-bzlib \
		--enable-static-md5

post-extract:
	${RM} -rf ${WRKSRC}/compat

post-patch:
	# Make direct calls to -lbz2
	${PERL} -pi -e 's,bz\.([^(]+),BZ2_bz\u\1,g' \
		${WRKSRC}/generic/bz2.c
	# Make direct calls to -lz
	${PERL} -pi -e 's,zf\.([^(]+),\1,g' ${WRKSRC}/generic/adler.c \
		${WRKSRC}/generic/crc_zlib.c ${WRKSRC}/generic/zip.c

post-install:
	${LN} -sf ${SHLIB_NAME} ${PREFIX}/lib/${SHLIB_LINK}
.ifndef(NOPORTDOCS)
	${RM} -f ${WRKSRC}/doc/html/*.orig
	${MKDIR} ${DOCSDIR}
	${CP} -pR ${WRKSRC}/doc/html/* ${DOCSDIR}
	${CHMOD} -R +r ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/painless-guide-to-crc.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

.if exists(${WRKSRC}/${MAKEFILE})
SHLIB_NAME!=	${MAKE} -f ${WRKSRC}/${MAKEFILE} -V Trf_LIB_FILE
SHLIB_LINK=	${SHLIB_NAME:C/\.so\..*/.so/}
.endif

PLIST_SUB+=	SHLIB_NAME=${SHLIB_NAME} SHLIB_LINK=${SHLIB_LINK}
