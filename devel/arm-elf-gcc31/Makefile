# New ports collection makefile for:	gcc-arm
# Date created:		3 November 2000
# Whom:			Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc
PKGNAMEPREFIX=	arm-elf-

MAINTAINER=	esk@ira.uka.de

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

USE_BZIP2=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --enable-languages="c,c++,objc"
.if defined(DEFAULT_CPU)
CONFIGURE_ARGS+=	--with-cpu="${DEFAULT_CPU}"
.endif

MAKE_ENV=		PATH=${PREFIX}/bin:${PATH}
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure etc/configure gcc/ch/configure gcc/configure \
		libchill/configure libf2c/configure libf2c/libF77/configure \
		libf2c/libI77/configure libf2c/libU77/configure \
		libiberty/configure libobjc/configure texinfo/configure \
		texinfo/testsuite/configure
MAN1=		${PKGNAMEPREFIX}g++.1 ${PKGNAMEPREFIX}gcc.1 cccp.1

.if !defined(DEFAULT_CPU)
pre-extract:
	@${ECHO}
	@${ECHO} "You can specify a default cpu target for gcc by setting DEFAULT_CPU to the"
	@${ECHO} "appropriate target (e.g., strongarm1100)."
	@${ECHO}
.endif

post-configure:
	${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=),\1#,' ${WRKSRC}/Makefile
	${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' \
	    ${WRKSRC}/gcc/Makefile

post-install:
	@${MV} ${PREFIX}/bin/cpp ${PREFIX}/bin/${PKGNAMEPREFIX}cpp
	@${MV} ${PREFIX}/bin/gcov ${PREFIX}/bin/${PKGNAMEPREFIX}gcov
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}g++ \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/g++
	@${RM} ${PREFIX}/lib/libiberty.a

.include <bsd.port.mk>
