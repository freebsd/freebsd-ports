# New ports collection makefile for:	chimera + kanji patch
# Version required:	1.65
# Date created:		26 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.8 1998/09/05 00:47:04 max Exp $
#

DISTNAME=	chimera-1.65
PKGNAME=	ja-chimera-1.65
CATEGORIES=	japanese www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/

PATCH_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/www/chimera/old/
PATCHFILES=	chimera-1.65-kanji.patch

MAINTAINER=	ports@FreeBSD.ORG

BROKEN_ELF=	yes

USE_IMAKE=		yes
PATCH_DIST_STRIP=	-p1
MAN1=			chimera.1

.include <bsd.port.mk>
