# New ports collection makefile for:	arm-elf-gcc295
# Date created:		3 November 2000
# Whom:			Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}
PKGNAMEPREFIX=	arm-elf-
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-objc-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g77-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	esk@ira.uka.de

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

GCC_REV=	${DISTNAME:S/gcc-//g}
PLIST_SUB+=	GCC_REV=${GCC_REV}
USE_BZIP2=	yes
USE_REINPLACE=	yes
CFLAGS:=	${CFLAGS:C/-m(arch|cpu)=[a-zA-Z0-9]+//}
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --enable-languages="c,c++,objc"
.if defined(DEFAULT_CPU)
CONFIGURE_ARGS+=	--with-cpu="${DEFAULT_CPU}"
.endif
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure etc/configure gcc/configure libiberty/configure \
		libobjc/configure texinfo/configure \
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
	${REINPLACE_CMD} -e 's,^(TARGET_CONFIGDIRS\s*=),\1#,' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,^(install-info:),\1\ndonot-\1,; \
	    s,\$$\(bindir\)/(\$$\(DEMANGLER_CROSS_NAME\)),./\1,' \
	    ${WRKSRC}/gcc/Makefile

post-install:
	@${MV} ${PREFIX}/bin/cpp ${PREFIX}/bin/${PKGNAMEPREFIX}cpp
	@${MV} ${PREFIX}/bin/gcov ${PREFIX}/bin/${PKGNAMEPREFIX}gcov
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}g++ \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/g++
	@${RM} ${PREFIX}/lib/libiberty.a

.include <bsd.port.mk>
