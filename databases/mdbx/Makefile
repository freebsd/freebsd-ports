PORTNAME=	mdbx
DISTVERSION=	0.13.9
CATEGORIES=	databases
MASTER_SITES=	https://libmdbx.dqdkfa.ru/release/
DISTNAME=	libmdbx-amalgamated-${DISTVERSION}

MAINTAINER=	mahlon@martini.nu
COMMENT=	Lightning Memory-Mapped Database (Extended)
WWW=		https://github.com/erthink/libmdbx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake tar:xz
USE_LDCONFIG=	yes

NO_WRKSUBDIR=	yes

PLIST_SUB=	VERSION=${DISTVERSION}

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libmdbx-static.a ${STAGEDIR}${PREFIX}/lib/libmdbx.a
	${MV}  ${STAGEDIR}${PREFIX}/lib/libmdbx.so ${STAGEDIR}${PREFIX}/lib/libmdbx.so.${DISTVERSION}
	${RLN} libmdbx.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so
	${RLN} libmdbx.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so.0

.include <bsd.port.mk>
