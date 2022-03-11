# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	njs
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	lang www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript command line utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe

CPE_VENDOR=	f5
CPE_PRODUCT=	njs

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:0.7.2
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		SSL
OPTIONS_RADIO+=		PCRE
OPTIONS_RADIO_PCRE=	NOPCRE PCRE_ONE PCRE_TWO
NOPCRE_CONFIGURE_ON=	--no-pcre
PCRE_ONE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_ONE_CONFIGURE_ON=	--no-pcre2
PCRE_TWO_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
OPTIONS_DEFAULT=	PCRE_ONE SSL
SSL_CONFIGURE_OFF=	--no-openssl
SSL_USES=		ssl

NOPCRE_DESC=		Disable PCRE support
PCRE_ONE_DESC=		Enable PCRE1 support
PCRE_TWO_DESC=		Enable PCRE2 support
SSL_DESC=		Enable OpenSSL support

PLIST_FILES=	bin/njs

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
