# New ports collection makefile for:	sed+mb
# Version required:	3.02+mb1.08
# Date created:		2 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

DISTNAME=	sed-3.02
PKGNAME=	ja-sed-3.02
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sed

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	sedmb108.diff.gz
PATCH_DIST_STRIP=	-p1
FETCH_BEFORE_ARGS=	-b

MAN1=		sed.1

.include <bsd.port.mk>
