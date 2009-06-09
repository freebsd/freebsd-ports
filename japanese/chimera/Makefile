# New ports collection makefile for:	chimera + kanji patch
# Date created:		26 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	chimera
PORTVERSION=	1.70p1
PORTREVISION=	2
CATEGORIES=	japanese www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/
DISTNAME=	${PORTNAME}-${PREV_VERSION}

PATCH_SITES=	http://hasse.mathematik.tu-muenchen.de/%7Enikl/chimera-1.65p/ \
		ftp://netbsd.tohoku.ac.jp/network/www/chimera/
PATCHFILES=	${PORTNAME}-${PREV_VERSION}-${PORTVERSION}.gz \
		diff-${PORTVERSION}-jp-01
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X/Athena World-Wide Web client + Japanese patch

PREV_VERSION=	${PORTVERSION:S/p1/p0/}

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		chimera.1

pre-configure:
	${CP} ${WRKSRC}/Common.tmpl.dist ${WRKSRC}/Common.tmpl
	${CP} ${WRKSRC}/options.h.dist ${WRKSRC}/options.h

.include <bsd.port.mk>
