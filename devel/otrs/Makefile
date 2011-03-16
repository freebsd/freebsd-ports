# New ports collection makefile for:	otrs
# Date created:	   5 July 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	otrs
PORTVERSION=	3.0.6
CATEGORIES=	devel
MASTER_SITES=	http://ftp.otrs.org/pub/otrs/ \
		ftp://ftp.samurai.com/pub/otrs/ \
		http://ftp.gwdg.de/pub/misc/otrs/ \
		http://mirror.xaranet.de/otrs/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Open Ticket Request System

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Pcalc.pm:${PORTSDIR}/devel/p5-Date-Pcalc \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Tools>=5.427:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Net-DNS>=0.66:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Text/CSV.pm:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-CSS-Minifier-XS>=0:${PORTSDIR}/textproc/p5-CSS-Minifier-XS \
		p5-JavaScript-Minifier-XS>=0:${PORTSDIR}/textproc/p5-JavaScript-Minifier-XS \
		p5-Apache-Reload>=0:${PORTSDIR}/www/p5-Apache-Reload \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/XML/FeedPP.pm:${PORTSDIR}/textproc/p5-XML-FeedPP
RUN_DEPENDS=	${BUILD_DEPENDS}

BROKEN=		conflicting dependencies

OPTIONS=	MYSQL "MySQL database support" on \
		PGSQL "PostgreSQL database support" off \
		MODPERL2 "ModPerl2 support" on \
		REPORTS_MODULES "Reports support" on \
		SMTP "Send email via SMTP" on \
		POP3 "Fetch email via POP3" on \
		IMAP "Fetch email via IMAP" on \
		LDAP "Enable LDAP support" off \
		PDF "Enable PDF output" on \
		ISPELL "Enable ispell checking" off \
		ASPELL "Enable aspell checking" on \
		GNUPG "Use GnuPG" off

USE_BZIP2=	yes

OTRSDIR=	${PREFIX}/otrs

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
DOCS_FILES_LIST=	C[A-Z]* INSTALL RE* TODO UPGRADING

SCRIPTS_DIRS_LIST=	"" database/update test tools
CLEAN_FILES=	scripts/suse* scripts/redhat* \
		var/httpd/htdocs/js/thirdparty/ckeditor-3.4.2/_source \
		var/httpd/htdocs/skins/Agent/*/img/source

USE_PERL5=	yes

.include <bsd.port.pre.mk>

.ifdef WITH_MYSQL
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
USE_MYSQL=	yes
.endif

.ifdef WITH_PGSQL
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
USE_PGSQL=	yes
.endif

.ifdef WITH_MODPERL2
USE_APACHE=	2.2+
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=2.0.0:${PORTSDIR}/www/mod_perl2
.else
USE_APACHE=	1.3+
.endif

.ifdef WITH_REPORTS_MODULES
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text/Align.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
.endif

.ifdef WITH_SMTP
RUN_DEPENDS+=	p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL \
		p5-Net-SMTP-TLS>=0:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL
.endif

.ifdef WITH_POP3
RUN_DEPENDS+=	${SITE_PERL}/Mail/POP3Client.pm:${PORTSDIR}/mail/p5-Mail-POP3Client \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.ifdef WITH_IMAP
RUN_DEPENDS+=	p5-Net-IMAP-Simple-SSL>=0:${PORTSDIR}/mail/p5-Net-IMAP-Simple-SSL
.endif

.ifdef WITH_LDAP
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.ifdef WITH_PDF
RUN_DEPENDS+=	p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2
. if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
. endif
.endif

.ifdef WITH_ISPELL
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.ifdef WITH_ASPELL
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.ifdef WITH_GNUPG
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
.endif

.ifdef WITH_ISPELL && WITH_ASPELL
IGNORE=	you only need 1 spell checker
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${RM} -rf ${WRKSRC}/Kernel/cpan-lib/ \
		${CLEAN_FILES:S!^!${WRKSRC}/!}

do-build:
	@${FIND} ${WRKSRC}/Kernel -type d | ${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/Kernel -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/opt/=${PREFIX}/=g;s=wwwrun=${WWWOWN}=g;"
.ifdef WITH_ISPELL
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/ispell=g"
.endif
.ifdef WITH_ASPELL
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/aspell=g"
.endif
.ifdef WITH_GNUPG
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/gpg=${PREFIX}/bin/gpg=g"
.endif

do-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
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
	@${INSTALL_DATA} ${WRKSRC}/scripts/*.p[hm]* ${WRKSRC}/scripts/apache* \
		${WRKSRC}/scripts/*.sql ${OTRSDIR}/scripts/
	@${INSTALL_DATA} ${WRKSRC}/scripts/database/update/*.* ${OTRSDIR}/scripts/database/update/
	@${INSTALL_DATA} ${WRKSRC}/scripts/database/*.* ${OTRSDIR}/scripts/database/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/test/*.t ${OTRSDIR}/scripts/test/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/tools/*.pl ${OTRSDIR}/scripts/tools/
.ifndef NOPORTDOCS
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
