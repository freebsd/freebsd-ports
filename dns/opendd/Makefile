# New ports collection makefile for:	opendd
# Date created:				11 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	opendd
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.bsdmon.com/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A small DynDNS client

OPTIONS=	OPENSSL	"Build with SSL support"	on \
		RC_NG	"Install RC_NG script"		on

MAKE_JOBS_SAFE=	yes
PORTDOCS=	COPYING COPYRIGHT README
PLIST_FILES=	sbin/${PORTNAME} \
		"@unexec if cmp -s %D/%%ETCDIR%%/${PORTNAME}.conf %D/%%ETCDIR%%/${PORTNAME}.conf.default; then ${RM} -f %D/%%ETCDIR%%/${PORTNAME}.conf; fi " \
		"%%ETCDIR%%/${PORTNAME}.conf.default" \
		"@exec [ -f %B/${PORTNAME}.conf ] || ${CP} %B/%f %B/${PORTNAME}.conf" \
		"%%ETCDIR%%/${PORTNAME}.pem" \
		"@dirrmtry %%ETCDIR%%"

.include <bsd.port.pre.mk>

.if defined(WITH_RC_NG)
USE_RC_SUBR=	${PORTNAME}
.endif

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	"USE_SOCKET_SSL=yes"
.endif

pre-patch:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}.${PORTVERSION}

post-patch:
.if !defined(WITHOUT_OPENSSL)
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
.if defined(WITH_RC_NG)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
