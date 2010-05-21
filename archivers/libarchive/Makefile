# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	2.8.3
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

PLIST_FILES=	bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.la \
		lib/libarchive.so \
		lib/libarchive.so.10 \
		lib/pkgconfig/libarchive.pc
PLIST_DIRS=	lib/pkgconfig

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

CFLAGS+=	"-I${LOCALBASE}/include"
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

check:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check)

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.0:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
