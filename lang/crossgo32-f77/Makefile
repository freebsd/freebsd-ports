# Ports collection makefile for:	crossgo32-f77
# Date created:				19 September 2000
# Whom:					Huidae Cho <hdcho@geni.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	crossgo32-f77
PORTVERSION=	2.95.2
CATEGORIES=	lang
MASTER_SITES=	# none
DISTNAME=	f77-freebsd.0.3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} g772952b.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	G2c libraries and compatibility for DJGPP V2 crossgo32 crosscompiler

DEPRECATED=	"project abandoned, mastersite long gone"
EXPIRATION_DATE=	"May 5, 2004"

EXTRACT_DEPENDS+=unzip:${PORTSDIR}/archivers/unzip
.if !defined(GNU_CPP)
RUN_DEPENDS+=	${LOCALBASE}/bin/fpp:${PORTSDIR}/devel/fpp
.endif
RUN_DEPENDS+=	${LOCALBASE}/bin/f2c:${PORTSDIR}/lang/f2c \
		${LOCALBASE}/i386-go32/bin/gcc:${PORTSDIR}/devel/crossgo32-djgpp2

# Set F77NAME to the name of the Fortran 77 wrapper.
F77NAME=	ftn77
GCCVERSION=	2.952
ONLY_FOR_ARCHS=	i386

MAKE_ARGS+=	CFLAGS+=" -DPP_COMMAND='\"/usr/bin/cpp\"' \
		-DF2C_COMMAND='\"${LOCALBASE}/bin/f2c\"'"
.if !defined(GNU_CPP)
MAKE_ARGS+=	CFLAGS+=" -DSUN_FPP"
.endif
MAKE_ARGS+=	-DF2C_INCLUDEDIR='\"-I${LOCALBASE}/i386-go32/include\"' \
		-DF2C_LIBDIR='\"-I${LOCALBASE}/i386-go32/lib\"' \
		-DCC_COMMAND='\"${LOCALBASE}/bin/i386-go32-gcc\"'

ALL_TARGET=	depend all

post-extract:
	if ! (cd ${WRKDIR} && \
		unzip -q ${_DISTDIR}g772952b.zip -d ${WRKDIR} \
		lib/gcc-lib/djgpp/${GCCVERSION}/libg2c.a \
		lib/gcc-lib/djgpp/${GCCVERSION}/include/g2c.h);\
	then \
		exit 1; \
	fi

do-install:
	${INSTALL_DATA} \
		${WRKDIR}/lib/gcc-lib/djgpp/${GCCVERSION}/libg2c.a \
		${PREFIX}/i386-go32/lib/libf2c.a
	${INSTALL_DATA} \
		${WRKDIR}/lib/gcc-lib/djgpp/${GCCVERSION}/include/g2c.h \
		${PREFIX}/i386-go32/include/f2c.h
	${INSTALL_PROGRAM} ${WRKSRC}/f77 ${PREFIX}/i386-go32/bin/f77
	${INSTALL_PROGRAM} ${WRKSRC}/f77 ${PREFIX}/bin/i386-go32-f77

.include <bsd.port.mk>
