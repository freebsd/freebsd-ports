# New ports collection makefile for:	skk-tools
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.2 1998/12/23 08:50:24 kuriyama Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-tools-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

BUILD_DEPENDS=	/nonexistent:${SKK_MASTERDIR}:configure

SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${WRKDIRPREFIX}${SKK_MASTERDIR}/work/skk-9.6
MAKE_ARGS=	SUBDIRS='jisyo-tools'

.include <bsd.port.mk>
