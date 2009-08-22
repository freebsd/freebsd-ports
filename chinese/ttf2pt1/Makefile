# New ports collection makefile for:    zh-ttf2pt1
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ttf2pt1
PORTVERSION=	3.4.0
CATEGORIES=	chinese print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-chinese/${PORTVERSION}
DISTNAME=	${PORTNAME}-chinese-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	True Type Font to Postscript Type 1 Converter with chinese maps

RUN_DEPENDS=	ttf2pt1:${PORTSDIR}/print/ttf2pt1

MAKE_ARGS=	INSTDIR="${PREFIX}"

NO_BUILD=	yes

.include <bsd.port.mk>
