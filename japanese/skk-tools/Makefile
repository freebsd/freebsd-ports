# New ports collection makefile for:	skk-tools
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/12/15 15:22:46 kuriyama Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-tools-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

BUILD_DEPENDS=	/nonexistent:${SKK_MASTERDIR}:configure

SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${SKK_MASTERDIR}/work/skk-9.6
MAKE_ARGS=	SUBDIRS='jisyo-tools'

.include <bsd.port.mk>
