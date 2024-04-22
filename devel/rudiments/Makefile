PORTNAME=	rudiments
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more
WWW=		https://rudiments.sourceforge.net

LICENSE=	LGPL20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgssapi_krb5.so:security/krb5

USES=		libedit libtool pathfix pkgconfig readline shebangfix
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librudiments.so.8.1.1

.include <bsd.port.mk>
