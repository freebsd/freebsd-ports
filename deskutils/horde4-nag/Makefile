# Ports collection makefile for:  Nag
# Date created:			  Sun Dec 14, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nag
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	ftp://ftp.horde.org/pub/nag/tarballs/
DISTNAME=	${PORTNAME}-${PORTVERSION}-RC3

MAINTAINER=	thierry@pompo.net

RUN_DEPENDS=	${LOCALBASE}/www/horde/imp/index.php:${PORTSDIR}/mail/imp3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
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
	@${PERL} -pi -e "s:/home/httpd/html/horde/nag:${NAGDIR}:g" \
		${HORDE_INC}/httpd.conf.nag
	@${PERL} -pi -e "s://UNCOMMENTWHENINSTNAG::" ${HORDEDIR}/config/registry.php
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
