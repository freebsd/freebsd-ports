# New ports collection makefile for:	nkf
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	2.06
DISTVERSION=	a
CATEGORIES?=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/19481
PKGNAMEPREFIX?=	ja-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//:S/./-/}${DISTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT?=	Network Kanji code conversion Filter

WRKSRC?=	${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//:S/./-/}

.if ${PKGNAMEPREFIX} != "ja-p5-"
MAN1=		nkf.1
MANLANG=	"" ja
PLIST_FILES=	bin/nkf
ALL_TARGET=	nkf
.endif

.include <bsd.port.mk>
