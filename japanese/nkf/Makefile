# New ports collection makefile for:	nkf
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	2.05
CATEGORIES?=	japanese
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/
PKGNAMEPREFIX?=	ja-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//:S/./-/}

MAINTAINER=	max@FreeBSD.org
COMMENT?=	Network Kanji code conversion Filter

.if ${PKGNAMEPREFIX} != "ja-p5-"
MAN1=		nkf.1
MANLANG=	"" ja
PLIST_FILES=	bin/nkf
ALL_TARGET=	nkf
.endif

.include <bsd.port.mk>
