# New ports collection makefile for:	msp430-gcc
# Date created:		15 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}.${PATCHVERSION}
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		http://lev.serebryakov.spb.ru/download/msp430/:patches
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	msp430-
DISTFILES=	${PORTNAME}-core-${GCCVERSION}${EXTRACT_SUFX} \
		${PKGNAMEPREFIX}${PORTNAME}-${GCCVERSION}.${PATCHVERSION}${EXTRACT_SUFX}:patches

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF gcc-3.4 for TI's msp430 MCUs cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

GCCVERSION=	3.4.1
PATCHVERSION=	20040723

WRKSRC=		${WRKDIR}/${PORTNAME}-${GCCVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--enable-languages=c --disable-nls \
		--infodir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}gcov.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

INFO=		cpp cppinternals gcc gccinstall gccint
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

BINARIES=	gcc gcc-${GCCVERSION} gcov cpp

.include <bsd.port.pre.mk>

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=).+$$,\1,' ${WRKSRC}/Makefile
#	@${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' ${WRKSRC}/gcc/Makefile

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.post.mk>
