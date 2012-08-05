# Ports collection makefile for:		squeezeboxserver
# Date created:					Wed Apr 14, 2004
# Whom:						Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	squeezeboxserver
PORTVERSION=	7.5.4
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://downloads.slimdevices.com/SqueezeboxServer_v${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-noCPAN
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS_DEFINE=	APE FAAD FLAC LAME SHORTEN SOX DOCS
OPTIONS_DEFAULT=	APE FAAD FLAX SOX
SHORTEN_DESC=	Support Shorten input
SOX_DESC=	Support OGG Vorbis input via SoX (SliMP3 and SB1)

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-32171-noCPAN

RUN_DEPENDS+=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-EV>=0:${PORTSDIR}/devel/p5-EV \
		p5-Audio-Scan>=0.87:${PORTSDIR}/audio/p5-Audio-Scan \
		p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor

# Work around a bug in p5-Package-Stash port
RUN_DEPENDS+=	p5-Package-DeprecationManager>=0.10:${PORTSDIR}/devel/p5-Package-DeprecationManager

USERS=		${SLIMUSER}
GROUPS=		${SLIMGROUP}
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

USE_MYSQL=	server

.if ${PORT_OPTIONS:MAPE}
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif
.if ${PORT_OPTIONS:MFAAD}
RUN_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif
.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if ${PORT_OPTIONS:MSHORTEN}
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
.endif
.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

USE_RC_SUBR=	squeezeboxserver
TMP_SLIMDIR=	${WRKDIR}/_squeezeboxserver
TMP_DOCSDIR=	${WRKDIR}/doc
DOCFILES=	Changelog.html Installation.txt License.txt
CONFFILES=	convert.conf types.conf
EXCEPTFILES=	${DOCFILES} \
		${CONFFILES} \
		CPAN/Carp/Clan.pm \
		CPAN/Class/Accessor.pm \
		CPAN/Class/Accessor/Chained.pm \
		CPAN/Class/C3.pm \
		CPAN/Class/Inspector.pm \
		CPAN/Class/XSAccessor.pm \
		CPAN/Data/Page.pm \
		CPAN/DBI.pm \
		CPAN/EV.pm \
		CPAN/File/Temp.pm \
		CPAN/File/Which.pm \
		CPAN/GD.pm \
		CPAN/HTML/Parser.pm \
		CPAN/JSON/XS/Boolean.pm \
		CPAN/JSON/XS.pm \
		CPAN/Template.pm \
		CPAN/Test/Simple.pm \
		CPAN/URI.pm \
		CPAN/XML/Parser.pm \
		MySQL/errmsg.txt \
		MySQL/errmsg.sys

EXCEPTDIRS=	Bin \
		CPAN/arch \
		CPAN/Algorith \
		CPAN/Audio \
		CPAN/Compress \
		CPAN/Class/Accessor/Chained \
		CPAN/Class/C3 \
		CPAN/Class/Inspector \
		CPAN/Class/XSAccessor \
		CPAN/DBD \
		CPAN/DBI \
		CPAN/DBIx \
		CPAN/Digest \
		CPAN/Encode \
		CPAN/GD \
		CPAN/Module \
		CPAN/MRO \
		CPAN/Path \
		CPAN/Scope \
		CPAN/Sub \
		CPAN/SQL \
		CPAN/Template \
		CPAN/URI \
		CPAN/XML/Parser \
		CPAN/YAML

CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR}

SUB_FILES=	Custom.pm \
		pkg-install \
		softsqueeze.sh \
		custom-convert.conf
SUB_LIST=	PERL=${PERL} \
		PORTNAME=${PORTNAME} \
		SITE_PERL=${SITE_PERL} \
		SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		SLIMUSER=${SLIMUSER} \
		SLIMGROUP=${SLIMGROUP} \
		CONFFILES="${CONFFILES}"

pre-fetch:
.if !defined(SLIMDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define SLIMDIR to override default of 'squeezeboxserver'."
	@${ECHO_MSG} ""
.endif

SLIMDIR?=	squeezeboxserver
SLIMDBDIR?=	/var/db/squeezeboxserver
SLIMUSER?=	slimserv
SLIMGROUP?=	${SLIMUSER}

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|/usr/bin/perl|${PERL}|g' \
	    -e 's|%%DISTDIR%%|${_DISTDIR}|g' \
	    -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SITE_PERL%%|${SITE_PERL}|g' \
	    -e 's|%%SLIMDBDIR%%|${SLIMDBDIR}|g' \
	    -e 's|%%TMP_SLIMDIR%%|${TMP_SLIMDIR}|g' \
		${WRKSRC}/scanner.pl \
		${WRKSRC}/slimserver.pl
	${REINPLACE_CMD} \
		-e 's/skip-locking/skip-external-locking/' \
		-e 's/default-character-set/character-set-server/'\
		-e 's/default-collation/collation-server/'  ${WRKSRC}/MySQL/my.tt
	${REINPLACE_CMD} \
		-e 's/TYPE=InnoDB/ENGINE=InnoDB/' ${WRKSRC}/SQL/mysql/schema_*.sql

do-build:
	@${MKDIR} -m 0755 ${TMP_SLIMDIR}
	cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig -o -name \*.bak \
	    ${EXCEPTFILES:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S/$/\/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${TMP_SLIMDIR}
.for _CONF in ${CONFFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${_CONF} ${TMP_SLIMDIR}/${_CONF}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${TMP_DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${TMP_DOCSDIR}
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${SLIMDIR}
	@${RM} -f ${PREFIX}/${SLIMDIR}/Cache
	@${LN} -s ${SLIMDBDIR}/cache ${PREFIX}/${SLIMDIR}/Cache
	@cd ${TMP_SLIMDIR} && ${COPYTREE_SHARE} . ${PREFIX}/${SLIMDIR}
	@${INSTALL_DATA} ${WRKDIR}/Custom.pm \
	    ${PREFIX}/${SLIMDIR}/Slim/Utils/OS/Custom.pm
	@${INSTALL_DATA} ${WRKDIR}/custom-convert.conf \
	    ${PREFIX}/${SLIMDIR}/custom-convert.conf
	@${CHMOD} 755 ${PREFIX}/${SLIMDIR}/slimserver.pl
	@${CHMOD} 755 ${PREFIX}/${SLIMDIR}/scanner.pl
	@${LN} -sf ${LOCALBASE}/share/mysql/errmsg.txt \
	    ${LOCALBASE}/share/mysql/english/errmsg.sys \
	    ${PREFIX}/${SLIMDIR}/MySQL/
	@${INSTALL_SCRIPT} ${WRKDIR}/softsqueeze.sh ${PREFIX}/bin/softsqueeze
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${TMP_DOCSDIR} && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

build-plist:
	@${CAT} /dev/null > ${PLIST}
	@${ECHO} bin/softsqueeze >> ${PLIST}
.for _CONF in ${CONFFILES}
	@${ECHO} '@unexec if cmp -s %D/%%SLIMDIR%%/${_CONF} %D/%%SLIMDIR%%/${_CONF}.sample; then rm -f %D/%%SLIMDIR%%/${_CONF}; fi' >> ${PLIST}
.endfor
	@${FIND} ${TMP_DOCSDIR} -type f | \
	    ${SED} -e 's|${TMP_DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	@${FIND} ${TMP_SLIMDIR}/* -type f | \
	    ${SED} -e 's|${TMP_SLIMDIR}|%%SLIMDIR%%|' | \
	    ${SORT} >> ${PLIST}
	@${ECHO} "%%SLIMDIR%%/custom-convert.conf" >> ${PLIST}
	@${ECHO} "%%SLIMDIR%%/Cache" >> ${PLIST}
	@${ECHO} "%%SLIMDIR%%/MySQL/errmsg.txt" >> ${PLIST}
	@${ECHO} "%%SLIMDIR%%/MySQL/errmsg.sys" >> ${PLIST}
	@${ECHO} "%%SLIMDIR%%/Slim/Utils/OS/Custom.pm" >> ${PLIST}
	@${FIND} ${TMP_SLIMDIR} -type d | \
	    ${EGREP} -v "${TMP_SLIMDIR}(|/Plugins)$$" | \
	    ${SED} -e 's|${TMP_SLIMDIR}|@dirrm %%SLIMDIR%%|' | \
	    ${SORT} -r >> ${PLIST}
	@echo "@dirrmtry %%SLIMDIR%%/Plugins" >> ${PLIST}
	@echo "@dirrmtry %%SLIMDIR%%" >> ${PLIST}
	@${FIND} ${TMP_DOCSDIR} -type d | \
	    ${SED} -e 's|${TMP_DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' | \
	    ${SORT} -r >> ${PLIST}
	@${ECHO} '@unexec rm -rf ${SLIMDBDIR}/cache > /dev/null 2>&1 || true' >> ${PLIST}
	@${ECHO} '@dirrmtry ${SLIMDBDIR}/playlists' >> ${PLIST}
	@${ECHO} '@dirrmtry ${SLIMDBDIR}' >> ${PLIST}
	@${ECHO} '@unexec test -d ${SLIMDBDIR} && (echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove ${SLIMDBDIR} and its contents manually.")' >> ${PLIST}

.include <bsd.port.post.mk>
