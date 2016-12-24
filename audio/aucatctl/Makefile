# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# Based on the OpenBSD port audio/aucatctl
# $OpenBSD: Makefile,v 1.3 2014/07/13 11:40:23 armani Exp $

PORTNAME=	aucatctl
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	t@tobik.me
COMMENT=	Control sndiod and/or aucat volumes

LICENSE=	ISCL

LIB_DEPENDS=	libsndio.so:audio/sndio

MAKE_ARGS=	INCLUDE="-I${LOCALBASE}/include" \
		LIB="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/aucatctl \
		man/man1/aucatctl.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aucatctl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aucatctl.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
