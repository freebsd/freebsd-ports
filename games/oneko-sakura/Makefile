# New ports collection makefile for:	oneko-sakura
# Version required:	1.2
# Date created:		25 May 1999
# Whom:			HOTARU-YA <hotaru@tail.net>
#
# $FreeBSD$
#

DISTNAME=	oneko-1.2
PKGNAME=	oneko-sakura3-1.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cin.nihon-u.ac.jp/pub/Linux/PJE/PJE-0.1.2/sources/xclt/ \
		http://hp.vector.co.jp/authors/VA004959/oneko/

PATCH_SITES=	ftp://aptiva.mp.es.osaka-u.ac.jp/pub/oneko-sakura/
PATCHFILES=	oneko-1.2.sakura.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hotaru@tail.net

USE_IMAKE=	yes
MAN6=		oneko.6
NO_CDROM=	"Including a derivative from CARDCAPTOR SAKURA. See http://www.clamp.f-2.co.jp/"

pre-configure:
	@${ECHO} "MANSUFFIX=6" >>${WRKSRC}/Imakefile

.include <bsd.port.mk>
