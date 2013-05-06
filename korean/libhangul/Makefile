# Created by: Hyogeol, Lee <hyogeollee@gmail.com>
# $FreeBSD$

PORTNAME=	libhangul
PORTVERSION=	0.1.0
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Library for Hangul processing

LICENSE=	LGPL21

USES=		iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
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
