# New ports collection makefile for:	bugzilla
# Date created:				28 September 2001
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	2.16.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	webtools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bug-tracking system developed by Mozilla Project

RUN_DEPENDS=	${PERL_SITEDIR}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql \
		${PERL_SITEDIR}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${PERL_SITEDIR}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${PERL_SITEDIR}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap

.if !defined(WITHOUT_BUG_CHARTING_MODULES)
RUN_DEPENDS+=	${PERL_SITEDIR}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${PERL_SITEDIR}/Chart/Base.pm:${PORTSDIR}/graphics/p5-chart
.endif

.if defined(WITH_BUG_MAILING_MODULES)
RUN_DEPENDS+=	${PERL_SITEDIR}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools
.endif

.if defined(WITH_BUG_EXPORT_AND_IMPORT)
RUN_DEPENDS+=	${PERL_SITEDIR}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
.endif

.if defined(WITH_CONTRIB)
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

USE_REINPLACE=	yes

NO_BUILD=	yes
BINMODE=	700
PKGMESSAGE=	${WRKDIR}/pkg-message

PERL_SITEDIR=	${SITE_PERL}

BUGZILLADIR?=	www/data/bugzilla
BUGZILLADOCS=	html images txt rel_notes.txt
BONSAIPERLWC=	*.cgi *.pl *.pm processmail syncshadowdb contrib/*.pl
SENDMAILWC=	*.pl *.pm processmail contrib/*.pl

PLIST_SUB+=	BUGZILLADIR=${BUGZILLADIR}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_BUG_CHARTING_MODULES do not install perl modules required for bug"
	@${ECHO_MSG} "                               charting support"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_BUG_MAILING_MODULES     install perl modules required for bug mailing"
	@${ECHO_MSG} "                               support (contrib/bug_email.pl) interface"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_BUG_EXPORT_AND_IMPORT   install perl modules required for bug"
	@${ECHO_MSG} "                               export/import feature to move bugs to or from"
	@${ECHO_MSG} "                               other bugzilla installations"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CONTRIB                 to install various user-contributed scripts,"
	@${ECHO_MSG} "                               e.g. to import bugs from other databases, to"
	@${ECHO_MSG} "                               allow follow-ups/submissions by e-mail etc."
	@${ECHO_MSG} ""

post-patch:
	@${FIND} -d ${WRKSRC} -name CVS -type d -exec ${RM} -rf {} \;
	@${FIND} -d ${WRKSRC} -name sgml -type d -exec ${RM} -rf {} \;
	@${FIND} ${WRKSRC} -name .cvsignore -type f -exec ${RM} -f {} \;
	@${FIND} ${WRKSRC} -name README.docs -type f -exec ${RM} -f {} \;
	@${FIND} ${WRKSRC} -name \*.orig -type f -exec ${RM} -f {} \;
.for i in ${BONSAIPERLWC}
	@${REINPLACE_CMD} -e 's@#!/usr/bonsaitools/bin/perl@#!/usr/bin/perl@' \
		${WRKSRC}/$i
.endfor
.for i in ${SENDMAILWC}
	@${REINPLACE_CMD} -e 's@/usr/lib/sendmail@/usr/sbin/sendmail@' \
		${WRKSRC}/$i
.endfor
	@${FIND} ${WRKSRC} -name \*.bak -type f -exec ${RM} -f {} \;

pre-install:
	@${FIND} ${WRKSRC}/docs -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${WRKSRC}/docs -type f -exec ${CHMOD} ${MANMODE} {} \;
	@${FIND} ${WRKSRC}/docs -type f -exec ${CHOWN} root:wheel {} \;

do-install:
	${MKDIR} ${PREFIX}/${BUGZILLADIR}
	${FIND} ${WRKSRC} \! -type d -maxdepth 1 \! -name UPGRADING* -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/${BUGZILLADIR} \;
	${TAR} -C ${WRKSRC} -cf - template css | ${TAR} --unlink -C ${PREFIX}/${BUGZILLADIR} -xf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} --unlink -C ${DOCSDIR} -xf -
.endif
.if defined(WITH_CONTRIB)
	${MKDIR} ${PREFIX}/${BUGZILLADIR}/contrib ${PREFIX}/${BUGZILLADIR}/contrib/cmdline
	cd ${WRKSRC}/contrib; ${INSTALL_SCRIPT} BugzillaEmail.pm bug_email.pl \
		bugzilla_email_append.pl cvs-update.sh gnats2bz.pl jb2bz.py \
		mysqld-watcher.pl yp_nomail.sh ${PREFIX}/${BUGZILLADIR}/contrib
	cd ${WRKSRC}/contrib/cmdline; ${INSTALL_SCRIPT} buglist bugs \
		query.conf ${PREFIX}/${BUGZILLADIR}/contrib/cmdline
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/contrib
	cd ${WRKSRC}/contrib; ${INSTALL_DATA} README README.Mailif \
		bugmail_help.html bugzilla.procmailrc ${DOCSDIR}/contrib
.endif
.endif

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
