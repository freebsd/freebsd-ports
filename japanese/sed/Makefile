# New ports collection makefile for:	sed+mb
# Date created:		2 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	sed
PORTVERSION=	3.02
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	${PORTNAME}mb108.diff.gz
PATCH_DIST_STRIP=	-p1
FETCH_BEFORE_ARGS=	-b

MAN1=		sed.1

.include <bsd.port.mk>
