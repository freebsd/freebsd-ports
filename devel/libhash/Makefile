# New ports collection makefile for:    libhash
# Date created:                         14 Jan 2002
# Whom:                                 Andrew <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	libhash
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ugh.net.au/pub/unix/libhash/ \
				ftp://ftp.megamirror.com/pub/ugh/unix/libhash/ \
				http://ftp.megamirror.com/pub/ugh/unix/libhash/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	A library for manipulating hash tables

WRKSRC=		${WRKDIR}/libhash

MAN3=		libhash.3 libhash_convenience.3
MANCOMPRESSED=	maybe
MLINKS=		libhash.3 hash_initialise.3 \
		libhash.3 hash_insert.3 \
		libhash.3 hash_retrieve.3 \
		libhash.3 hash_delete.3 \
		libhash.3 hash_iterator_initialise.3 \
		libhash.3 hash_fetch_next.3 \
		libhash.3 hash_iterator_deinitialise.3 \
		libhash.3 hash_deinitialise.3 \
		libhash_convenience.3 hash_compare_int.3 \
		libhash_convenience.3 hash_compare_string.3 \
		libhash_convenience.3 hash_hash_int.3 \
		libhash_convenience.3 hash_hash_string.3 \
		libhash_convenience.3 hash_copy_int.3 \
		libhash_convenience.3 hash_copy_string.3

INSTALLS_SHLIB=	yes

.if defined(NOPROFILE)
PLIST_SUB+=	BUILT_PROFILE="@comment "
.else
PLIST_SUB+=	BUILT_PROFILE=""
.endif

.include <bsd.port.mk>
