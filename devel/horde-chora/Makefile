# Ports collection makefile for:  Chora
# Date created:			  Mon Nov 26, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	chora
PORTVERSION=	1.0
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.horde.org/pub/chora/tarballs/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/chora/tarballs/

MAINTAINER=	thierry@pompo.net

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde-devel

NO_BUILD=	yes

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

DOCS=		COPYING README  docs/BUGS docs/CHANGES docs/CREDITS \
		docs/GOALS docs/INSTALL
CONFFILE=	conf.php cvsroots.php html.php longIntro.txt \
		mime_drivers.php

LHORDEDIR?=	www/horde
LCHORADIR?=	${LHORDEDIR}/chora

PLIST_SUB=	HORDEDIR=${LHORDEDIR} CHORADIR=${LCHORADIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
CHORADIR=	${PREFIX}/${LCHORADIR}
CONFDIR=	${CHORADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${MKDIR}  ${CHORADIR}
	@${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${CHORADIR}
	@${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/po ${WRKSRC}/templates ${CHORADIR}
	@${CP} -p  ${WRKSRC}/*.php ${CHORADIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${PERL} -pi -e "s:%%CVSROOT%%:${CVSROOT}:;s:%%CONFDIR%%:${CONFDIR}:" \
		${CONFDIR}/cvsroots.php
	@${CHOWN} -R www:www ${CHORADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.chora ${HORDE_INC}
	@${PERL} -pi -e "s:/home/httpd/html/horde/chora:${CHORADIR}:g" \
		${HORDE_INC}/httpd.conf.chora
	@${PERL} -pi -e "s://UNCOMMENTWHENINSTCHORA::" \
		${HORDEDIR}/config/registry.php
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
