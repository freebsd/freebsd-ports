# New ports collection makefile for:    asl
# Version required:     1.41r7
# Date created:         18 June 1997
# Whom:                 Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=       asl-1.41r7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://john.ccac.rwth-aachen.de/pub/as/source/c_version/
MASTER_SITE_SUBDIR=	devel/lang/assemblers

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	mkdirhier:${PORTSDIR}/x11/XFree86

MAN1=	asl.1 p2bin.1 p2hex.1 pbind.1 plist.1

post-extract:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

post-install:
	${MKDIR} ${PREFIX}/share/doc/asl
	${INSTALL_DATA} ${WRKSRC}/doc_EN/* ${PREFIX}/share/doc/asl

.include <bsd.port.mk>
