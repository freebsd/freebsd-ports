# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	gsoap
PORTVERSION=	2.8.17
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2/gSOAP
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

LICENSE=	GPLv2

CONFIGURE_ENV=	LEX=flex YACC=yacc
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USES=		pathfix zip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
   		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error
CONFIGURE_ARGS=	--enable-gnutls
LDFLAGS+=	-L${LOCALBASE}/lib
.elif ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS=	--enable-ssl
.else
CONFIGURE_ARGS=	--disable-ssl
.endif

post-patch:
	${REINPLACE_CMD} -e 's| sys/timeb.h | |' \
	    -e 's|-DSOAPCPP_IMPORT_PATH=|-DSOAPCPP2_IMPORT_PATH=|' \
	    -e 's|-DWSDL_IMPORT_PATH=|-DWSDL2H_IMPORT_PATH=|' \
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gsoap
	@${INSTALL_DATA} ${WRKSRC}/gsoap/stdsoap2.c \
	    ${STAGEDIR}${PREFIX}/lib/gsoap
	@${LN} -fs stdsoap2.c ${STAGEDIR}${PREFIX}/lib/gsoap/stdsoap2.cpp

.include <bsd.port.mk>
