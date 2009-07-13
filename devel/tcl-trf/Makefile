# New ports collection makefile for:	tcl-Trf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Trf
PORTVERSION=	2.1.4
CATEGORIES=	devel tcl
MASTER_SITES=	ftp://ftp.tcl.tk/pub/incoming/
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}
MASTER_SITE_SUBDIR=tcltrf

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Data conversion, digests, compression, error-correction for Tcl

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//} \
		${LOCALBASE}/lib/tcl${TCL_VER}/Memchan/pkgIndex.tcl:${PORTSDIR}/devel/tcl-memchan

USE_BZIP2=	yes

ALL_TARGET=	all

USE_TCL=	84+
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf
CFLAGS+=	-Wall -Werror

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TCL_VER} \
		--enable-static-zlib --enable-static-bzlib \
		--enable-static-md5

post-patch:
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
	# Using OpenSSL's implementations of message digests (-lcrypto)
	# To use FreeBSD's own -lmd, stop now and restart make with:
	#
	#	-DTRF_USE_MD
	#
USE_OPENSSL=	yes
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/Trf
	${INSTALL_DATA} ${WRKSRC}/libTrf${PORTVERSION}.so	\
		${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/Trf/
	for m in ${WRKSRC}/doc/man/*.n	;	\
	do	\
		${INSTALL_MAN} $$m ${MANNPREFIX}/man/mann/ ;\
	done

post-build test:
	cd ${WRKSRC}/tests && ${SETENV} TCLLIBPATH="${WRKSRC}" ${TCLSH} all

MANN=	adler.n ascii85.n base64.n bin.n bz2.n crc-zlib.n crc.n	\
	crypt.n haval.n hex.n md2.n md5.n md5_otp.n md5crypt.n	\
	oct.n otp_words.n quoted-printable.n ripemd128.n ripemd160.n \
	rs_ecc.n sha.n sha1.n sha1_otp.n transform.n trf.n unstack.n \
	uuencode.n zip.n

.include <bsd.port.pre.mk>

PLIST_SUB+=	TCL_DVER=${TCL_VER:C/\.//} VER=${PORTVERSION}

.if defined(OPENSSLBASE) && ${OPENSSLBASE} != "/usr"
MAKE_ENV+=	SSLINC=-I${OPENSSLINC} SSLLIB=-L${OPENSSLLIB}
.endif

.include <bsd.port.post.mk>
