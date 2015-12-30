# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	MOZILLA/webtools MOZILLA/webtools/archived

MAINTAINER=	bz-ports@FreeBSD.org
COMMENT=	Bug-tracking system developed by Mozilla Project

LICENSE=	MPL

# see Bugzilla/Install/Requirements.pm
RUN_DEPENDS=	\
		p5-CGI>=3.51:${PORTSDIR}/www/p5-CGI \
		p5-DBI>=1.614:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime-TimeZone>=1.64:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime>=0.75:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-MIME>=1.904:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Sender>=1.300011:${PORTSDIR}/mail/p5-Email-Sender \
		p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
		p5-File-Slurp>=9999.13:${PORTSDIR}/devel/p5-File-Slurp \
		p5-JSON-XS>=2.01:${PORTSDIR}/converters/p5-JSON-XS \
		p5-List-MoreUtils>=0.32:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Math-Random-ISAAC>=1.001:${PORTSDIR}/math/p5-Math-Random-ISAAC \
		p5-Template-Toolkit>=2.24:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TimeDate>=2.23:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>=1.55:${PORTSDIR}/net/p5-URI

USES=		cpe perl5
USE_PERL5=	run

CPE_VENDOR=	mozilla

SUB_FILES=	pkg-message

DATA_DIRS_LIST=	images js skins

# checksetup will fail if these directories are not present!
EMPTY_DIRS_LIST=data graphs contrib lib t xt

.include "${.CURDIR}/Makefile.common"
.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} >= 501800
# PR 194782: silence Module::Pluggable deprecated warnings
RUN_DEPENDS+=	p5-Module-Pluggable>=5.1:${PORTSDIR}/devel/p5-Module-Pluggable
# PR 196060,196100: explicitly depend on textproc/p5-Text-Tabv
RUN_DEPENDS+=	p5-Text-Tabs+Wrap>=2013.0523:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
.endif

.if ${PORT_OPTIONS:MMODPERL}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=4.0001:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql:91+
RUN_DEPENDS+=	p5-DBD-Pg>=3.4.2:${PORTSDIR}/databases/p5-DBD-Pg
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
RUN_DEPENDS+=	p5-Chart>=2.4.10:${PORTSDIR}/graphics/p5-Chart
.endif

.if ${PORT_OPTIONS:MPATCH_VIEWER}
RUN_DEPENDS+=	p5-PatchReader>=0.9.6:${PORTSDIR}/devel/p5-PatchReader \
		interdiff:${PORTSDIR}/misc/patchutils
.endif

.if ${PORT_OPTIONS:MMORE_HTML}
RUN_DEPENDS+=	p5-HTML-Parser>=3.67:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if ${PORT_OPTIONS:MINBOUND_EMAIL}
RUN_DEPENDS+=	p5-Email-MIME-Attachment-Stripper>=0:${PORTSDIR}/mail/p5-Email-MIME-Attachment-Stripper \
		p5-Email-Reply>=0:${PORTSDIR}/mail/p5-Email-Reply \
		p5-HTML-FormatText-WithLinks>=0.13:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks
.endif

.if ${PORT_OPTIONS:MMAIL_QUEUEING}
RUN_DEPENDS+=	p5-TheSchwartz>=1.10:${PORTSDIR}/devel/p5-TheSchwartz \
		p5-Daemon-Generic>=0:${PORTSDIR}/net/p5-Daemon-Generic
.endif

.if ${PORT_OPTIONS:MMOVE_BUGZ}
RUN_DEPENDS+=	p5-MIME-Tools>=5.406:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig
.endif

.if ${PORT_OPTIONS:MBMP2PNG}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

# Note: XML-RPC and JSON-RPC are deprecated in favor of REST
# and will likely be removed in the Bugzilla 7.0 release.
.if ${PORT_OPTIONS:MXMLRPC} || ${PORT_OPTIONS:MJSONRPC} || ${PORT_OPTIONS:MREST}
RUN_DEPENDS+=	p5-Test-Taint>=1.06:${PORTSDIR}/devel/p5-Test-Taint
.endif

.if ${PORT_OPTIONS:MXMLRPC}
RUN_DEPENDS+=	p5-XMLRPC-Lite>=0.712:${PORTSDIR}/net/p5-XMLRPC-Lite
# XXX SOAP::Lite can be removed if upstream officially depends on
# XMLRPC::Lite>=0.717, see Bugzilla/Install/Requirements.pm
RUN_DEPENDS+=	p5-SOAP-Lite>=0.712:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if ${PORT_OPTIONS:MJSONRPC} || ${PORT_OPTIONS:MREST}
RUN_DEPENDS+=	p5-JSON-RPC>=0:${PORTSDIR}/devel/p5-JSON-RPC
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

.if ${PORT_OPTIONS:MMEMCACHED}
RUN_DEPENDS+=	p5-Cache-Memcached>=1.30:${PORTSDIR}/databases/p5-Cache-Memcached
.endif

post-extract:
# The docs_urlbase parameter has been removed. If documentation has not been
# compiled locally, the "Help" links and other documentation links will
# redirect to bugzilla.readthedocs.org automatically.
	${RM} -r ${WRKSRC}/docs
	${RM} -r ${WRKSRC}/.git
	${RM} ${WRKSRC}/.bzrignore ${WRKSRC}/.gitignore ${WRKSRC}/.gitrev \
		${WRKSRC}/.travis.yml ${WRKSRC}/Build.PL ${WRKSRC}/MANIFEST.SKIP

post-patch:
	${REINPLACE_CMD} -e 's/apache/www/' ${WRKSRC}/Bugzilla/Install/Localconfig.pm
	${REINPLACE_CMD} -e 's|/opt/bugzilla|${WWWDIR}|' ${WRKSRC}/importxml.pl
	${FIND} ${WRKSRC} -type f \( -name \*.cgi -o -name \*.pl -o -name \*.pm -o -name \*.t \) \
		-exec ${SED} -i '' -e "s=/usr/bin/perl=${PERL}=g; \
			s!/usr/lib/sendmail!/usr/sbin/sendmail!g;" {} \+

.if ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} -e "s/'mysql'/'Pg'/" ${WRKSRC}/Bugzilla/Install/Localconfig.pm
.endif

pre-install:
	${FIND} ${WRKSRC} -type f \( -name "*.orig" -or -name "*.bak" \) -delete

do-install:	.SILENT
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${FIND} ${WRKSRC} \! -type d -maxdepth 1 \! -name "UPGRADING*" -exec \
		${INSTALL_SCRIPT} {} ${STAGEDIR}${WWWDIR} \;
	@${MKDIR} ${DATA_DIRS_LIST:S!^!${STAGEDIR}${WWWDIR}/!}
.for D in ${DATA_DIRS_LIST}
	(cd ${WRKSRC}/${D} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${D})
.endfor
	${TAR} -C ${WRKSRC} -cf - Bugzilla template | ${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -
	@${MKDIR} ${EMPTY_DIRS_LIST:S!^!${STAGEDIR}${WWWDIR}/!}

do-install-CONTRIB-on:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/contrib
	(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/contrib)

.include <bsd.port.post.mk>
