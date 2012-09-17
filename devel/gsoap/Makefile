# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.8.10
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2/gSOAP 
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

OPTIONS=	OPENSSL  "Enable SSL/TLS (OpenSSL from base)" on \
		GNUTLS "Enable SSL/TLS (GnuTLS)" off

USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-DWSDL_TYPEMAP_FILE=\\\"${DATADIR}/WS/typemap.dat\\\" \
		-DSOAPCPP2_IMPORT_PATH=\\\"${DATADIR}/import\\\"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if defined(WITHOUT_OPENSSL) && defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=--disable-ssl
.endif

.if defined(WITH_GNUTLS) 
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls \
   		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error
CONFIGURE_ARGS+=--enable-gnutls
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
	${REINPLACE_CMD} -e 's|sys/timeb.h||' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${PREFIX}/lib/gsoap
	@${CP} ${WRKSRC}/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap
	@${LN} ${PREFIX}/lib/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap/stdsoap2.cpp

.include <bsd.port.post.mk>
