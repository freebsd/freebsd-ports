# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	1.01.013
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

GNU_CONFIGURE=	yes

PLIST_FILES=	include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a

MANCOMPRESSED=	no
MAN3=		archive_entry.3 \
		archive_read.3 \
		archive_util.3 \
		archive_write.3 \
		libarchive.3
MAN5=		libarchive-formats.5 \
		tar.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502103
IGNORE=		is in the base system
.endif

.include <bsd.port.post.mk>
