# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	2.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.la \
		lib/libarchive.so \
		lib/libarchive.so.9

MANCOMPRESSED=	no
MAN1=		bsdcpio.1 \
		bsdtar.1
MAN3=		archive_entry.3 \
		archive_read.3 \
		archive_read_disk.3 \
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

regression-test:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check)

.include <bsd.port.post.mk>
