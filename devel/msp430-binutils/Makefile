# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${LTSVERSION}
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases \
		SF/mspgcc/mspgcc:mspgcc
PKGNAMEPREFIX=	msp430-
DISTNAME=	${PORTNAME}-${BINUTILVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mspgcc-${LTSVERSION}${EXTRACT_SUFX}:mspgcc

PATCH_SITES=		SF/mspgcc/Patches/LTS/${LTSVERSION}
PATCHFILES=		${LTS_PATCHES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for TI's msp430 MCUs cross-development

LICENSE=	GPLv3

DEPRECATED=		Obsolete. Please, use devel/gcc-msp430-ti-toolchain
EXPIRATION_DATE=	2016-01-08

BINUTILVERSION=	2.21.1a
LTSVERSION=	20120406
PATCHVERSION=	20120406
BUGS_FIXED=	# For future use
.for bugid in ${BUGS_FIXED}
LTS_PATCHES+=	${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION}-sf${BUGID}.patch
.endfor

USES=		tar:bzip2 gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-werror

INFO=		as bfd binutils configure gprof ld standards
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION:C/[^0-9.]//g}

BINARIES=	addr2line ar as c++filt elfedit gprof ld nm objcopy objdump \
		ranlib readelf size strings strip

pre-patch:
	@cd ${WRKSRC} && ${PATCH} -s -p1 < ../mspgcc-${LTSVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION}.patch

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
.for F in ${BINARIES}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

#add-plist-post:
#	@${ECHO_CMD} "@unexec rmdir %D/${INFO_PATH} 2> /dev/null || true" >> ${TMPPLIST}
#	@${ECHO_CMD} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
