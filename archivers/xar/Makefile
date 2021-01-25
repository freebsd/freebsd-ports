# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	xar
PORTVERSION=	1.6.1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/downloads/mackyle/xar/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenDarwin XML eXtensible ARchiver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome libtool ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_crypto_OpenSSL_add_all_ciphers=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
