# New ports collection makefile for:	libgooglepinyin
# Date created:				11 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libgooglepinyin
PORTVERSION=	0.1.1
CATEGORIES=	chinese devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	A fork of Google Pinyin IME on Android

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	does not support big-endian dictionary

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes

.include <bsd.port.mk>
