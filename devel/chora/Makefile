# Ports collection makefile for:  Chora
# Date created:			  Mon Nov 26, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	chora
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.horde.org/pub/chora/				\
		ftp://ftp.au.horde.org/pub/horde/chora/			\
		ftp://ftp.es.horde.org/pub/chora/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/chora/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/chora/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/chora/

MAINTAINER=	thierry@pompo.net
COMMENT=	The Horde CVS web-viewer

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_ENSCRIPT	: if you do not need syntax highlighting;
#
# - A4 or DJ		: if you run enscript with this paper size.
#
#-----------------------------------------------------------------------

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2
.if !defined(WITHOUT_ENSCRIPT)
.if defined(A4)
RUN_DEPENDS+=	${LOCALBASE}/bin/enscript:${PORTSDIR}/print/enscript-a4
.elif defined(DJ)
RUN_DEPENDS+=	${LOCALBASE}/bin/enscript:${PORTSDIR}/print/enscript-letterdj
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/enscript:${PORTSDIR}/print/enscript-letter
.endif
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i.beforeChora

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

DOCS=		COPYING README  docs/BUGS docs/CHANGES docs/CREDITS \
		docs/GOALS docs/INSTALL
CONFFILE=	conf.php cvsroots.php html.php longIntro.txt \
		mime_drivers.php prefs.php
SUB_DIRS=	config graphics lib locale po templates

LHORDEDIR?=	www/horde
LCHORADIR?=	${LHORDEDIR}/chora

PLIST_SUB=	HORDEDIR=${LHORDEDIR} CHORADIR=${LCHORADIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
CHORADIR=	${PREFIX}/${LCHORADIR}
CONFDIR=	${CHORADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${MKDIR}  ${CHORADIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${CHORADIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${CHORADIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${REINPLACE_CMD} -e "s:%%CVSROOT%%:${CVSROOT}:;s:%%CONFDIR%%:${CONFDIR}:" \
		${CONFDIR}/cvsroots.php
	@${RM} ${CONFDIR}/cvsroots.php.beforeChora
	@${CHOWN} -R www:www ${CHORADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.chora ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/chora:${CHORADIR}:g" \
		${HORDE_INC}/httpd.conf.chora
	@${RM} ${HORDE_INC}/httpd.conf.chora.beforeChora
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTCHORA::" \
		${HORDEDIR}/config/registry.php
.if !defined(WITHOUT_ENSCRIPT)
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTCHORA::" \
		${HORDEDIR}/config/mime_drivers.php
.endif
	@${CP} -p ${HORDEDIR}/config/registry.php		\
		${HORDEDIR}/config/registry.php.afterChora
	@${CP} -p ${HORDEDIR}/config/mime_drivers.php		\
		${HORDEDIR}/config/mime_drivers.php.afterChora
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
	${SED} -e "s:%%CHORADIR%%:${CHORADIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
