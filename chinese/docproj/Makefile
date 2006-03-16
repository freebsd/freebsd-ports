# New ports collection makefile for:	zh-docproj
# Date created:		26 Feb 2006
# Whom:			Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	docproj
PORTVERSION=	0.1.20060303
CATEGORIES=	chinese
MASTER_SITES=	# none
PKGNAMEPREFIX=	zh-
DISTFILES=	# none

# Note: Updates from intron@intron.ac should also be
# considered as maintainer updates.

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Supportive tools for Chinese docproj build

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	gbklatex:${PORTSDIR}/chinese/CJK \
		html2text:${PORTSDIR}/textproc/html2text

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

.include <bsd.port.mk>
