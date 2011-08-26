# New ports collection makefile for:	libhangul
# Date created:				31 January 2007
# Whom:					Hyogeol, Lee <hyogeollee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libhangul
PORTVERSION=	0.0.12
CATEGORIES=	korean
MASTER_SITES=	http://kldp.net/frs/download.php/5855/

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	A library for hangul processing

LICENSE=	LGPL21

USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

test:	build
	@( cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${GMAKE} )
.if exists(${LOCALBASE}/libdata/pkgconfig/check.pc)
	@( cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${GMAKE} test && ./test )
.endif

.include <bsd.port.post.mk>
