# Created by: Hyogeol, Lee <hyogeollee@gmail.com>
# $FreeBSD$

PORTNAME=	libhangul
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Library for Hangul processing

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS
USE_LDCONFIG=	yes
USES=		iconv libtool pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS=	--enable-nls
.else
CONFIGURE_ARGS=	--disable-nls
.endif

.if exists(${LOCALBASE}/libdata/pkgconfig/check.pc)
test:	build
	@( cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
	@( cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test && ./test )
.endif

.include <bsd.port.mk>
