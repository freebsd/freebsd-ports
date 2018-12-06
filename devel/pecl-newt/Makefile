# $FreeBSD$

PORTNAME=	newt
PORTVERSION=	1.2.9
PORTREVISION=	1
CATEGORIES=	devel www

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP language extension for RedHat Newt library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

LIB_DEPENDS=	libnewt.so:devel/newt

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

post-patch:
	@${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
