# New ports collection makefile for:	msp430-binutils
# Date created:		15 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${MSPGCCVERSION}
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${BINUTILVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mspgcc-${MSPGCCVERSION}${EXTRACT_SUFX}:mspgcc
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		SF/mspgcc/mspgcc:mspgcc
MASTER_SITE_SUBDIR=	binutils/releases

PKGNAMEPREFIX=	msp430-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for TI's msp430 MCUs cross-development
LICENSE=	GPLv3

BINUTILVERSION=	2.21.1
MSPGCCVERSION=	20110716
PATCHVERSION=	20110716

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-werror
MAKE_ARGS+=	ARCH=""

MAN1=		${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}ar.1 \
		${PKGNAMEPREFIX}as.1 ${PKGNAMEPREFIX}c++filt.1 \
		${PKGNAMEPREFIX}dlltool.1 ${PKGNAMEPREFIX}elfedit.1 \
		${PKGNAMEPREFIX}gprof.1 ${PKGNAMEPREFIX}ld.1 \
		${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}objdump.1 \
		${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}readelf.1 \
		${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1 \
		${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}windmc.1 \
		${PKGNAMEPREFIX}windres.1


INFO=		as bfd binutils configure gprof ld standards
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt elfedit gprof ld nm objcopy objdump \
		ranlib readelf size strings strip

pre-patch:
	@cd ${WRKSRC} && ${PATCH} -s -p1 < ../mspgcc-${MSPGCCVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION}.patch
		
pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

#
# UGLY HACK
#
add-plist-post:
	@${ECHO_CMD} "@unexec rmdir -p %D/${PKGNAMEPREFIX:S/-$//}/info 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir -p %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}
.if (defined(PREFIX) && ${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec rmdir %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif

.include <bsd.port.mk>
