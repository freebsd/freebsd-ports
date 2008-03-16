# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	2.4.14
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

OPTIONS=	BSDCPIO		"Enable bsdcpio"	on

PLIST_FILES=	bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.la \
		lib/libarchive.so \
		lib/libarchive.so.6

MANCOMPRESSED=	no
MAN1=		bsdtar.1
MAN3=		archive_entry.3 \
		archive_read.3 \
		archive_util.3 \
		archive_write.3 \
		archive_write_disk.3 \
		libarchive.3 \
		libarchive_internals.3
MAN5=		cpio.5 \
		libarchive-formats.5 \
		mtree.5 \
		tar.5

.include <bsd.port.pre.mk>

.if defined(WITH_BSDCPIO)
CONFIGURE_ARGS+=	--enable-bsdcpio=yes
PLIST_FILES+=		bin/bsdcpio
MAN1+=			bsdcpio.1
.endif

.include <bsd.port.post.mk>
