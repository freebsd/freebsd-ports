# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rudiments
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

LIB_DEPENDS=	libgssapi_krb5.so:security/krb5 \
		libcurl.so:ftp/curl

USES=		libtool libedit pathfix pkgconfig readline shebangfix
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile
SHEBANG_FILES=	doc/programming/insert.pl
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS PCRE SSL
OPTIONS_DEFAULT=	SSL

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre
SSL_USES=		ssl
SSL_CONFIGURE_ENABLE=	ssl
SSL_CONFIGURE_ON=	--with-ssl-includes=-I${OPENSSLINC} \
			--with-ssl-libs=-L${OPENSSLLIB}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librudiments.so.6.0.1

.include <bsd.port.mk>
