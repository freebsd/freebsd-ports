# New ports collection makefile for:	msp430-libc
# Date created:		15 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	libc
PORTVERSION=	1.0.${LIBCVERSION}
CATEGORIES=	devel
MASTER_SITES=	SF/mspgcc/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	${LIBCTARGET}-
PKGNAMESUFFIX=	-gcc${NEEDGCCVERSION}
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${LIBCVERSION}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Libc for TI's msp430 MCUs cross-development

BUILD_DEPENDS=	${LOCALBASE}/${LIBCTARGET}/include/${LIBCTARGET}.h:${PORTSDIR}/devel/${LIBCTARGET}mcu \
		${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc${PORTGCCVERSION}
RUN_DEPENDS=	${LOCALBASE}/${LIBCTARGET}/include/${LIBCTARGET}.h:${PORTSDIR}/devel/${LIBCTARGET}mcu \
		${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc${PORTGCCVERSION}

CONFLICTS=	${PKGNAMEPREFIX}${PORTNAME}-gcc${OTHERGCCVERSION}-[0-9]*

OPTIONS=	GCC4 "Use new msp430-gcc4 compiler" on \
		GCC3 "Use old msp430-gcc3 compiler" off

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH} PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}libc-${LIBCVERSION}/src

LIBCVERSION=	20110612
LIBCTARGET=	msp430

.include <bsd.port.options.mk>

.if defined(WITH_GCC4)
.if defined(WITH_GCC3)
BROKEN=	Please, select msp430-gcc-4 or msp430-gcc-3, not both
.endif
BUILD_DEPENDS+=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc
PLIST_SUB+=	GCC3="@comment " GCC4=""
NEEDGCCVERSION=	4
PORTGCCVERSION=
OTHEGCCVERSION=	3
.elif defined(WITH_GCC3)
PLIST_SUB+=	GCC3="" GCC4="@comment "
NEEDGCCVERSION=	3
PORTGCCVERSION=	${NEEDGCCVERSION}
OTHEGCCVERSION=	4
.else
BROKEN=	Please, select msp430-gcc-4 either msp430-gcc-3
.endif

pre-configure:
	@HAVEGCCVERSION=`${PKGNAMEPREFIX}gcc -v 2>&1 | ${GREP} "gcc version " | ${CUT} -d" " -f 3 | ${CUT} -d. -f 1` ; \
	 if [ "$${HAVEGCCVERSION}" = "" ] ; then \
	 	${ECHO_MSG} "ERROR: Can not find any version of msp430-gcc" ; \
	 	${FALSE} ; \
	 elif [ "$${HAVEGCCVERSION}" != "${NEEDGCCVERSION}" ] ; then \
	 	${ECHO_MSG} "ERROR: Need msp430-gcc-${NEEDGCCVERSION} but found msp430-gcc-$${HAVEGCCVERSION}" ; \
	 	${FALSE} ; \
	 fi

.include <bsd.port.mk>
