# Ports collection makefile for:  Mnemo
# Date created:			  Sun May 19, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mnemo
PORTVERSION=	2.0.1
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/mnemo/				\
		ftp://ftp.planetmirror.com/pub/horde/mnemo/		\
		ftp://ftp.au.horde.org/pub/horde/mnemo/			\
		ftp://ftp.be.horde.org/mnemo/				\
		ftp://ftp.es.horde.org/pub/mnemo/			\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/mnemo/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/mnemo/	\
		http://ftp.horde.org/pub/mnemo/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mnemo is the Horde notes and memos application

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_REINPLACE=	yes

PLIST_SUB=	MNEMODIR=${LMNEMODIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES  docs/TODO docs/UPGRADING
CONFFILE=	prefs.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LMNEMODIR?=	${LHORDEDIR}/mnemo

MNEMODIR=	${PREFIX}/${LMNEMODIR}
CONFDIR=	${MNEMODIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/mnemo:${MNEMODIR}:g"	\
		${FILESDIR}/httpd.conf.mnemo > ${WRKDIR}/httpd.conf.mnemo

do-install:
	@${MKDIR}  ${MNEMODIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${MNEMODIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${MNEMODIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then			\
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ;	\
	fi
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${MNEMODIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd.conf.mnemo ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SED} -e "s:%%MNEMODIR%%:${MNEMODIR}:g;s:%%DOCSDIR%%:${DOCSDIR}:g"	\
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
