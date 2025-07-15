PORTNAME=	gsoap
DISTVERSION=	2.8.139
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++
WWW=		https://www.cs.fsu.edu/~engelen/soap.html

LICENSE=	GPLv2

USES=		autoreconf cpe pathfix ssl zip
CPE_VENDOR=	genivia

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LEX=flex \
		YACC=yacc

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-fPIC -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PORTSCOUT=	limit:^2\.8\.[0-9][0-9][0-9]$

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

OPTIONS_DEFINE=			DEBUG IPV6
OPTIONS_DEFAULT=		IPV6 OPENSSL
OPTIONS_RADIO=			SSL
OPTIONS_RADIO_SSL=		GNUTLS OPENSSL

DEBUG_CONFIGURE_ON=	--enable-debug
GNUTLS_LIB_DEPENDS=		libgcrypt.so:security/libgcrypt \
				libgnutls.so:security/gnutls \
				libgpg-error.so:security/libgpg-error
GNUTLS_USES=	localbase:ldflags
GNUTLS_CONFIGURE_ON=		--enable-gnutls
IPV6_CONFIGURE_ENABLE=		ipv6
OPENSSL_CONFIGURE_ENABLE=	ssl

post-patch:
	@${REINPLACE_CMD} -e 's|sys/timeb.h | |' \
	    -e 's|-DSOAPCPP_IMPORT_PATH=|-DSOAPCPP2_IMPORT_PATH=|' \
	    -e 's|-DWSDL_IMPORT_PATH=|-DWSDL2H_IMPORT_PATH=|' \
	    ${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gsoap
	${INSTALL_DATA} ${WRKSRC}/gsoap/stdsoap2.c ${WRKSRC}/gsoap/dom.cpp \
	    ${STAGEDIR}${PREFIX}/lib/gsoap
	@${LN} -fs stdsoap2.c ${STAGEDIR}${PREFIX}/lib/gsoap/stdsoap2.cpp
	@${LN} -fs dom.cpp ${STAGEDIR}${PREFIX}/lib/gsoap/dom.c

.include <bsd.port.mk>
