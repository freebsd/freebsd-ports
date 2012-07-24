# New ports collection makefile for:	bugzilla
# Date created:				28 September 2001
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	3.6.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	webtools webtools/archived

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Bug-tracking system developed by Mozilla Project

LICENSE=	MPL

RUN_DEPENDS=	\
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-DBI>=1.41:${PORTSDIR}/databases/p5-DBI \
		p5-Template-Toolkit>=2.22:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-TimeZone>=0.71:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-CGI.pm>=3.51:${PORTSDIR}/www/p5-CGI.pm \
		p5-Email-Send>=2.00:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-MIME>=1.861:${PORTSDIR}/mail/p5-Email-MIME

LATEST_LINK=	bugzilla3

USE_PERL5=	yes

BINMODE=	700

SUB_FILES=	pkg-message

DATA_DIRS_LIST=	images js skins

.include "${.CURDIR}/Makefile.common"

OPTIONS=	MYSQL "MySQL database support" off \
		PGSQL "PostgreSQL database support" off \
		GRAPH_REPORTS "Graphical Reports" on \
		CHARTING_MODULES "Bug charting support" on \
		PATCH_VIEWER "Patch Viewer" on \
		MORE_HTML "More HTML in Product/Group Descriptions" on \
		INBOUND_EMAIL "Inbound Email" off \
		MAIL_QUEUEING "Mail Queueing" off \
		MOVE_BUGZ "Move Bugs Between Installations" off \
		BMP2PNG "BMP Attachments to PNGs" off \
		XMLRPC "XML-RPC Interface" off \
		JSONRPC "JSON-RPC Interface" off \
		MODPERL2 "With mod_perl2 support" off \
		GRAPHVIZ "Use GraphViz" off \
		EXPORT_IMPORT "Import/export bugs (via XML)" off \
		CONTRIB	"Install user-contributed scripts" off \
		LDAP "LDAP Authentication" off \
		RADIUS "RADIUS Authentication" off

.include <bsd.port.options.mk>

.ifdef (WITH_MODPERL2)
USE_APACHE_RUN=	20+
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA
.endif

.ifdef WITH_MYSQL
RUN_DEPENDS+=	p5-DBD-mysql>=2.9003:${PORTSDIR}/databases/p5-DBD-mysql
USE_MYSQL=	yes
.endif

.ifdef WITH_PGSQL
RUN_DEPENDS+=	p5-DBD-Pg>=1.45:${PORTSDIR}/databases/p5-DBD-Pg
USE_PGSQL=	yes
.endif

.ifdef WITH_GRAPH_REPORTS
RUN_DEPENDS+=	p5-GD>=1.20:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Template-GD>=0:${PORTSDIR}/www/p5-Template-GD
.endif

.ifdef WITH_CHARTING_MODULES
RUN_DEPENDS+=	p5-Chart>=2.1:${PORTSDIR}/graphics/p5-Chart
.endif

.ifdef WITH_PATCH_VIEWER
RUN_DEPENDS+=	p5-PatchReader>=0.9.4:${PORTSDIR}/devel/p5-PatchReader \
		interdiff:${PORTSDIR}/misc/patchutils
.endif

.ifdef WITH_MORE_HTML
RUN_DEPENDS+=	p5-HTML-Parser>=3.40:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.ifdef WITH_INBOUND_EMAIL
RUN_DEPENDS+=	p5-Email-MIME-Attachment-Stripper>=0:${PORTSDIR}/mail/p5-Email-MIME-Attachment-Stripper \
		p5-Email-Reply>=0:${PORTSDIR}/mail/p5-Email-Reply
.endif

.ifdef WITH_MAIL_QUEUEING
RUN_DEPENDS+=	p5-TheSchwartz>=0:${PORTSDIR}/devel/p5-TheSchwartz \
		p5-Daemon-Generic>=0:${PORTSDIR}/net/p5-Daemon-Generic
.endif

.ifdef WITH_MOVE_BUGZ
RUN_DEPENDS+=	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig
.endif

.ifdef WITH_BMP2PNG
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_XMLRPC) || defined(WITH_JSONRPC)
RUN_DEPENDS+=	p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint
.endif

.ifdef WITH_XMLRPC
RUN_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.ifdef WITH_JSONRPC
RUN_DEPENDS+=	p5-JSON-RPC>=0:${PORTSDIR}/devel/p5-JSON-RPC
.endif

.ifdef WITH_MODPERL2
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI
.endif

.ifdef WITH_GRAPHVIZ
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.ifdef WITH_EXPORT_IMPORT
RUN_DEPENDS+=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig
.endif

.ifdef WITH_CONTRIB
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.ifdef WITH_LDAP
RUN_DEPENDS+=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
.endif

.ifdef WITH_RADIUS
RUN_DEPENDS+=	p5-Authen-Radius>=0:${PORTSDIR}/security/p5-Authen-Radius
.endif

post-patch:
	@${PERL} -pi -e 's/(default => ON_WINDOWS.+)apache/$$1www/' \
		${WRKSRC}/Bugzilla/Install/Localconfig.pm
.if defined(WITH_PGSQL) && !defined(WITH_MYSQL)
	@${PERL} -pi -e 's/(default =>.+|Default is )mysql/$$1Pg/' \
		${WRKSRC}/Bugzilla/Install/Localconfig.pm
.endif
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' \
		-e 's!/usr/lib/sendmail!/usr/sbin/sendmail!g; s=/usr/bin/perl=${PERL}=g' {} \+
	@${FIND} ${WRKSRC}/docs -type f | \
		${XARGS} ${REINPLACE_CMD} -i '' -e "s!/var/www/html/bugzilla!${WWWDIR}!"
	@${FIND} ${WRKSRC} \( -name "CVS" -or -name ".cvsignore" -or -name "*.orig" \
		-or -name "*.bak" -or -name ".bzr*" -or -name "README.docs" \) \
		| ${XARGS} ${RM} -rf

do-install:	.SILENT
	${MKDIR} ${WWWDIR}
	${FIND} ${WRKSRC} \! -type d -maxdepth 1 \! -name "UPGRADING*" -exec \
		${INSTALL_SCRIPT} {} ${WWWDIR} \;
	@${MKDIR} ${DATA_DIRS_LIST:S!^!${WWWDIR}/!}
.for D in ${DATA_DIRS_LIST}
	(cd ${WRKSRC}/${D} && ${COPYTREE_SHARE} . ${WWWDIR}/${D})
.endfor
	${TAR} -C ${WRKSRC} -cf - Bugzilla template | ${TAR} --unlink -C ${WWWDIR} -xf -
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}/)
.endif
# This are empty directories but they are needed,
# else ckecksetup.pl does not work as expected!
	${MKDIR} ${WWWDIR}/contrib ${WWWDIR}/lib ${WWWDIR}/t
.ifdef WITH_CONTRIB
	@cd ${WRKSRC}/contrib && \
		${FIND} . -type d -exec ${MKDIR} "${WWWDIR}/contrib/{}" \; && \
		${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${WWWDIR}/contrib/{}" \;
.endif
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
