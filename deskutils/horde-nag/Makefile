# Ports collection makefile for:  Nag
# Date created:			  Sun Dec 14, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nag
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/nag/tarballs/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	thierry@pompo.net
COMMENT=	Nag is a simple, multiuser task list manager

RUN_DEPENDS=	${LOCALBASE}/www/horde/imp/index.php:${PORTSDIR}/mail/imp3

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeNag

PLIST_SUB=	HORDEDIR=${LHORDEDIR} NAGDIR=${LNAGDIR}

DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL \
		docs/TODO
CONFFILE=	conf.php html.php menu.php motd.php prefs.php
SUB_DIRS=	config graphics lib locale po scripts templates

LHORDEDIR?=	www/horde
LNAGDIR?=	${LHORDEDIR}/nag

HORDEDIR=	${PREFIX}/${LHORDEDIR}
NAGDIR=		${PREFIX}/${LNAGDIR}
CONFDIR=	${NAGDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${MKDIR}  ${NAGDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${NAGDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${NAGDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${NAGDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.nag ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/nag:${NAGDIR}:g" \
		${HORDE_INC}/httpd.conf.nag
	@${RM} ${HORDE_INC}/httpd.conf.nag.beforeNag
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTNAG::" ${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php		\
		${HORDEDIR}/config/registry.php.afterNag
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
	${SED} -e "s:%%NAGDIR%%:${NAGDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%HORDEDIR%%:${HORDEDIR}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
