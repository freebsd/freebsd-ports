# Ports collection makefile for:  Chora
# Date created:			  Mon Nov 26, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	chora
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.horde.org/pub/chora/				\
		ftp://ftp.planetmirror.com/pub/horde/chora/		\
		ftp://ftp.au.horde.org/pub/horde/chora/			\
		ftp://ftp.be.horde.org/chora/				\
		ftp://ftp.es.horde.org/pub/chora/			\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/chora/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/chora/	\
		http://ftp.horde.org/pub/chora/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	The Horde CVS web-viewer

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SVN		: if you don't need subversion;
#
# - WITHOUT_CVSPS	: if you don't need cvsps;
#
# - WITHOUT_CVSGRAPH	: if you don't need cvsgraph;
#
# - A4 or DJ		: if you run enscript with this paper size.
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

.if !defined(WITHOUT_SVN)
RUN_DEPENDS+=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion
.endif

.if !defined(WITHOUT_CVSPS)
RUN_DEPENDS+=	${LOCALBASE}/bin/cvsps:${PORTSDIR}/devel/cvsps-devel
.endif

.if !defined(WITHOUT_CVSGRAPH)
RUN_DEPENDS+=	${LOCALBASE}/bin/cvsgraph:${PORTSDIR}/devel/cvsgraph
.endif

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

DOCS=		COPYING README docs/BUGS docs/CHANGES docs/CREDITS \
		docs/INSTALL docs/RELEASE_NOTES docs/TODO
CONFFILE=	cvsgraph.conf longIntro.txt mime_drivers.php prefs.php	\
		sourceroots.php
SUB_DIRS=	config lib locale po templates themes

LHORDEDIR?=	www/horde
LCHORADIR=	${LHORDEDIR}/chora

PLIST_SUB=	CHORADIR=${LCHORADIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	CHORADIR=${CHORADIR} CONFDIR=${CONFDIR}

CHORADIR=	${PREFIX}/${LCHORADIR}
CONFDIR=	${CHORADIR}/config

PATCH2RM=	sourceroots.php.dist.orig sourceroots.php.dist.bak conf.xml.bak

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/chora:${CHORADIR}:"	\
		${FILESDIR}/httpd.conf.chora > ${WRKDIR}/httpd-chora.conf
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"		\
		-e "s|/usr/bin/cvsgraph|${LOCALBASE}/bin/cvsgraph|"	\
		-e "s|/usr/bin/svn|${LOCALBASE}/bin/svn|"		\
		${WRKSRC}/config/conf.xml
	@${REINPLACE_CMD} -e "s|%%CVSROOT%%|${CVSROOT}|"		\
		-e "s|%%CONFDIR%%|${CONFDIR}|"				\
		${WRKSRC}/config/sourceroots.php.dist
.for FILE in ${PATCH2RM}
	@${RM} ${WRKSRC}/config/${FILE}
.endfor

pre-install:
.if !defined(WITHOUT_CVSPS)
	@if ! pkg_info -I -x cvsps-devel > /dev/null ; then \
	  ${ECHO_MSG} "Error: cvsps-devel is required, not cvsps." ; \
	  ${FALSE} ; \
	fi
.endif

do-install:
	@${MKDIR}  ${CHORADIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${CHORADIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${CHORADIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${CHORADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-chora.conf ${HORDE_INC}
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
