PORTNAME=	njs
DISTVERSION=	0.8.8
CATEGORIES=	lang www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript command line utility
WWW=		https://nginx.org/en/docs/njs/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ssl

CPE_VENDOR=	f5

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:${DISTVERSION}
HAS_CONFIGURE=	yes

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libquickjs.so:lang/quickjs

PLIST_FILES=	bin/njs

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/auto/quickjs

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
