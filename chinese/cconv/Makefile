# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	chinese converters

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified-Traditional Chinese conversion tool

LICENSE=	MIT
LICNESE_FILE=	${WRKSRC}/License

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf iconv libtool

GH_ACCOUNT=	xiaoyjy
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|unicode.h||; s|libcconv_la_LDFLAGS|cconv_LDFLAGS|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|UTF-TW|UTF8-TW|g' ${WRKSRC}/main.c

.include <bsd.port.pre.mk>

.if ! empty(ICONV_LIB)
CONFIGURE_ENV+=	ICONV_DIR=${ICONV_PREFIX}
.endif

.include <bsd.port.post.mk>
