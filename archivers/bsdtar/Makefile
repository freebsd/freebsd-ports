# New ports collection makefile for:	libarchive
# Date created:		11 Jun 2004
# Whom:			Martin Matuska <martin@matuska.org>
#
# $FreeBSD$

PORTNAME=	bsdtar
PORTVERSION=	1.02.016
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	New tar archiver from FreeBSD 5.3

BUILD_DEPENDS=	${LOCALBASE}/lib/libarchive.a:${PORTSDIR}/archivers/libarchive

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/bsdtar

MANCOMPRESSED=	no
MAN1=		bsdtar.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502111
IGNORE=		is in the base system
.endif

.include <bsd.port.post.mk>
