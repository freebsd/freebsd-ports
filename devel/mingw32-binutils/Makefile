# New ports collection makefile for: mingw2-binutils
# Date created:		24 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${PATCHVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-${BINUTILVERSION}
DIST_SUBDIR=	mingw

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	mingw
PATCHFILES=	${PORTNAME}-${BINUTILVERSION}-${PATCHVERSION:S/./-/}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF binutils-2.13 for Windows cross-development

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

BINUTILVERSION=	2.13
PATCHVERSION=	20020903.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-win32-registry \
		--disable-shared

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

# There may be original binutils sources already
pre-fetch:
	for F in ${DISTFILES}; do \
		${TEST} -f ${DISTDIR}/$${F} && \
		${TEST} ! -f ${DISTDIR}/${DIST_SUBDIR}/$${F} && \
		${LN} ${DISTDIR}/$${F} ${DISTDIR}/${DIST_SUBDIR}/$${F} || \
		true ; \
	done

pre-install:
	@${CP} ${FILESDIR}/fdl.texi ${WRKSRC}/etc

post-install:
.for F in ${BINARIES}
	@strip ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
