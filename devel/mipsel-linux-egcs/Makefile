# New ports collection makefile for:	mipsel-linux-egcs
# Date created:		14 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	egcs
PORTVERSION=	1.0.3a
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=     gcc/old-releases/egcs
PKGNAMEPREFIX=	mipsel-linux-

MAINTAINER=	lev@serebryakov.spb.ru

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${LOCALBASE}/${PKGNAMEPREFIX:S/-$//}/include/stdio.h:${PORTSDIR}/devel/agenda-headers
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

USE_BZIP2=	yes
PATCH_STRIP=    -p1
CONFIGURE_ARGS=	--enable-threads --target=${PKGNAMEPREFIX:S/-$//}

MAKE_ENV=	PATH=${PREFIX}/bin:${PATH} LANGUAGES="c c++ objective-c"
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure etc/configure gcc/configure \
		texinfo/configure texinfo/testsuite/configure
MAN1=		${PKGNAMEPREFIX}g++.1 ${PKGNAMEPREFIX}gcc.1 cccp.1

EGCS_REV=	2.90.29

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${PORTNAME}-${EGCS_REV}

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=),\1#,' ${WRKSRC}/Makefile
	@${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' ${WRKSRC}/gcc/Makefile

post-install:
	@${LN} -fs ${PREFIX}/bin/${PKGNAMEPREFIX}gcc \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/gcc
	@${LN} -fs ${PREFIX}/bin/${PKGNAMEPREFIX}g++ \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/g++
	@${LN} -fs ${PREFIX}/bin/${PKGNAMEPREFIX}c++ \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/c++
	@${RM} ${PREFIX}/lib/libiberty.a

.include <bsd.port.mk>
