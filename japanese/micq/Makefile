# New ports collection makefile for:	micq
# Version required:			13 Dec 1998
# Date created:				31 Oct 1998
# Whom:					flathill
#
# $Id: Makefile,v 1.1.1.1 1998/11/19 08:01:50 flathill Exp $
#

DISTNAME=	micq
PKGNAME=	ja-micq-0.3.3
CATEGORIES=	japanese net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.3.3/ \
		http://www.freebsd.org/~flathill/distfiles/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://flos.kuee.kyoto-u.ac.jp/soft/ \
		http://www.freebsd.org/~flathill/distfiles/
PATCHFILES=	micq981218ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.ORG

WRKSRC=		${WRKDIR}/micq981218

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
