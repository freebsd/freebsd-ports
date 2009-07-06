# Ports collection makefile for:		squeezecenter
# Date created:					Wed Apr 14, 2004
# Whom:						Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	squeezecenter
PORTVERSION=	7.3.3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.slimdevices.com/SqueezeCenter_v${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.0//}-noCPAN
EXTRACT_SUFX=	.tgz

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS=	APE "Support Monkey's Audio Codec input" on \
		FAAD "Support AAC input via FAAD" on \
		FLAC "Support FLAC output (and input on SliMP3 and SB1)" on \
		LAME "Support MP3 output via LAME" off \
		MUSEPACK "Support musepack input" on \
		SHORTEN "Support Shorten input" off \
		SOX "Support OGG Vorbis input via SoX (SliMP3 and SB1)" on

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

WRKSRC=	${WRKDIR}/squeezecenter-${PORTVERSION:S/.0//}-noCPAN

BUILD_DEPENDS+=	${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Encode/Detect.pm:${PORTSDIR}/converters/p5-Encode-Detect \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/${PERL_ARCH}/JSON/XS.pm:${PORTSDIR}/converters/p5-JSON-XS \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck

PKGINSTALL=	${WRKDIR}/pkg-install

USE_PERL5=	yes
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323 40

.include <bsd.port.pre.mk>

# We need a dependency on the server because squeezecenter runs the binary
# directly with a non-standard config.
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server

.if !defined(WITHOUT_APE)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif
.if !defined(WITHOUT_FAAD)
RUN_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif
.if !defined(WITHOUT_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if !defined(WITHOUT_MUSEPACK)
RUN_DEPENDS+=	mppdec:${PORTSDIR}/audio/musepack
.endif
.if !defined(WITHOUT_SHORTEN)
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
.endif
.if !defined(WITHOUT_SOX)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

USE_RC_SUBR=	squeezecenter.sh
TMP_SLIMDIR=	${WRKDIR}/_squeezecenter
TMP_DOCSDIR=	${WRKDIR}/doc
DOCFILES=	Changelog.html Installation.txt License.txt
CONFFILES=	convert.conf types.conf
EXCEPTFILES=	${DOCFILES} \
		${CONFFILES} \
		CPAN/DBI.pm \
		CPAN/GD.pm \
		CPAN/JSON/XS/Boolean.pm \
		CPAN/JSON/XS.pm \
		CPAN/Template.pm \
		CPAN/XML/Parser.pm \
		MySQL/errmsg.txt \
		MySQL/errmsg.sys
EXCEPTDIRS=	Bin \
		CPAN/arch \
		CPAN/Compress \
		CPAN/DBI \
		CPAN/Digest \
		CPAN/Encode \
		CPAN/GD \
		CPAN/Template \
		CPAN/XML/Parser \
		CPAN/YAML

CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	SLIMDIR=${SLIMDIR}

SUB_FILES=	Custom.pm \
		pkg-install \
		softsqueeze.sh
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
	@${ECHO_MSG} "Define SLIMDIR to override default of 'squeezecenter'."
	@${ECHO_MSG} ""
.endif

SLIMDIR?=	squeezecenter
SLIMDBDIR?=	/var/db/squeezecenter
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
.if !defined(NOPORTDOCS)
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
	@${CHMOD} 755 ${PREFIX}/${SLIMDIR}/slimserver.pl
	@${CHMOD} 755 ${PREFIX}/${SLIMDIR}/scanner.pl
	@${LN} -sf ${LOCALBASE}/share/mysql/errmsg.txt \
	    ${LOCALBASE}/share/mysql/english/errmsg.sys \
	    ${PREFIX}/${SLIMDIR}/MySQL/
	@${INSTALL_SCRIPT} ${WRKDIR}/softsqueeze.sh ${PREFIX}/bin/softsqueeze
.if !defined(NOPORTDOCS)
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
