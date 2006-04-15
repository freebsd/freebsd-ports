# Ports collection makefile for:  Mnemo
# Date created:			  Sun May 19, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mnemo
PORTVERSION=	2.1
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

MAINTAINER=	shaun@inerd.com
COMMENT=	Mnemo is the Horde notes and memos application

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes

PLIST_SUB=	MNEMODIR=${LMNEMODIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	MNEMODIR=${MNEMODIR}

REINPLACE_ARGS=	-i ""
DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES  docs/TODO docs/UPGRADING
CONFFILE=	prefs.php
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LMNEMODIR?=	${LHORDEDIR}/mnemo

MNEMODIR=	${PREFIX}/${LMNEMODIR}
CONFDIR=	${MNEMODIR}/config

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@(cd ${WRKSRC}/scripts &&	\
		${FIND} . -name "*.php" -exec	\
		${REINPLACE_CMD} -e "s:/usr/local/bin/php: ${LOCALBASE}/bin/php:;s:/usr/bin/php: ${LOCALBASE}/bin/php:" {} \; )
	@${SED} -e "s:/home/httpd/html/horde/mnemo:${MNEMODIR}:g"	\
		${FILESDIR}/httpd.conf.mnemo > ${WRKDIR}/httpd-mnemo.conf

do-install:
	@${MKDIR}  ${MNEMODIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${MNEMODIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${MNEMODIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${MNEMODIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-mnemo.conf ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
