# New ports collection makefile for:	chimera + kanji patch
# Version required:	1.65
# Date created:		26 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/11/26 11:32:35 asami Exp $
#

DISTNAME=	chimera-1.65
PKGNAME=	jp-chimera-1.65
CATEGORIES+=	japanese www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/

PATCH_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/www/chimera/
PATCHFILES=	chimera-1.65-kanji.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

.include <bsd.port.mk>
