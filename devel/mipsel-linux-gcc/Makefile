# New ports collection makefile for:	mipsel-linux-gcc
# Date created:		20 October 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.97
PORTREVISION=	3
CATEGORIES=	devel
#MASTER_SITES=   ftp://ftp.agendacomputing.com/pub/dev/snow/snap-02212000/src/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex
PKGNAMEPREFIX=	mipsel-linux-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Gcc-2.97 for mipsel-linux cross-development with SNOW ABI

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include/stdio.h:${PORTSDIR}/devel/agenda-headers \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib/crti.o:${PORTSDIR}/devel/agenda-static-libs \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib/libc.a:${PORTSDIR}/devel/agenda-static-libs
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

WRKSRC=		${WRKDIR}/gcc

CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=c,c++ \
		--enable-soft-float \
		--enable-multilib \
		--disable-shared \
		--disable-nls

ONLY_FOR_ARCHS=	i386 alpha
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
USE_PERL5=	yes
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}g++.1 ${PKGNAMEPREFIX}gcc.1 \
		${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}gcov.1

GCC_REV=	2.97

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCC_REV}

BINARIES=	gcc g++ c++ cpp gcov

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=).+$$,\1,' ${WRKSRC}/Makefile
	@${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' ${WRKSRC}/gcc/Makefile

post-install:
.for F in ${BINARIES}
	@${STRIP_CMD} ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
