# New ports collection makefile for:	chimera + kanji patch
# Version required:	1.70p1
# Date created:		26 December 1994
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	chimera-1.70p0
PKGNAME=	ja-chimera-1.70p1
CATEGORIES=	japanese www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/

PATCH_SITES=	http://hasse.mathematik.tu-muenchen.de/%7Enikl/chimera-1.65p/ \
		ftp://netbsd.tohoku.ac.jp/network/www/chimera/
PATCHFILES=	chimera-1.70p0-1.70p1.gz diff-1.70p1-jp-01
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
USE_IMAKE=	yes
MAN1=		chimera.1

pre-configure:
	${CP} ${WRKSRC}/Common.tmpl.dist ${WRKSRC}/Common.tmpl
	${CP} ${WRKSRC}/options.h.dist ${WRKSRC}/options.h

.include <bsd.port.mk>
