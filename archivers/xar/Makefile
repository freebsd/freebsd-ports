PORTNAME=	xar
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/downloads/mackyle/xar/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenDarwin XML eXtensible ARchiver
WWW=		https://mackyle.github.io/xar/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream last release was in 2012 and seems dead

USES=		cpe gmake gnome libtool ssl
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	undefined reference due to --no-allow-shlib-undefined: EVP_MD_type
CPE_VENDOR=	xar_project
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_crypto_OpenSSL_add_all_ciphers=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
