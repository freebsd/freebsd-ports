# Ports collection makefile for:	slimserver
# Date created:				Wed Apr 14, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	slimserver
PORTVERSION?=	5.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.slimdevices.com/downloads/${NIGHTLY}SlimServer_v${DISTVERSION}/
DISTNAME=	SlimServer_v${DISTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

DISTVERSION?=	${PORTVERSION}

RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder \
		${SITE_PERL}/Audio/Wav.pm:${PORTSDIR}/audio/p5-Audio-Wav \
		${SITE_PERL}/Audio/WMA.pm:${PORTSDIR}/audio/p5-Audio-WMA \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page \
		${SITE_PERL}/DBIx/ContextualFetch.pm:${PORTSDIR}/databases/p5-DBIx-ContextualFetch \
		${SITE_PERL}/Ima/DBI.pm:${PORTSDIR}/databases/p5-Ima-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/UNIVERSAL/moniker.pm:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which \
		${SITE_PERL}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	${LOCALBASE}/bin/pgrep:${PORTSDIR}/sysutils/pkill
PGREPBASE=	${LOCALBASE}
.else
PGREPBASE=	/usr
.endif

USE_RC_SUBR=	yes
TMP_SLIMDIR=	${WRKDIR}/slimserver
TMP_DOCSDIR=	${WRKDIR}/doc
DOCFILES=	Changelog.html Installation.txt
EXCEPTFILES=	${DOCFILES} \
		CPAN/Audio/WMA.pm
EXCEPTDIRS=	Bin \
		CPAN/arch \
		CPAN/Audio/Wav \
		CPAN/Bundle \
		CPAN/Class \
		CPAN/Data \
		CPAN/DBIx \
		CPAN/File \
		CPAN/HTML \
		CPAN/HTTP \
		CPAN/Ima \
		CPAN/IO \
		CPAN/LWP \
		CPAN/MIME \
		CPAN/MP3 \
		CPAN/Net \
		CPAN/SQL \
		CPAN/Template \
		CPAN/Universal \
		CPAN/URI \
		CPAN/XML

CPIOARGS=	--quiet -pdum -R
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	SLIMDIR=${SLIMDIR}

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%PGREPBASE%%,${PGREPBASE},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%SLIMDIR%%,${SLIMDIR},g'

pre-fetch:
.if !defined(SLIMDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define SLIMDIR to override default of 'slimserver'."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${SED} ${SED_SCRIPT} <${FILESDIR}/slimserver.sh >${WRKDIR}/slimserver.sh

SLIMDIR?=	slimserver

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-build:
	@${MKDIR} -m 0755 ${TMP_SLIMDIR}
	@cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S/^/-o -name /} \
	    ${EXCEPTDIRS:S/$/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${TMP_SLIMDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TMP_DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${TMP_DOCSDIR}
.endif
	@${ECHO} "etc/rc.d/slimserver${PKGNAMESUFFIX}.sh" > ${PLIST}
.if !defined(NOPORTDOCS)
	@${FIND} ${TMP_DOCSDIR} -type f | \
	    ${SED} -e 's|${TMP_DOCSDIR}|%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
.endif
	@${FIND} ${TMP_SLIMDIR}/* -type f | \
	    ${SED} -e 's|${TMP_SLIMDIR}|%%SLIMDIR%%|' | \
	    ${SORT} >> ${PLIST}
	@${ECHO} "${SLIMDIR}/Cache" >> ${PLIST}
	@${FIND} ${TMP_SLIMDIR} -type d | \
	    ${SED} -e 's|${TMP_SLIMDIR}|@dirrm %%SLIMDIR%%|' | \
	    ${SORT} -r >> ${PLIST}
.if !defined(NOPORTDOCS)
	@${FIND} ${TMP_DOCSDIR} -type d | \
	    ${SED} -e 's|${TMP_DOCSDIR}|@dirrm %%DOCSDIR%%|' | \
	    ${SORT} -r >> ${PLIST}
.endif
	@${ECHO} '@unexec rmdir /var/db/slimserver 2>/dev/null || (echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove /var/db/slimserver and its contents manually.")' >> ${PLIST}

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${SLIMDIR}
	@${LN} -s /var/db/slimserver/cache ${PREFIX}/${SLIMDIR}/Cache
	@cd ${TMP_SLIMDIR} && \
	    ${FIND} . | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/slimserver.sh \
	    ${PREFIX}/etc/rc.d/slimserver${PKGNAMESUFFIX}.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${TMP_DOCSDIR} && \
	    ${FIND} . | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
