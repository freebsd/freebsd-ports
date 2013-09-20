# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${LTSVERSION}
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		SF/mspgcc/mspgcc:mspgcc
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	msp430-
DISTNAME=	${PORTNAME}-${BINUTILVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mspgcc-${LTSVERSION}${EXTRACT_SUFX}:mspgcc

PATCH_SITES=		${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	mspgcc/Patches/LTS/${LTSVERSION}
PATCHFILES=		${LTS_PATCHES}
PATCH_DIST_STRIP=	-p1

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION:C/[^0-9.]//g}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for TI's msp430 MCUs cross-development

LICENSE=	GPLv3

BINUTILVERSION=	2.21.1a
LTSVERSION=	20120406
PATCHVERSION=	20120406
BUGS_FIXED=	# For future use
.for bugid in ${BUGS_FIXED}
LTS_PATCHES+=	${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION}-sf${BUGID}.patch
.endfor

USE_BZIP2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-werror

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

NO_STAGE=	yes
pre-patch:
	@cd ${WRKSRC} && ${PATCH} -s -p1 < ../mspgcc-${LTSVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION}.patch

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

add-plist-post:
	@${ECHO_CMD} "@unexec rmdir %D/${INFO_PATH} 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
