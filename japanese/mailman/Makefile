# Created by: Sunagawa Koji <koj@ofug.net>
# $FreeBSD$

PORTNAME=	mailman
PORTVERSION=	2.1.14.j7
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.python.jp/doc/contrib/mailman/_static/ \
		LOCAL/tota/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.j/+j/}
DIST_SUBDIR=	mailman

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Japanized mailman which is a mailing list manager with a web front-end

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gnu-COPYING-GPL

CONFLICTS=	mailman-2.1.*

PORTSCOUT=	limit:.*\.j\d+$$

USES=		autoreconf gettext python:2.7 tar:tgz
USE_RC_SUBR=	mailman

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${MAILMANDIR}
CONFIGURE_ARGS+=--with-python=${PYTHON_CMD} \
		--with-username=${MM_USERNAME} \
		--with-groupname=${MM_GROUPNAME} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID} \
		--with-permcheck=no

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

OPTIONS_DEFINE=	DOCS NAMAZU2

OPTIONS_SINGLE=	MTA
OPTIONS_SINGLE_MTA=	SENDMAIL EXIM4 POSTFIX COURIER

NAMAZU2_DESC=	Make private archives searchable with namazu2
MTA_DESC=	Integrate with which MTA?
SENDMAIL_DESC=	for use with sendmail
EXIM4_DESC=	for use with exim4
POSTFIX_DESC=	for use with postfix
COURIER_DESC=	for use with courier

OPTIONS_DEFAULT=	SENDMAIL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSENDMAIL}
MAIL_GID?=	mailnull
.endif

.if ${PORT_OPTIONS:MEXIM4}
MAIL_GID?=	mail
.endif

.if ${PORT_OPTIONS:MPOSTFIX}
RUN_DEPENDS+=	${LOCALBASE}/sbin/postconf:mail/postfix
BUILD_DEPENDS+=	${LOCALBASE}/sbin/postconf:mail/postfix
MAIL_GID?=	mailman
EXTRA_PATCHES+=	${FILESDIR}/postfix-verp.diff
.endif

.if ${PORT_OPTIONS:MCOURIER}
MAIL_GID?=	courier
.endif

.if ${PORT_OPTIONS:MNAMAZU2}
RUN_DEPENDS+=	mknmz:japanese/namazu2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Mailman-Cgi-private.py
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may change the following build options:"
	@${ECHO} ""
	@${ECHO} "Option		Default Value	Description"
	@${ECHO} "-------------	---------------	------------------------------------------------"
	@${ECHO} "MM_USERNAME	mailman		The username of the Mailman user."
	@${ECHO} "MM_USERID	91		The user ID of the Mailman user."
	@${ECHO} "MM_GROUPNAME	mailman		The group to which the Mailman user will belong."
	@${ECHO} "MM_GROUPID	\$$MM_USERID	The group ID for the Mailman user."
	@${ECHO} "MM_DIR		mailman		Mailman will be installed in"
	@${ECHO} "				${PREFIX}/${MM_DIR}."
	@${ECHO} "CGI_GID		www		The group name or id under which your web"
	@${ECHO} "				server executes CGI scripts."
	@${ECHO} "IMGDIR		www/icons	Icon images will be installed in"
	@${ECHO} "				${PREFIX}/${IMGDIR}."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  ${WRKSRC}/Mailman/Defaults.py.in
	@${REINPLACE_CMD} -e 's/^0,5,10/#&/' ${WRKSRC}/cron/crontab.in.in

pre-configure:
	@${ECHO} "DEFAULT_SERVER_LANGUAGE = 'ja'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
	@${ECHO} "GLOBAL_PIPELINE.insert(1, 'iso2022jpfix')" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
.if ${PORT_OPTIONS:MPOSTFIX}
	@${ECHO} "MTA = 'Postfix'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
.endif

post-install:
.for i in admin admindb confirm create edithtml listinfo options private \
	rmlist roster subscribe
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/cgi-bin/${i}
.endfor
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/mail/mailman
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/pythonlib/pykf.so
# Compile additional Python scripts:
.for dir in Mailman bin pythonlib
	(cd ${STAGEDIR}${MAILMANDIR} \
	    && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	    -f -d ${MAILMANDIR}/${dir} ${dir})
.endfor
	@${RM} ${STAGEDIR}${MAILMANDIR}/pythonlib/*.egg-info
	# mm_cfg.py is handled by pkg-plist:
	@${RM} ${STAGEDIR}${MAILMANDIR}/Mailman/mm_cfg.py
	@${RM} ${STAGEDIR}${MAILMANDIR}/Mailman/mm_cfg.pyc
	@${MKDIR} ${STAGEDIR}${PREFIX}/${IMGDIR}
.for imgfile in ${IMGFILES}
	${CP} ${STAGEDIR}${MAILMANDIR}/icons/${imgfile} ${STAGEDIR}${PREFIX}/${IMGDIR}
.endfor
	uudecode -p ${FILESDIR}/powerlogo.gif.uue > \
	  ${STAGEDIR}${PREFIX}/${IMGDIR}/powerlogo.gif
.if ${PORT_OPTIONS:MDOCS}
	${CP} -R ${WRKSRC}/doc/* ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/FreeBSD-post-install-notes ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS:NFreeBSD-post-install-notes}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${ECHO} "This marker file ensures that Python's upgrade-site-packages handles ${PKGNAME}." >${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mailman-info.txt
.if ${PORT_OPTIONS:MPOSTFIX}
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
