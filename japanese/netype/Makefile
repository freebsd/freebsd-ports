# New ports collection makefile for:	netype
# Date created:		07 May 2001
# Whom:			Takeshi MUTOH <mutoh@info.nara-k.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	netype
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.i.his.fukui-u.ac.jp/~funakami/software/netype/src/
DISTNAME=	${PORTNAME}-0.1.0

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}.${PORTVERSION}.patch.gz
PATCH_DIST_STRIP=	-p1
#PATH_WRKSRC=	${WRKSRC}

MAINTAINER=	mutoh@openedu.org
COMMENT=	Network Type Trainer client program

USE_GNOME=	imlib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
