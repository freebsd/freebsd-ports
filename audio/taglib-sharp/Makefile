# $FreeBSD$

PORTNAME=	taglib-sharp
PORTVERSION=	2.0.3.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Tagging library for the Mono framework

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		VERSIONSUFX="db62eba44689b5b0"

CONFIGURE_ARGS=	--disable-docs

.include <bsd.port.mk>
