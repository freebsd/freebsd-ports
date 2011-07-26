# New ports collection makefile for:	msp430-libc
# Date created:		15 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	libc
PORTVERSION=	1.0.${LIBCVERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	${LIBCTARGET}-
MASTER_SITES=	SF/mspgcc/${PKGNAMEPREFIX}${PORTNAME}
DISTFILES=	${PKGNAMEPREFIX}${PORTNAME}-${LIBCVERSION}${EXTRACT_SUFX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Libc for TI's msp430 MCUs cross-development

LIBCVERSION=	20110612
LIBCTARGET=	msp430

BUILD_DEPENDS=	${PREFIX}/${LIBCTARGET}/include/${LIBCTARGET}.h:${PORTSDIR}/devel/${LIBCTARGET}mcu
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	GCC4 "Use new msp430-gcc4 compiler" on \
		GCC3 "Use old msp430-gcc3 compiler" off

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH} PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}libc-${LIBCVERSION}/src

.include <bsd.port.options.mk>

.if defined(WITH_GCC4)
.if defined(WITH_GCC3)
BROKEN=	Please, select msp430-gcc-4 or msp430-gcc-3, not both
.endif
PKGNAMESUFFIX=	-gcc4
BUILD_DEPENDS+=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc
CONFLICTS=	${PKGNAMEPREFIX}${PORTNAME}-gcc3-*
PLIST_SUB+=	GCC3="@comment " GCC4=""
NEEDGCCVERSION=	4
.elif defined(WITH_GCC3)
PKGNAMESUFFIX=	-gcc3
BUILD_DEPENDS+=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc3
CONFLICTS=	${PKGNAMEPREFIX}${PORTNAME}-gcc4-*
PLIST_SUB+=	GCC3="" GCC4="@comment "
NEEDGCCVERSION=	3
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
