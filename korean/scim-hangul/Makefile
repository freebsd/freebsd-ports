# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	scim-hangul
PORTVERSION=	0.4.0
CATEGORIES=	korean
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	SCIM IMEngine module for Korean(Hangul) input

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:${PORTSDIR}/korean/libhangul \
		libscim-1.0.so:${PORTSDIR}/textproc/scim

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
