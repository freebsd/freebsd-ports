# New ports collection makefile for:	ja-mailman
# Date created:				21 Feb 2003
# Whom:					Sunagawa Koji <koj@ofug.net>
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.1.14.j7
PORTEPOCH=	1
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.python.jp/doc/contrib/mailman/_static/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.j/+j/}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	mailman

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Japanized mailman which is a mailing list manager with a web front-end

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gnu-COPYING-GPL

CONFLICTS=	mailman-2.1.*

USE_AUTOTOOLS=	autoconf
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	mailman

GNU_CONFIGURE_PREFIX=	${MAILMANDIR}
CONFIGURE_ARGS+=--with-python=${PYTHON_CMD} \
		--with-username=${MM_USERNAME} \
		--with-groupname=${MM_GROUPNAME} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID} \
		--with-permcheck=no
MAKE_JOBS_SAFE=	yes

# The Mailman port supports a number of variables that may be tweaked at
# build time.  Getting the values of some of them right is crucial!
#
MM_USERNAME?=	mailman
MM_USERID?=	91
MM_GROUPNAME?=	${MM_USERNAME}
MM_GROUPID?=	${MM_USERID}
MM_DIR?=	mailman
CGI_GID?=	www
IMGDIR?=	www/icons
#
# End of user-configurable variables.

USERS=		${MM_USERNAME}
GROUPS=		${MM_GROUPNAME}

MAILMANDIR=	${PREFIX}/${MM_DIR}
PLIST_SUB=	MMDIR=${MM_DIR} IMGDIR=${IMGDIR}
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	MAILMANDIR=${MAILMANDIR} USER=${MM_USERNAME} GROUP=${MM_GROUPNAME}

IMGFILES=	PythonPowered.png mailman.jpg mm-icon.png

PORTDOCS=	ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS NEWS.japan.utf-8 \
		README README-I18N.en README.CONTRIB README.NETSCAPE \
		README.USERAGENT README.japan.utf-8 STYLEGUIDE.txt \
		TODO UPGRADING \
		mailman-admin.txt \
		mailman-install.txt \
		mailman-member.txt \
		FreeBSD-post-install-notes

OPTIONS=	SENDMAIL "for use with sendmail" off \
		EXIM3 "for use with exim3" off \
		EXIM4 "for use with exim4" off \
		POSTFIX "for use with postfix" off \
		COURIER "for use with courier" off \
		INTEGRATION "integrating postfix and mailman" off \
		NAMAZU2 "make private archives searchable with namazu2" off

.include <bsd.port.options.mk>

.if defined(WITH_SENDMAIL)
.if defined(WITH_EXIM3) || defined(WITH_EXIM4) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
IGNORE=	can only have one MTA selected to integrate with
.endif
MAIL_GID?=	mailnull
.endif

.if defined(WITH_EXIM3)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM4) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
IGNORE=	can only have one MTA selected to integrate with
.endif
MAIL_GID?=	nobody
.endif

.if defined(WITH_EXIM4)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
IGNORE=	can only have one MTA selected to integrate with
.endif
MAIL_GID?=	mail
.endif

.if defined(WITH_POSTFIX)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_EXIM4) || \
defined(WITH_COURIER)
IGNORE=	can only have one MTA selected to integrate with
.endif
.if defined(WITH_INTEGRATION)
MAIL_GID?=	mailman
.else
MAIL_GID?=	nobody
.endif
EXTRA_PATCHES+=	${FILESDIR}/postfix-verp.diff
.endif

.if defined(WITH_COURIER)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_EXIM4) || \
defined(WITH_POSTFIX)
IGNORE=	can only have one MTA selected to integrate with
.endif
MAIL_GID?=	courier
.endif

.if defined(WITH_NAMAZU2)
RUN_DEPENDS+=	mknmz:${PORTSDIR}/japanese/namazu2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Mailman-Cgi-private.py
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may change the following build options:"
	@${ECHO} "MM_USERNAME=mailman	The username of the Mailman user."
	@${ECHO} "MM_USERID=91		The user ID of the Mailman user."
	@${ECHO} "MM_GROUPNAME=mailman	The group to which the Mailman user will belong."
	@${ECHO} "MM_GROUPID=MM_USERID	The group ID for the Mailman user."
	@${ECHO} "MM_DIR=mailman		Mailman will be installed in ${PREFIX}/${MM_DIR}."
	@${ECHO} "CGI_GID=www		The group name or id under which your web server executes CGI scripts."
	@${ECHO} "IMGDIR=www/icons	Icon images will be installed in ${PREFIX}/${IMGDIR}."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  ${WRKSRC}/Mailman/Defaults.py.in
	@${REINPLACE_CMD} -e 's/^0,5,10/#&/' ${WRKSRC}/cron/crontab.in.in

pre-configure:
	@${ECHO} "DEFAULT_SERVER_LANGUAGE = 'ja'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
	@${ECHO} "GLOBAL_PIPELINE.insert(1, 'iso2022jpfix')" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
.if defined(WITH_POSTFIX) && defined(WITH_INTEGRATION)
	@${ECHO} "MTA = 'Postfix'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
.endif

post-install:
	@${RM} -f ${MAILMANDIR}/pythonlib/*.egg-info
.for dir in cron scripts
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MAILMANDIR}/${dir}
.endfor
	@${CHGRP} -R ${MM_GROUPNAME} ${MAILMANDIR}
	@${MKDIR} ${PREFIX}/${IMGDIR}
.for imgfile in ${IMGFILES}
	@${CP} ${MAILMANDIR}/icons/${imgfile} ${PREFIX}/${IMGDIR}
.endfor
	@uudecode -p ${FILESDIR}/powerlogo.gif.uue > \
	  ${PREFIX}/${IMGDIR}/powerlogo.gif
.if !defined(NOPORTDOCS)
	@${CP} -R ${WRKSRC}/doc/* ${WRKSRC}/
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/FreeBSD-post-install-notes ${DOCSDIR}
.for docfile in ${PORTDOCS:NFreeBSD-post-install-notes}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_POSTFIX)
	@if [ "x`${LOCALBASE}/sbin/postconf -h myhostname`" != "xlocalhost" ]; then \
		${ECHO_CMD} ""; \
		${ECHO_CMD} "Your Postfix hostname is non-default."; \
		${ECHO_CMD} -n "You must add \"SMTPHOST = "; \
		${ECHO_CMD} -n `${LOCALBASE}/sbin/postconf -h myhostname`; \
		${ECHO_CMD} "\" to the bottom of mm_cfg.py."; \
		${ECHO_CMD} ""; \
		fi
.endif

.include <bsd.port.mk>
