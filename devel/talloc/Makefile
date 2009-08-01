# New ports collection makefile for:	talloc
# Date created:				18 Apr 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		talloc
PORTVERSION?=		1.3.1
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
PKGNAMESUFFIX=

COMMENT=		Hierarchical pool based memory allocator

CONFLICTS=		samba-3.3*

SAMBA_PORT?=		samba4-devel
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../../net/${SAMBA_PORT}
FILESDIR=		${.CURDIR}/files
PKGDIR=			${.CURDIR}

WRKSRC=			${WRKDIR}/${DISTNAME}/lib/talloc

USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		autoconf:262 autoheader:262

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"

MAN3=			talloc.3

PLIST_FILES=		include/talloc.h \
			lib/libtalloc.a \
			lib/libtalloc.so \
			lib/libtalloc.so.1 \
			libdata/pkgconfig/talloc.pc

pre-install:
.if !exists(${WRKSRC}/talloc.3)
		@${CP} ${FILESDIR}/talloc.3 ${WRKSRC}
.endif

post-install:
		${LN} -sf libtalloc.so.1 ${PREFIX}/lib/libtalloc.so

.include "${MASTERDIR}/Makefile"
