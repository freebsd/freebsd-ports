# New ports collection makefile for: mingw2-binutils
# Date created:		24 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${PATCHVERSION}
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}  	# ${MASTER_SITE_SOURCEWARE}
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
#MASTER_SITE_SUBDIR=	mingw			# binutils/releases
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	mingw32-
#DISTNAME=	${PORTNAME}-${BINUTILVERSION}.${PATCHVERSION:S/./-/g}-src
DISTNAME=	${PORTNAME}-${BINUTILVERSION}
#DIST_SUBDIR=	mingw

# No patches for this release
PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
# Special hack: I don't use SITE_SUBDIR & DIST_SUBDIR, and only pathces
#               will be placed to subdirectory
#               It allows to use main binutils sources from other ports.
PATCHFILES=	mingw/${PORTNAME}-${BINUTILVERSION}.${PATCHVERSION:S/./-/g}-src.diff.gz

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF binutils-2.14 for Windows cross-development

BROKEN=		Incomplete pkg-plist

BINUTILVERSION=	2.15
PATCHVERSION=	90.20040222.1

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PATCH_DIST_STRIP=	-p1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-win32-registry \
		--disable-shared \
		--infodir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info

MAN1=	${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}ar.1    \
	${PKGNAMEPREFIX}as.1 ${PKGNAMEPREFIX}dlltool.1      \
	${PKGNAMEPREFIX}c++filt.1 ${PKGNAMEPREFIX}ld.1      \
	${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}nm.1      \
	${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}objdump.1 \
	${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}readelf.1  \
	${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1    \
	${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}windres.1

INFO=		as bfd binutils ld configure standards
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip dlltool dllwrap windres

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
# Register these too
	install-info ${PREFIX}/${INFO_PATH}/configure.info ${PREFIX}/${INFO_PATH}/dir
	install-info ${PREFIX}/${INFO_PATH}/standards.info ${PREFIX}/${INFO_PATH}/dir
# Add this after all quto-generated info etries
	${ECHO} "@unexec rm %D/${PKGNAMEPREFIX:S/-$//}/info/dir" >> ${TMPPLIST}
	${ECHO} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//}/info 2> /dev/null || true" >> ${TMPPLIST}
	${ECHO} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>

