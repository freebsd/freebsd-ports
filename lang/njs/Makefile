PORTNAME=	njs
DISTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	lang www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript command line utility
WWW=		https://nginx.org/en/docs/njs/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libquickjs.so:lang/quickjs

USES=		cpe ssl

CPE_VENDOR=	f5

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:${DISTVERSION}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc-opt="-I${LOCALBASE}/include/quickjs" \
		--ld-opt="-L${LOCALBASE}/lib" \
		--with-quickjs

PLIST_FILES=	bin/njs

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
