# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	Trf
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tcltrf/tcltrf/${PORTVERSION}
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Data conversion, digests, compression, error-correction for Tcl

ALL_TARGET=	all

USES+=		tcl:tea tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/Trf
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf
CFLAGS+=	-Wall -Werror

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

TEST_TARGET=	do-test

REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS+=--enable-static-zlib --enable-static-bzlib \
		--enable-static-md5

.include <bsd.port.options.mk>
post-patch:
.if defined(TRF_USE_MD)
	#
	# Using FreeBSD's own -lmd instead of OpenSSL's -lcrypto
	#
	${REINPLACE_CMD} -E -e 's,openssl/,,'		\
		-e 's,(MD[5])_([A-Z][a-z]),\1\2,g'	\
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
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/Trf
	${INSTALL_DATA} ${WRKSRC}/libTrf${PORTVERSION}.so \
		${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/Trf/
	for m in ${WRKSRC}/doc/man/*.n	;	\
	do	\
		${INSTALL_MAN} $$m ${STAGEDIR}${MANNPREFIX}/man/mann/ ;\
	done

do-test:
	@if ! ${PKG_BIN} info --quiet tcl-memchan; then	\
		${PRINTF} "*****************\n%s\n*****************\n"	\
		    "devel/tcl-memchan must be installed for the tests to work";	\
		exit 1;	\
	fi
	cd ${WRKSRC}/tests && ${SETENV} TCLLIBPATH="${WRKSRC}" ${TCLSH} all

.include <bsd.port.pre.mk>

PLIST_SUB+=	TCL_DVER=${TCL_VER:C/\.//} VER=${PORTVERSION}

.if defined(OPENSSLBASE) && ${OPENSSLBASE} != "/usr"
MAKE_ENV+=	SSLINC=-I${OPENSSLINC} SSLLIB=-L${OPENSSLLIB}
.endif

.include <bsd.port.post.mk>
