# Ports collection makefile for:  WHUPS
# Date created:			  Sun Mar 03, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	whups
PORTVERSION=	0.0.1.020303
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://pompo.net/horde/whups/

MAINTAINER=	thierry@pompo.net
COMMENT=	WHUPS is a web-based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

BROKEN=		"Doesn't run with Horde 2.1 or 2.2"

NO_BUILD=	yes

USE_REINPLACE=	yes

DOCS=		LICENSE docs/CHANGES
CONFFILE=	conf.php html.php prefs.php
SUB_DIRS=	config graphics lib locale po scripts templates

LHORDEDIR?=	www/horde
LWHUPSDIR?=	${LHORDEDIR}/whups

PLIST_SUB=	HORDEDIR=${LHORDEDIR} WHUPSDIR=${LWHUPSDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
WHUPSDIR=		${PREFIX}/${LWHUPSDIR}
CONFDIR=	${WHUPSDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${RM} -f ${WRKSRC}/config/conf.php.dist.orig
	@${MKDIR}  ${WHUPSDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${WHUPSDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${WHUPSDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${WHUPSDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.whups ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/whups:${WHUPSDIR}:g" \
		${HORDE_INC}/httpd.conf.whups
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTWHUPS::" ${HORDEDIR}/config/registry.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%WHUPSDIR%%:${WHUPSDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%HORDEDIR%%:${HORDEDIR}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
