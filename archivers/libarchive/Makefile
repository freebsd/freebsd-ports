# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	2.2.3
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

PLIST_FILES=	bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.la \
		lib/libarchive.so \
		lib/libarchive.so.4

MANCOMPRESSED=	no
MAN1=		bsdtar.1
MAN3=		archive_entry.3 \
		archive_read.3 \
		archive_util.3 \
		archive_write.3 \
		archive_write_disk.3 \
		libarchive.3 \
		libarchive_internals.3
MAN5=		libarchive-formats.5 \
		tar.5

.include <bsd.port.mk>
