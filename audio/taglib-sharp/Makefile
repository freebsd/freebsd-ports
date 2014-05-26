# $FreeBSD$

PORTNAME=	taglib-sharp
PORTVERSION=	2.0.3.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Tagging library for the Mono framework

GNU_CONFIGURE=	yes
USES=		gmake mono pathfix pkgconfig

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		VERSIONSUFX="db62eba44689b5b0"

CONFIGURE_ARGS=	--disable-docs

.include <bsd.port.mk>
