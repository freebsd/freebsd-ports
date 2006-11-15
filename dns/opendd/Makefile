# New ports collection makefile for:	opendd
# Date created:				11 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	opendd
PORTVERSION=	0.7.7
CATEGORIES=	dns
MASTER_SITES=	http://www.bsdmon.com/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@logvinov.com
COMMENT=	A small DynDNS client

OPTIONS=	OPENDD_SSL	"Build with SSL support"	off \
		RC_NG		"Install RC_NG script"		on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING COPYRIGHT README
PLIST_FILES=	sbin/${PORTNAME} \
		"@unexec if cmp -s %D/etc/${PORTNAME}/${PORTNAME}.conf %D/etc/${PORTNAME}/${PORTNAME}.conf.default; then ${RM} -f %D/etc/${PORTNAME}/${PORTNAME}.conf; fi " \
		"etc/${PORTNAME}/${PORTNAME}.conf.default" \
		"etc/${PORTNAME}/${PORTNAME}.pem" \
		"@dirrmtry etc/${PORTNAME}"

.include <bsd.port.pre.mk>

.if defined(WITH_RC_NG)
USE_RC_SUBR=	opendd
.endif

.if defined(WITH_OPENDD_SSL) && !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	"USE_SOCKET_SSL=yes"
.endif

pre-patch:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
.if defined(WITH_OPENDD_SSL) && !defined(WITHOUT_SSL)
	@${REINPLACE_CMD} 's|use_ssl = 0|use_ssl = 1|' ${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|^FLAGS =|FLAGS        = ${CFLAGS}|" ${WRKSRC}/Makefile
.endif
.for i in ${PORTNAME}.conf globals.h
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.pem|${PREFIX}/etc/${PORTNAME}/${PORTNAME}.pem|' \
	    ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}.conf|${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf|' \
	    ${WRKSRC}/globals.h
.if defined(WITH_RC_NG)
	@${REINPLACE_CMD} 's|runasdaemon = 0|runasdaemon = 1|' ${WRKSRC}/${PORTNAME}.conf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.default
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pem ${PREFIX}/etc/${PORTNAME}/
.if !exists(${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}/
.endif
	@${CHMOD} 600 ${PREFIX}/etc/${PORTNAME}/*.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
