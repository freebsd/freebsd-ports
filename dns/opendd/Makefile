# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	opendd
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.bsdmon.com/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DynDNS client

OPTIONS_DEFINE=	OPENSSL RCNG DOCS
OPTIONS_DEFAULT=	OPENSSL RCNG
RCNG_DESC=	Install RC_NG script

PORTDOCS=	COPYING COPYRIGHT README
PLIST_FILES=	sbin/${PORTNAME} \
		"@unexec if cmp -s %D/%%ETCDIR%%/${PORTNAME}.conf %D/%%ETCDIR%%/${PORTNAME}.conf.default; then ${RM} -f %D/%%ETCDIR%%/${PORTNAME}.conf; fi " \
		"%%ETCDIR%%/${PORTNAME}.conf.default" \
		"@exec [ -f %B/${PORTNAME}.conf ] || ${CP} %B/%f %B/${PORTNAME}.conf" \
		"%%ETCDIR%%/${PORTNAME}.pem" \
		"@dirrmtry %%ETCDIR%%"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRCNG}
USE_RC_SUBR=	${PORTNAME}
.endif

.if ${PORT_OPTIONS:MOPENSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	"USE_SOCKET_SSL=yes"
.endif

pre-patch:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}.${PORTVERSION}

post-patch:
.if ${PORT_OPTIONS:MOPENSSL}
	@${REINPLACE_CMD} 's|use_ssl = 0|use_ssl = 1|' ${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|^FLAGS =|FLAGS = ${CFLAGS}|" -e "s|^SSL =|SSL = ${LDFLAGS}|" \
	    ${WRKSRC}/Makefile
.endif
.for i in ${PORTNAME}.conf globals.h
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.pem|${ETCDIR}/${PORTNAME}.pem|' \
	    ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.conf|${ETCDIR}/${PORTNAME}.conf|' \
	    ${WRKSRC}/globals.h
.if ${PORT_OPTIONS:MRCNG}
	@${REINPLACE_CMD} 's|runasdaemon = 0|runasdaemon = 1|' ${WRKSRC}/${PORTNAME}.conf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.default
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pem ${STAGEDIR}${ETCDIR}
	${CHMOD} 600 ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.default
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
