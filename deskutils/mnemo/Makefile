# Ports collection makefile for:  Mnemo
# Date created:			  Sun May 19, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mnemo
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/mnemo/				\
		ftp://ftp.au.horde.org/pub/horde/mnemo/			\
		ftp://ftp.es.horde.org/pub/mnemo/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/mnemo/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/mnemo/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/mnemo/

MAINTAINER=	thierry@pompo.net
COMMENT=	Mnemo is the Horde notes and memos application

RUN_DEPENDS=	${LOCALBASE}/www/horde/imp/index.php:${PORTSDIR}/mail/imp3

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeMnemo

PLIST_SUB=	HORDEDIR=${LHORDEDIR} MNEMODIR=${LMNEMODIR}

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL
CONFFILE=	conf.php menu.php prefs.php
SUB_DIRS=	config graphics lib locale po scripts templates util

LHORDEDIR?=	www/horde
LMNEMODIR?=	${LHORDEDIR}/mnemo

HORDEDIR=	${PREFIX}/${LHORDEDIR}
MNEMODIR=	${PREFIX}/${LMNEMODIR}
CONFDIR=	${MNEMODIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

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
	@${CHOWN} -R www:www ${MNEMODIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.mnemo ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/mnemo:${MNEMODIR}:g"	\
		${HORDE_INC}/httpd.conf.mnemo
	@${RM} ${HORDE_INC}/httpd.conf.mnemo.beforeMnemo
	@${CP} -p ${HORDEDIR}/config/registry.php		\
		${HORDEDIR}/config/registry.php.beforeMnemo
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTMNEMO::" ${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php		\
		${HORDEDIR}/config/registry.php.afterMnemo
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
	${SED} -e "s:%%MNEMODIR%%:${MNEMODIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%HORDEDIR%%:${HORDEDIR}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
