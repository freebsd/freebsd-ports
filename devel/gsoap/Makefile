# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	gsoap
PORTVERSION=	2.8.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}2/gSOAP
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

OPTIONS_DEFINE=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	OPENSSL

USE_ZIP=	yes
GNU_CONFIGURE=	yes
USES=	pathfix
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-DWSDL_TYPEMAP_FILE=\\\"${DATADIR}/WS/typemap.dat\\\" \
		-DSOAPCPP2_IMPORT_PATH=\\\"${DATADIR}/import\\\"

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ! ${PORT_OPTIONS:MOPENSSL} && ! ${PORT_OPTIONS:MGNUTLS}
CONFIGURE_ARGS+=--disable-ssl
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls \
   		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error
CONFIGURE_ARGS+=--enable-gnutls
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
	${REINPLACE_CMD} -e 's|sys/timeb.h||' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${PREFIX}/lib/gsoap
	@${CP} ${WRKSRC}/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap
	@${LN} -f ${PREFIX}/lib/gsoap/stdsoap2.c ${PREFIX}/lib/gsoap/stdsoap2.cpp

.include <bsd.port.post.mk>
