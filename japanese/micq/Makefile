# New ports collection makefile for:	micq
# Version required:			13 Dec 1998
# Date created:				31 Oct 1998
# Whom:					flathill
#
# $FreeBSD$
#

DISTNAME=	micq-0.4.0
PKGNAME=	ja-micq-0.4.0
CATEGORIES=	japanese net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.4.0/ \
		http://www.freebsd.org/~flathill/distfiles/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.tahoo.org/~taku/soft/micq-0.4.0-jp.patch \
		http://www.freebsd.org/~flathill/distfiles/
PATCHFILES=	micq-0.4.0-jp.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.org

WRKSRC=		${WRKDIR}/micq-0.4.0

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
