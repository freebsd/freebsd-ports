# New ports collection makefile for: mingw2-binutils
# Date created:		24 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${PATCHVERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-${BINUTILVERSION}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
## Special hack: I don't use SITE_SUBDIR & DIST_SUBDIR, and only pathces
##               will be placed to subdirectory
##               It allows to use main binutils sources from other ports.
PATCHFILES=	mingw/${PORTNAME}-${BINUTILVERSION}.${PATCHVERSION:S/./-/g}-src.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF binutils-2.14 for Windows cross-development

BINUTILVERSION=	2.14
PATCHVERSION=	90.20030807.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
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

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip dlltool dllwrap windres

post-install:
.for F in ${BINARIES}
	@${STRIP_CMD} ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
