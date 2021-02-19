# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	opendd
PORTVERSION=	0.7.9
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.bsdmon.com/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DynDNS client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: saved_attributes
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: saved_attributes

PORTDOCS=	README
PLIST_FILES=	sbin/${PORTNAME} \
		"@sample(,,600) %%ETCDIR%%/${PORTNAME}.conf.sample" \
		"%%ETCDIR%%/${PORTNAME}.pem"

OPTIONS_DEFINE=	OPENSSL RCNG DOCS
OPTIONS_DEFAULT=	OPENSSL RCNG
RCNG_DESC=	Install RC_NG script

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	undefined symbol: BIO_set_conn_ip
BROKEN_FreeBSD_13=	undefined symbol: BIO_set_conn_ip
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	"USE_SOCKET_SSL=yes"
.endif

.if ${PORT_OPTIONS:MRCNG}
USE_RC_SUBR=	${PORTNAME}
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}.${PORTVERSION}

post-patch:
.for i in ${PORTNAME}.conf globals.h
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.pem|${ETCDIR}/${PORTNAME}.pem|' \
		${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.conf|${ETCDIR}/${PORTNAME}.conf|' \
		${WRKSRC}/globals.h

post-patch-OPENSSL-on:
	@${REINPLACE_CMD} 's|use_ssl = 0|use_ssl = 1|' ${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|^FLAGS =|FLAGS = ${CFLAGS}|" -e "s|^SSL =|SSL = ${LDFLAGS}|" \
		${WRKSRC}/Makefile

post-patch-RCNG-on:
	@${REINPLACE_CMD} 's|runasdaemon = 0|runasdaemon = 1|' ${WRKSRC}/${PORTNAME}.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pem ${STAGEDIR}${ETCDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
