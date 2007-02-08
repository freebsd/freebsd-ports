# New ports collection makefile for:	powerpc-binutils
# Date created:		9 Marth 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.17
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases

MAINTAINER=	stas@FreeBSD.org
COMMENT=	GNU binutils for PowerPC/RS6000 cross-development

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
NO_MTREE=	yes

.if defined(WITH_ABI)
OUR_ABI=		${WITH_ABI}
.else
OUR_ABI=		eabi
.endif

OUR_TARGET=		powerpc-elf-${OUR_ABI}

PKGNAMEPREFIX=		${OUR_TARGET}-
PLIST_SUB+=		TOOLPREFIX=${OUR_TARGET}
PREFIX?=		${LOCALBASE}/${OUR_TARGET}
CONFIGURE_ARGS=		--disable-nls \
			--target=${OUR_TARGET} \
			--with-system-zlib \
			--with-libiconv-prefix=${LOCALDIR} \
			--libdir=${PREFIX}/lib/gcc/${OUR_TARGET}

MAN1=			${PKGNAMEPREFIX}addr2line.1 \
			${PKGNAMEPREFIX}ar.1 \
			${PKGNAMEPREFIX}as.1 \
			${PKGNAMEPREFIX}c++filt.1 \
			${PKGNAMEPREFIX}dlltool.1 \
			${PKGNAMEPREFIX}ld.1 \
			${PKGNAMEPREFIX}nlmconv.1 \
			${PKGNAMEPREFIX}nm.1 \
			${PKGNAMEPREFIX}objcopy.1 \
			${PKGNAMEPREFIX}objdump.1 \
			${PKGNAMEPREFIX}ranlib.1 \
			${PKGNAMEPREFIX}readelf.1 \
			${PKGNAMEPREFIX}size.1 \
			${PKGNAMEPREFIX}strings.1 \
			${PKGNAMEPREFIX}strip.1 \
			${PKGNAMEPREFIX}windres.1

INFO=			as binutils ld

post-extract:
	@${REINPLACE_CMD} -E -e 's,^(install:).*,\1,' \
		${WRKSRC}/bfd/Makefile.in \
		${WRKSRC}/etc/Makefile.in \
		${WRKSRC}/libiberty/Makefile.in \
		${WRKSRC}/opcodes/Makefile.in

.include <bsd.port.mk>
