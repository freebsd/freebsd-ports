# New ports collection makefile for:	otrs
# Date created:	   5 July 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	otrs
PORTVERSION=	2.4.4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.otrs.org/pub/otrs/ \
		ftp://ftp.samurai.com/pub/otrs/ \
		http://ftp.gwdg.de/pub/misc/otrs/ \
		http://mirror.xaranet.de/otrs/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Open Ticket Request System

BUILD_DEPENDS=	p5-CGI.pm>=3.33:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Date/Pcalc.pm:${PORTSDIR}/devel/p5-Date-Pcalc \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Tools>=5.427:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Text/CSV.pm:${PORTSDIR}/textproc/p5-Text-CSV \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	MYSQL "MySQL database support" on \
		PGSQL "PostgreSQL database support" off \
		REPORTS_MODULES "Reports support" on \
		SMTP "Send email via SMTP" on \
		POP3 "Fetch email via POP3" on \
		IMAP "Fetch email via IMAP" on \
		LDAP "Enable LDAP support" off \
		PDF "Enable PDF output" on \
		ISPELL "Enable spell checking" on \
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
DOCS_DIRS_LIST=	"" manual/en/pdf
DOCS_FILES_LIST=	C* INSTALL RE* TODO UPGRADING

SCRIPTS_DIRS_LIST=	"" database/update test tools
CLEAN_FILES=	scripts/apache2-httpd.include.conf scripts/suse* scripts/redhat* \
		var/httpd/htdocs/yui

USE_APACHE=	1.3+
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

.ifdef WITH_REPORTS_MODULES
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text/Align.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
.endif

.ifdef WITH_SMTP
RUN_DEPENDS+=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL
.endif

.ifdef WITH_POP3
RUN_DEPENDS+=	${SITE_PERL}/Net/POP3.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/POP3Client.pm:${PORTSDIR}/mail/p5-Mail-POP3Client
.endif

.ifdef WITH_IMAP
RUN_DEPENDS+=	${SITE_PERL}/Net/IMAP/Simple.pm:${PORTSDIR}/mail/p5-Net-IMAP-Simple
.endif

.ifdef WITH_LDAP
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.ifdef WITH_PDF
RUN_DEPENDS+=	p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2 \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.ifdef WITH_ISPELL
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.ifdef WITH_GNUPG
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
.endif

do-build:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${FIND} ${WRKSRC}/Kernel -type d | ${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/Kernel -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${RM} -rf ${WRKSRC}/Kernel/cpan-lib/ \
		${CLEAN_FILES:S!^!${WRKSRC}/!}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/opt/=${PREFIX}/=g;s=wwwrun=${WWWOWN}=g;"
.ifdef WITH_ISPELL
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/ispell=g"
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
