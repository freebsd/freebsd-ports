# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	otrs
PORTVERSION=	3.2.11
CATEGORIES=	devel
MASTER_SITES=	http://ftp.otrs.org/pub/otrs/ \
		ftp://ftp.samurai.com/pub/otrs/ \
		http://ftp.gwdg.de/pub/misc/otrs/ \
		http://mirror.xaranet.de/otrs/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Open Ticket Request System

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Date-Pcalc>=0:${PORTSDIR}/devel/p5-Date-Pcalc \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Tools>=5.427:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Net-DNS>=0.66:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-CSS-Minifier-XS>=0:${PORTSDIR}/textproc/p5-CSS-Minifier-XS \
		p5-JavaScript-Minifier-XS>=0:${PORTSDIR}/textproc/p5-JavaScript-Minifier-XS \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-XML-FeedPP>=0:${PORTSDIR}/textproc/p5-XML-FeedPP \
		p5-IO-Interactive>=0:${PORTSDIR}/devel/p5-IO-Interactive \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		shebangfix
SHEBANG_FILES=	bin/cgi-bin/*.pl bin/fcgi-bin/*.pl bin/*.pl \
		scripts/auto_build/*.pl scripts/tools/*.pl scripts/*.pl

OPTIONS_DEFINE=		MYSQL PGSQL REPORTS_MODULES SMTP POP3 IMAP LDAP PDF \
			GNUPG DOCS
OPTIONS_DEFAULT=	MYSQL REPORTS_MODULES SMTP POP3 IMAP PDF ASPELL
OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL ISPELL

IMAP_DESC=		Fetch email via IMAP
POP3_DESC=		Fetch email via POP3
SMTP_DESC=		Send email via SMTP
REPORTS_MODULES_DESC=	Reports support

USE_BZIP2=	yes

OTRSDIR=	${PREFIX}/otrs
USERS=		${PORTNAME}
GROUPS=		${USERS}

SUB_FILES=	pkg-install pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ROOT_DIRS_LIST=	Kernel bin scripts
BIN_DIRS_LIST=	"" cgi-bin fcgi-bin
PM_DIRS_LIST=	Kernel Kernel/Config Kernel/Config/Files Kernel/Language \
		Modules Kernel/Output/HTML Kernel/Output/HTML/Lite \
		Kernel/Output/HTML/Standard System System/Auth System/AuthSession \
		System/Crypt System/CustomerAuth System/CustomerUser \
		System/CustomerUser/ System/
DOCS_DIRS_LIST=	"" manual/en
DOCS_FILES_LIST=	C[A-Z]* INSTALL.md RE* UPGRADING.md

SCRIPTS_DIRS_LIST=	"" database/update test tools
CLEAN_FILES=	scripts/suse* scripts/redhat* \
		var/httpd/htdocs/js/thirdparty/ckeditor-4.0/_source \
		var/httpd/htdocs/skins/Agent/*/img/source

USES=		perl5
USE_APACHE_RUN=	22+

PLIST_SUB+=	VER_CKEDITOR="4.0"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
USE_PGSQL=	yes
.endif

RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=2.0.5:${PORTSDIR}/www/mod_perl2

.if ${PORT_OPTIONS:MREPORTS_MODULES}
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil
.endif

.if ${PORT_OPTIONS:MSMTP}
RUN_DEPENDS+=	p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL \
		p5-Net-SMTP-TLS>=0:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
.endif

.if ${PORT_OPTIONS:MPOP3}
RUN_DEPENDS+=	p5-Mail-POP3Client>=0:${PORTSDIR}/mail/p5-Mail-POP3Client \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MIMAP}
RUN_DEPENDS+=	p5-Net-IMAP-Simple-SSL>=0:${PORTSDIR}/mail/p5-Net-IMAP-Simple-SSL
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MPDF}
RUN_DEPENDS+=	p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2
. if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
. endif
.endif

.if ${PORT_OPTIONS:MISPELL}
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.if ${PORT_OPTIONS:MASPELL}
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.if ${PORT_OPTIONS:MGNUPG}
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | \
		${XARGS} ${REINPLACE_CMD} -i '' \
      			-e 's|Digest::SHA::PurePerl|Digest::SHA|g'
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${RM} -rf ${WRKSRC}/Kernel/cpan-lib/ \
		${CLEAN_FILES:S!^!${WRKSRC}/!}
	#shebang file only gets the first instance of /usr/bin/perl
	@${REINPLACE_CMD} -i '' -e "s|/usr/bin/perl|${LOCALBASE}/bin/perl|g" \
		${WRKSRC}/bin/otrs.CreateApacheStartupFile.pl

do-build:
	@${FIND} ${WRKSRC}/Kernel -type d | ${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/Kernel -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/opt/=${PREFIX}/=g;s=wwwrun=${WWWOWN}=g;"
.if ${PORT_OPTIONS:MISPELL}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/ispell=g"
.endif
.if ${PORT_OPTIONS:MASPELL}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/aspell=g"
.endif
.if ${PORT_OPTIONS:MGNUPG}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/gpg=${PREFIX}/bin/gpg=g"
.endif

do-install:
	@${MKDIR} ${ROOT_DIRS_LIST:S!^!${OTRSDIR}/!} ${BIN_DIRS_LIST:S!^!${OTRSDIR}/bin/!} \
		${SCRIPTS_DIRS_LIST:S!^!${OTRSDIR}/scripts/!}
	@${INSTALL_DATA} ${WRKSRC}/.*.dist ${OTRSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/RELEASE ${OTRSDIR}/
.for D in ${BIN_DIRS_LIST}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${D}/*.* ${OTRSDIR}/bin/${D}/
.endfor
	@(cd ${WRKSRC} && ${PAX} -r -w Kernel var ${OTRSDIR})
.if !exists(${OTRSDIR}/Kernel/Config.pm)
	@${CP} ${OTRSDIR}/Kernel/Config.pm.dist ${OTRSDIR}/Kernel/Config.pm
.endif
.if !exists(${OTRSDIR}/Kernel/Config/GenericAgent.pm)
	@${CP} ${OTRSDIR}/Kernel/Config/GenericAgent.pm.dist ${OTRSDIR}/Kernel/Config/GenericAgent.pm
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${OTRSDIR}/Kernel
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][lh] ${OTRSDIR}/scripts/
	@${INSTALL_DATA} ${WRKSRC}/scripts/apache* \
		${WRKSRC}/scripts/*.sql ${OTRSDIR}/scripts/
	@${INSTALL_DATA} ${WRKSRC}/scripts/database/update/*.* ${OTRSDIR}/scripts/database/update/
	@${INSTALL_DATA} ${WRKSRC}/scripts/database/*.* ${OTRSDIR}/scripts/database/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/test/*.t ${OTRSDIR}/scripts/test/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/tools/*.pl ${OTRSDIR}/scripts/tools/
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCS_DIRS_LIST:S!^!${DOCSDIR}/!}
	@${INSTALL_DATA} ${DOCS_FILES_LIST:S!^!${WRKSRC}/!} ${DOCSDIR}/
.for D in ${DOCS_DIRS_LIST}
	@${INSTALL_DATA} ${WRKSRC}/doc/${D}/*.* ${DOCSDIR}/${D}/
.endfor
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E '\
		s=share/doc/${PORTNAME}=%%DOCSDIR%%=; \
	')> temp-pkg-plist

.include <bsd.port.post.mk>
