# New ports collection makefile for:	skk-tools
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-tools
PORTVERSION=	9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/${PORTVERSION}/
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	matusita@jp.FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${SKK_MASTERDIR}:configure

SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${WRKDIRPREFIX}${SKK_MASTERDIR}/work/skk-${PORTVERSION}
MAKE_ARGS=	SUBDIRS='jisyo-tools'

.include <bsd.port.mk>
