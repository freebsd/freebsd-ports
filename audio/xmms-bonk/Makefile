# New ports collection makefile for:	xmms-bonk
# Date created:		2002-06-15
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-bonk
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.proustmedia.de/bonk-xmms/
DISTNAME=	bonk-xmms-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin to play bonk files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
ALL_TARGET=

do-install:
	${INSTALL_DATA} ${WRKSRC}/libbonk.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
