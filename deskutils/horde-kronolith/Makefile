# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/kronolith/tarballs/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	thierry@pompo.net

RUN_DEPENDS=	${LOCALBASE}/www/horde/imp/index.php:${PORTSDIR}/mail/imp3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

IS_INTERACTIVE=	'need to build mod_php4 with MCAL option set.'
NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeKronolith
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL docs/TODO
CONFFILE=	conf.php html.php keywords.php menu.php prefs.php
SUB_DIRS=	config graphics lib locale po scripts templates

LHORDEDIR?=	www/horde
LKRONOLITHDIR?=	${LHORDEDIR}/kronolith

PLIST_SUB=	HORDEDIR=${LHORDEDIR} KRONOLITHDIR=${LKRONOLITHDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
KRONOLITHDIR=	${PREFIX}/${LKRONOLITHDIR}
CONFDIR=	${KRONOLITHDIR}/config
VAR_CAL=	/var/calendar

HORDE_INC=	${LOCALBASE}/etc/horde

pre-install:
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "mcal.0" ; then \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please configure PHP and Horde with MCAL support enabled." ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi

do-install:
	@${MKDIR}  ${KRONOLITHDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${KRONOLITHDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${KRONOLITHDIR}
	@${MKDIR} ${KRONOLITHDIR}/scripts
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${KRONOLITHDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.kronolith ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/kronolith:${KRONOLITHDIR}:g" \
		${HORDE_INC}/httpd.conf.kronolith
	@${RM} ${HORDE_INC}/httpd.conf.kronolith.beforeKronolith
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTKRONOLITH::" \
		${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php		\
		${HORDEDIR}/config/registry.php.afterKronolith
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@if [ ! -d ${VAR_CAL} ]; then \
	  ${ECHO_MSG} "===> Creating ${VAR_CAL}" ; \
	  ${MKDIR} ${VAR_CAL} ; \
	  ${CHMOD} 1777 ${VAR_CAL} ; \
	fi
.if !defined(BATCH)
	@if [ ! -f ${LOCALBASE}/etc/mpasswd ] ; then \
	  ${ECHO_MSG} "===> Creating ${LOCALBASE}/etc/mpasswd" ; \
	  ${ECHO} -n "Please enter a password for www's calendar: " ; \
	  (read PASSCAL;						\
	   ${LOCALBASE}/bin/htpasswd -bc ${LOCALBASE}/etc/mpasswd www $${PASSCAL}; \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:$${PASSCAL}:" ${CONFDIR}/conf.php) \
	elif ! ${GREP} -q -e "^www" ${LOCALBASE}/etc/mpasswd ; then \
	  ${ECHO_MSG} "===> Adding www into ${LOCALBASE}/etc/mpasswd" ; \
	  ${ECHO} -n "Please enter a password for www's calendar: " ; \
	  (read PASSCAL;						\
	   ${LOCALBASE}/bin/htpasswd -b ${LOCALBASE}/etc/mpasswd www $${PASSCAL} ; \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:$${PASSCAL}:" ${CONFDIR}/conf.php) \
	else \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:www_cal_password:" ${CONFDIR}/conf.php ; \
	fi
	@${RM} ${CONFDIR}/conf.php.beforeKronolith
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%KRONOLITHDIR%%:${KRONOLITHDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%LOCALBASE%%:${LOCALBASE}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
