# New ports collection makefile for:	bugzilla
# Date created:				28 September 2001
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	2.14.1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.mozilla.org/pub/${MASTER_SITE_SUBDIR}/ \
		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	webtools

MAINTAINER=	phantom@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${PERL_SITEDIR}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${PERL_SITEDIR}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql \
		${PERL_SITEDIR}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

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

NO_BUILD=	yes
BINMODE=	700
PKGMESSAGE=     ${WRKDIR}/pkg-message

PERL_SITEDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

BUGZILLADIR=	${PREFIX}/www/data.default/bugzilla
BUGZILLADOCS=	html images txt rel_notes.txt
BONSAIPERLWC=	*.cgi *.pl *.pm processmail syncshadowdb contrib/*.pl
SENDMAILWC=	*.pl *.pm processmail contrib/*.pl

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

post-patch:
	@find -d ${WRKSRC} -name CVS -type d -exec ${RM} -rf {} \;
	@find -d ${WRKSRC} -name sgml -type d -exec ${RM} -rf {} \;
	@find ${WRKSRC} -name .cvsignore -type f -exec ${RM} -f {} \;
	@find ${WRKSRC} -name README.docs -type f -exec ${RM} -f {} \;
	@find ${WRKSRC} -name \*.orig -type f -exec ${RM} -f {} \;
.for i in ${BONSAIPERLWC}
	@${PERL} -pi -e 's@#!/usr/bonsaitools/bin/perl@#!/usr/bin/perl@' \
		${WRKSRC}/$i
.endfor
.for i in ${SENDMAILWC}
	@${PERL} -pi -e 's@/usr/lib/sendmail@/usr/sbin/sendmail@' \
		${WRKSRC}/$i
.endfor

pre-install:
	@find ${WRKSRC}/docs -type d -exec ${CHMOD} 755 {} \;
	@find ${WRKSRC}/docs -type f -exec ${CHMOD} ${MANMODE} {} \;
	@find ${WRKSRC}/docs -type f -exec ${CHOWN} root:wheel {} \;

do-install:
	${MKDIR} ${BUGZILLADIR}
	find ${WRKSRC} \! -type d -maxdepth 1 \! -name UPGRADING* -exec \
		${INSTALL_SCRIPT} {} ${BUGZILLADIR} \;
.if !defined(NOPORTSDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} --unlink -C ${DOCSDIR} -xf -
.endif

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.endif

.include <bsd.port.mk>

