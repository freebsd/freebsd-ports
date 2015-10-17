# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rudiments
PORTVERSION=	0.54
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

GNU_CONFIGURE=	yes
USES=		libtool pkgconfig shebangfix
SHEBANG_FILES=	doc/programming/insert.pl
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS PCRE SSL
OPTIONS_DEFAULT=	SSL

PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre
SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_ENABLE=	ssl
SSL_CONFIGURE_ON=	--with-ssl-includes=-I${OPENSSLINC} \
			--with-ssl-libs=-L${OPENSSLLIB}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librudiments-${PORTVERSION}.so.1

.include <bsd.port.mk>
