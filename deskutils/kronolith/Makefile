# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	2.0.3
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/kronolith/				\
		ftp://ftp.planetmirror.com/pub/horde/kronolith/			\
		ftp://ftp.au.horde.org/pub/horde/kronolith/			\
		ftp://ftp.be.horde.org/kronolith/				\
		ftp://ftp.es.horde.org/pub/kronolith/				\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/kronolith/		\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/kronolith/		\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/kronolith/	\
		http://ftp.horde.org/pub/kronolith/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Kronolith is the Horde calendar application

#----------------------------------------------------------------------------
# You may define this option:
#
# - WITHOUT_MCAL:	you won't use the MCAL driver but a database backend
#			(only for PHP4).
#
#----------------------------------------------------------------------------

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_PHP=	yes	# modules set by Horde, but needed to get PHP_VER
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i ""
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO docs/UPGRADING
CONFFILE=	keywords.php menu.php prefs.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LKRONOLITHDIR?=	${LHORDEDIR}/kronolith

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	KRONOLITHDIR=${KRONOLITHDIR}
PLIST_SUB=	KRONOLITHDIR=${LKRONOLITHDIR}

KRONOLITHDIR=	${PREFIX}/${LKRONOLITHDIR}
CONFDIR=	${KRONOLITHDIR}/config
VAR_CAL=	/var/calendar

HORDE_INC=	${LOCALBASE}/etc/horde

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/sbin/htpasswd)
HTPASSWD=	${LOCALBASE}/sbin/htpasswd
.else
HTPASSWD=	${LOCALBASE}/bin/htpasswd
.endif

pre-configure:
	@${RM} ${WRKSRC}/config/conf.xml.orig
	@${SED} -e "s:/home/httpd/html/horde/kronolith:${KRONOLITHDIR}:"	\
		${FILESDIR}/httpd.conf.kronolith > ${WRKDIR}/httpd.conf.kronolith

do-install:
	@${MKDIR}  ${KRONOLITHDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${KRONOLITHDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${KRONOLITHDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${KRONOLITHDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd.conf.kronolith ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
.if !defined(WITHOUT_MCAL) && (${PHP_VER} == 4)
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
	   ${HTPASSWD} -bc ${LOCALBASE}/etc/mpasswd www $${PASSCAL}; \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:$${PASSCAL}:" ${CONFDIR}/conf.xml) \
	elif ! ${GREP} -q -e "^www" ${LOCALBASE}/etc/mpasswd ; then \
	  ${ECHO_MSG} "===> Adding www into ${LOCALBASE}/etc/mpasswd" ; \
	  ${ECHO} -n "Please enter a password for www's calendar: " ; \
	  (read PASSCAL;						\
	   ${HTPASSWD} -b ${LOCALBASE}/etc/mpasswd www $${PASSCAL} ; \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:$${PASSCAL}:" ${CONFDIR}/conf.xml) \
	else \
	   ${REINPLACE_CMD} -e "s:%%PASSCAL%%:www_cal_password:" ${CONFDIR}/conf.xml ; \
	fi
. endif
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
