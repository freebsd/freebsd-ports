# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	opendd
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.bsdmon.com/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small DynDNS client

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

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

NO_STAGE=	yes
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

BROKEN=	segfaults upon use

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${ETCDIR}/${PORTNAME}.conf.default
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pem ${ETCDIR}
.if !exists(${ETCDIR}/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${ETCDIR}
.endif
	@${CHMOD} 600 ${ETCDIR}/*.conf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
