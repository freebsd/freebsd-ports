# Ports collection makefile for:  Nag
# Date created:			  Sun Dec 14, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nag
PORTVERSION=	2.0
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/nag/				\
		ftp://ftp.planetmirror.com/pub/horde/nag/		\
		ftp://ftp.au.horde.org/pub/horde/nag/			\
		ftp://ftp.be.horde.org/nag/				\
		ftp://ftp.es.horde.org/pub/nag/				\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/nag/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/nag/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/nag/	\
		http://ftp.horde.org/pub/nag/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Nag is a simple, multiuser task list manager

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_REINPLACE=	yes

PLIST_SUB=	NAGDIR=${LNAGDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO docs/UPGRADING
CONFFILE=	menu.php prefs.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LNAGDIR?=	${LHORDEDIR}/nag

NAGDIR=		${PREFIX}/${LNAGDIR}
CONFDIR=	${NAGDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/nag:${NAGDIR}:g"		\
		${FILESDIR}/httpd.conf.nag > ${WRKDIR}/httpd.conf.nag

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
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${NAGDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd.conf.nag ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SED} -e "s:%%NAGDIR%%:${NAGDIR}:g;s:%%DOCSDIR%%:${DOCSDIR}:g"	\
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
