# New ports collection makefile for:	tcl-Trf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Trf
PORTVERSION=	2.1p2
PORTREVISION=	2
CATEGORIES=	devel tcl83
MASTER_SITES=	http://www.oche.de/~akupries/soft/trf/download/
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//} \
		${LOCALBASE}/lib/tcl${TCL_VER}/Memchan/pkgIndex.tcl:${PORTSDIR}/devel/tcl-memchan

USE_BZIP2=	yes

ALL_TARGET=	all test
MAKE_ARGS+=	-j2

TCL_VER?=		8.3
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

USE_REINPLACE=	yes
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

SHLIB_NAME=	libTrf2.so.1
SHLIB_LINK=	${SHLIB_NAME:C/\.so\..*/.so/}

PLIST_SUB+=	SHLIB_NAME=${SHLIB_NAME} SHLIB_LINK=${SHLIB_LINK}
