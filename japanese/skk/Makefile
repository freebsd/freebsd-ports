# New ports collection makefile for:	skk
# Version required:	9.6
# Date created:		13 Feb 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.3 1996/11/11 10:12:51 max Exp $
#

DISTNAME=	skk9.6
PKGNAME=	jp-skk-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule

WRKSRC=		${WRKDIR}/skk-9.6
GNU_CONFIGURE=	yes

MAKE_FLAGS+=	EMACS=mule

.include <bsd.port.mk>
