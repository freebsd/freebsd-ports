# New ports collection makefile for:	bugzilla
# Date created:				28 September 2001
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	bugzilla
PORTVERSION?=	2.18.1
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	webtools webtools/archived

MAINTAINER?=	skv@FreeBSD.org
COMMENT?=	Bug-tracking system developed by Mozilla Project

OPTIONS=	CHARTING_MODULES "Bug charting support" on \
		GRAPHVIZ "Use GraphViz" off \
		EMAIL_GATEWAY "Use email gateway" off \
		EXPORT_IMPORT "Import/export bugs (via XML)" off \
		CONTRIB	"Install user-contributed scripts" off \
		LDAP "Enable LDAP support" off

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/PatchReader.pm:${PORTSDIR}/devel/p5-PatchReader

CONFLICTS?=	ja-bugzilla-2.*

USE_REINPLACE=	yes

BINMODE=	700
PKGMESSAGE=	${WRKDIR}/pkg-message

.ifndef BUGZILLADIR
.ifdef APACHE_DATADIR
BUGZILLADIR=	${APACHE_DATADIR}/data/bugzilla
.else
BUGZILLADIR=	${PREFIX}/www/data/bugzilla
.endif
.endif

PLIST_SUB+=	BUGZILLADIR=${BUGZILLADIR:S!^${PREFIX}/!!}

CONTRIB_DOCS=	README README.Mailif bugmail_help.html bugzilla.procmailrc

.include <bsd.port.pre.mk>

.ifdef WITH_CHARTING_MODULES
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/Chart/Base.pm:${PORTSDIR}/graphics/p5-chart \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text/Align.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
.endif

.ifdef WITH_GRAPHVIZ
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.ifdef WITH_EMAIL_GATEWAY
RUN_DEPENDS+=	${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools
.endif

.ifdef WITH_EXPORT_IMPORT
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
.endif

.ifdef WITH_CONTRIB
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.ifdef WITH_LDAP
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

post-patch:
	@${FIND} ${WRKSRC} \( -name "CVS" -or -name ".cvsignore" -or -name "*.orig" \
		-or -name "README.docs" \) | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC} -name "*.p[ml]" | \
		${XARGS} ${REINPLACE_CMD} -i '' -e 's!/usr/lib/sendmail!/usr/sbin/sendmail!'

do-build:
	@${SED} -e "s:%%BUGZILLADIR%%:${BUGZILLADIR}:g; s:%%DOCSDIR%%:${DOCSDIR}:g" \
		${MASTERDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${MKDIR} ${BUGZILLADIR}
	${FIND} ${WRKSRC} \! -type d -maxdepth 1 \! -name "UPGRADING*" -exec \
		${INSTALL_SCRIPT} {} ${BUGZILLADIR} \;
.for D in css js skins/standard
	@${MKDIR} ${BUGZILLADIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/${D}/*.* ${BUGZILLADIR}/${D}
.endfor
	${TAR} -C ${WRKSRC} -cf - Bugzilla template | ${TAR} --unlink -C ${BUGZILLADIR} -xf -
.ifndef NOPORTDOCS
.for D in html images/callouts images pdf txt xml ""
	${MKDIR} ${DOCSDIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/docs/${D}/*.* ${DOCSDIR}/${D}/
.endfor
.endif
.ifdef WITH_CONTRIB
	${MKDIR} ${BUGZILLADIR}/contrib
	@cd ${WRKSRC}/contrib && \
		${FIND} . -type d -exec ${MKDIR} "${BUGZILLADIR}/contrib/{}" \; && \
		${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${BUGZILLADIR}/contrib/{}" \;
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}/contrib
	${INSTALL_DATA} ${CONTRIB_DOCS:S!^!${WRKSRC}/contrib/!} ${DOCSDIR}/contrib
.endif
.endif
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
