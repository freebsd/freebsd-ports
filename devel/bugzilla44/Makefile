# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.5
CATEGORIES=	devel
MASTER_SITES=	BUGZILLA
MASTER_SITE_SUBDIR=	webtools webtools/archived

MAINTAINER=	bz-ports@FreeBSD.org
COMMENT=	Bug-tracking system developed by Mozilla Project

LICENSE=	MPL

RUN_DEPENDS=	\
		p5-CGI.pm>=3.51:${PORTSDIR}/www/p5-CGI.pm \
		p5-DBI>=1.54:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime-TimeZone>=0.71:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-MIME>=1.904:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Send>=2.04:${PORTSDIR}/mail/p5-Email-Send \
		p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Math-Random-ISAAC>=1.001:${PORTSDIR}/math/p5-Math-Random-ISAAC \
		p5-Template-Toolkit>=2.22:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TimeDate>=1.19:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	patch build run

SUB_FILES=	pkg-message

DATA_DIRS_LIST=	images js skins

# checksetup will fail if these directories are not present!
EMPTY_DIRS_LIST=data graphs contrib lib t xt

.include "${.CURDIR}/Makefile.common"
.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=4.0001:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=2.19.3:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
RUN_DEPENDS+=	p5-DBD-SQLite>=1.29:${PORTSDIR}/databases/p5-DBD-SQLite \
		sqlite3>=3:${PORTSDIR}/databases/sqlite3
.endif

.if ${PORT_OPTIONS:MGRAPH_REPORTS}
RUN_DEPENDS+=	p5-GD>=1.20:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Template-GD>=0:${PORTSDIR}/www/p5-Template-GD
.endif

.if ${PORT_OPTIONS:MCHARTING_MODULES}
RUN_DEPENDS+=	p5-Chart>=2.1.0:${PORTSDIR}/graphics/p5-Chart
.endif

.if ${PORT_OPTIONS:MPATCH_VIEWER}
RUN_DEPENDS+=	p5-PatchReader>=0.9.6:${PORTSDIR}/devel/p5-PatchReader \
		interdiff:${PORTSDIR}/misc/patchutils
.endif

.if ${PORT_OPTIONS:MMORE_HTML}
RUN_DEPENDS+=	p5-HTML-Parser>=3.40:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if ${PORT_OPTIONS:MINBOUND_EMAIL}
RUN_DEPENDS+=	p5-Email-MIME-Attachment-Stripper>=0:${PORTSDIR}/mail/p5-Email-MIME-Attachment-Stripper \
		p5-Email-Reply>=0:${PORTSDIR}/mail/p5-Email-Reply \
		p5-HTML-FormatText-WithLinks>=0.13:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks
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

.if ${PORT_OPTIONS:MGRAPHVIZ}
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

.if ${PORT_OPTIONS:MSMTP_AUTH}
RUN_DEPENDS+=	p5-Authen-SASL>=2.16:${PORTSDIR}/security/p5-Authen-SASL
.endif

.if ${PORT_OPTIONS:MSMTP_SSL}
RUN_DEPENDS+=	p5-Net-SMTP-SSL>=1.01:${PORTSDIR}/mail/p5-Net-SMTP-SSL
.endif

.if ${PORT_OPTIONS:MMIME_SNIFF}
RUN_DEPENDS+=	p5-File-MimeInfo>=0.16:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy
.endif

.if ${PORT_OPTIONS:MFREEBSD}
EXTRA_PATCHES=	${FILESDIR}/freebsd-project-ldap.diff
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/.bzr
	@${RM} -f ${WRKSRC}/.bzrignore ${WRKSRC}/.gitignore ${WRKSRC}/.gitrev \
		${WRKSRC}/docs/en/README.docs ${WRKSRC}/docs/en/html/Bugzilla-Guide.proc \
		${WRKSRC}/.travis.yml ${WRKSRC}/Build.PL ${WRKSRC}/MANIFEST.SKIP

post-patch:
	@${PERL} -pi -e 's/(default => ON_WINDOWS.+)apache/$$1www/' \
		${WRKSRC}/Bugzilla/Install/Localconfig.pm

.if ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MMYSQL}
	@${PERL} -pi -e 's/(default =>.+|Default is )mysql/$$1Pg/' \
		${WRKSRC}/Bugzilla/Install/Localconfig.pm
.endif
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' \
		-e 's!/usr/lib/sendmail!/usr/sbin/sendmail!g; s=/usr/bin/perl=${PERL}=g' {} \+
	@${FIND} ${WRKSRC}/docs -type f | \
		${XARGS} ${REINPLACE_CMD} -i '' -e "s!/var/www/html/bugzilla!${WWWDIR}!"

pre-install:
	${FIND} ${WRKSRC} -type f \( -name "*.orig" -or -name "*.bak" \) -delete

do-install:	.SILENT
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${FIND} ${WRKSRC} \! -type d -maxdepth 1 \! -name "UPGRADING*" -exec \
		${INSTALL_SCRIPT} {} ${STAGEDIR}${WWWDIR} \;
	@${MKDIR} ${DATA_DIRS_LIST:S!^!${STAGEDIR}${WWWDIR}/!}
.for D in ${DATA_DIRS_LIST}
	(cd ${WRKSRC}/${D} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${D})
.endfor
	${TAR} -C ${WRKSRC} -cf - Bugzilla template | ${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -
	@${MKDIR} ${EMPTY_DIRS_LIST:S!^!${STAGEDIR}${WWWDIR}/!}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.if ${PORT_OPTIONS:MCONTRIB}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/contrib
	(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/contrib)
.endif

.include <bsd.port.mk>
