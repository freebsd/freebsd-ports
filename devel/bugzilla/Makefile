# New ports collection makefile for:	bugzilla
# Date created:				28 September 2001
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	4.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	webtools webtools/archived

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Bug-tracking system developed by Mozilla Project

LICENSE=	MPL

RUN_DEPENDS=	\
		p5-CGI.pm>=3.51:${PORTSDIR}/www/p5-CGI.pm \
		p5-DBI>=1.41:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime-TimeZone>=0.71:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-MIME>=1.904:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Send>=2.00:${PORTSDIR}/mail/p5-Email-Send \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Math-Random-Secure>=0.05:${PORTSDIR}/math/p5-Math-Random-Secure \
		p5-Template-Toolkit>=2.22:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TimeDate>=1.19:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USE_PERL5=	yes

BINMODE=	700

SUB_FILES=	pkg-message

DATA_DIRS_LIST=	images js skins

# checksetup will fail if these directories are not present!
EMPTY_DIRS_LIST=data graphs contrib lib t xt

.include "${.CURDIR}/Makefile.common"
.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL}
USE_APACHE_RUN=	20+
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=2.9003:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=1.45:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MGRAPH_REPORTS}
RUN_DEPENDS+=	p5-GD>=1.20:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Template-GD>=0:${PORTSDIR}/www/p5-Template-GD
.endif

.if ${PORT_OPTIONS:MCHARTING_MODULES}
RUN_DEPENDS+=	p5-Chart>=2.1:${PORTSDIR}/graphics/p5-Chart
.endif

.if ${PORT_OPTIONS:MPATCH_VIEWER}
RUN_DEPENDS+=	p5-PatchReader>=0.9.4:${PORTSDIR}/devel/p5-PatchReader \
		interdiff:${PORTSDIR}/misc/patchutils
.endif

.if ${PORT_OPTIONS:MMORE_HTML}
RUN_DEPENDS+=	p5-HTML-Parser>=3.40:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if ${PORT_OPTIONS:MINBOUND_EMAIL}
RUN_DEPENDS+=	p5-Email-MIME-Attachment-Stripper>=0:${PORTSDIR}/mail/p5-Email-MIME-Attachment-Stripper \
		p5-Email-Reply>=0:${PORTSDIR}/mail/p5-Email-Reply
.endif

.if ${PORT_OPTIONS:MMAIL_QUEUEING}
RUN_DEPENDS+=	p5-TheSchwartz>=0:${PORTSDIR}/devel/p5-TheSchwartz \
		p5-Daemon-Generic>=0:${PORTSDIR}/net/p5-Daemon-Generic
.endif

.if ${PORT_OPTIONS:MMOVE_BUGZ}
RUN_DEPENDS+=	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig
.endif

.if ${PORT_OPTIONS:MBMP2PNG}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if ${PORT_OPTIONS:MXMLRPC} || ${PORT_OPTIONS:MJSONRPC}
RUN_DEPENDS+=	p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint
.endif

.if ${PORT_OPTIONS:MXMLRPC}
RUN_DEPENDS+=	p5-SOAP-Lite>=0.712:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if ${PORT_OPTIONS:MJSONRPC}
RUN_DEPENDS+=	p5-JSON-RPC>=0:${PORTSDIR}/devel/p5-JSON-RPC \
		p5-JSON-XS>=2.0:${PORTSDIR}/converters/p5-JSON-XS
.endif

.if ${PORT_OPTIONS:MMODPERL}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI
.endif

.if ${PORT_OPTIONS:MWITH_GRAPHVIZ}
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if ${PORT_OPTIONS:MEXPORT_IMPORT}
RUN_DEPENDS+=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig
.endif

.if ${PORT_OPTIONS:MCONTRIB}
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MRADIUS}
RUN_DEPENDS+=	p5-Authen-Radius>=0:${PORTSDIR}/security/p5-Authen-Radius
.endif

post-patch:
	@${PERL} -pi -e 's/(default => ON_WINDOWS.+)apache/$$1www/' \
		${WRKSRC}/Bugzilla/Install/Localconfig.pm

.if ${PORT_OPTIONS:MPGSQL} && empty(PORT_OPTIONS:MMYSQL)
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
	@${MKDIR} ${EMPTY_DIRS_LIST:S!^!${WWWDIR}/!}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}/)
.endif

.if ${PORT_OPTIONS:MCONTRIB}
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
