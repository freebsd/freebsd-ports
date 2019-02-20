# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	gsoap
PORTVERSION=	2.8.79
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2/gsoap-2.8
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

LICENSE=	GPLv2

USES=		autoreconf pathfix ssl zip

CONFIGURE_ENV=	LEX=flex YACC=yacc
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GNUTLS_CONFIGURE_ON=	--enable-gnutls
GNUTLS_LDFLAGS=		-L${LOCALBASE}/lib
OPENSSL_CONFIGURE_ENABLE=	ssl
CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's|sys/timeb.h | |' \
	    -e 's|-DSOAPCPP_IMPORT_PATH=|-DSOAPCPP2_IMPORT_PATH=|' \
	    -e 's|-DWSDL_IMPORT_PATH=|-DWSDL2H_IMPORT_PATH=|' \
	    ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|$$(libdir)|$$(libdir)data|' \
	    ${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gsoap
	${INSTALL_DATA} ${WRKSRC}/gsoap/stdsoap2.c ${WRKSRC}/gsoap/dom.cpp \
	    ${STAGEDIR}${PREFIX}/lib/gsoap
	@${LN} -fs stdsoap2.c ${STAGEDIR}${PREFIX}/lib/gsoap/stdsoap2.cpp
	@${LN} -fs dom.cpp ${STAGEDIR}${PREFIX}/lib/gsoap/dom.c

.include <bsd.port.mk>
