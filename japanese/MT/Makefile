# New ports collection makefile for:	ja-MT
# Date created:			Fri, 2 Oct 2009 07:56:20 GMT
# Whom:				Takefu Kenji <takefu@airport.fm>
#
# $FreeBSD$

PORTNAME=	MT
CATEGORIES=	japanese www
PKGNAMEPREFIX=	ja-
DISTNAME=	MTOS-${PORTVERSION}-ja

COMMENT=	Japanese localization of the MovableType publishing system

MASTERDIR=	${.CURDIR}/../../www/${PORTNAME}

MT_LANG=	ja
CONFLICTS=	MT-[2-5].* fr-MT-[2-5].* de-MT-[2-5].* es-MT-[2-5].* \
		nl-MT-[2-5].* ru-MT-[2-5].*

MT_DOCS_URL=	http://movabletype.jp/documentation/
MT_UPGRADE_URL=	http://movabletype.jp/documentation/upgrade/

.include "${MASTERDIR}/Makefile"
