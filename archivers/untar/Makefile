# New ports collection makefile for:    untar
# Date created:         14 Jul 2002
# Whom:                 KIMURA Shigekazu <zau50357@lion.zero.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	untar
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists/Extracts files from a "*.tgz" or "*.gz" archive

NO_WRKSUBDIR=	yes
NO_INSTALL_MANPAGES=		yes
PLIST_FILES=	bin/untar

PROG=	untar

pre-patch:
	@${CP} ${DISTDIR}/untar.c ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile.untar ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROG} ${PREFIX}/bin

.include <bsd.port.mk>
