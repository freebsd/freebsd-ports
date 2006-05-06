# Ports collection makefile for:	slimserver
# Date created:				Wed Apr 14, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	slimserver
PORTVERSION=	6.2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.slimdevices.com/downloads/SlimServer_v${PORTVERSION}/
DISTNAME=	SlimServer_v${PORTVERSION}.no-cpan-arch
DIST_SUBDIR=	slimserver

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS=	APE "Support Monkey's Audio Codec input" on \
		FAAD "Support AAC input via FAAD" on \
		FLAC "Support FLAC output (and inputs on older devices)" on \
		LAME "Support MP3 output via LAME" off \
		MUSEPACK "Support musepack input" on \
		SHORTEN "Support Shorten input" off \
		VORBIS "Support OGG Vorbis input" on

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

WRKSRC=		${WRKDIR}/SlimServer_v${PORTVERSION}

LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder

PKGINSTALL=	${WRKDIR}/pkg-install

USE_PERL5=	yes

SLIMCPANPKGS=	Compress-Zlib-1.33.tar.gz \
		DBI-1.46.tar.gz \
		DBD-SQLite-1.08.tar.gz \
		HTML-Parser-3.45.tar.gz \
		Template-Toolkit-2.13.tar.gz \
		Time-HiRes-1.66.tar.gz \
		XML-Parser-2.34.tar.gz

ALLFILES=	${DISTFILES} ${SLIMCPANPKGS}

.include <bsd.port.pre.mk>

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
.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PERL_LEVEL} < 500800
IGNORE=		perl 5.8 or newer required. Install lang/perl5.8 and try again
.endif

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	{LOCALBASE}/bin/pgrep:${PORTSDIR}/sysutils/pkill
PGREPBASE=	${LOCALBASE}
.else
PGREPBASE=	/usr
.endif

USE_RC_SUBR=	slimserver.sh
TMP_SLIMDIR=	${WRKDIR}/slimserver
TMP_DOCSDIR=	${WRKDIR}/doc
CPANWRKDIR=	${WRKDIR}/cpantemp
DOCFILES=	Changelog.html Installation.txt License.txt
CONFFILES=	convert.conf types.conf
EXCEPTFILES=	${DOCFILES} ${CONFFILES}
EXCEPTDIRS=	Bin \
		CPAN/arch

CPIOARGS=	--quiet -pdum -R
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	SLIMDIR=${SLIMDIR}
PLIST_FILES=	bin/softsqueeze

SUB_FILES=	softsqueeze.sh pkg-install
SUB_LIST=	PGREPBASE=${PGREPBASE} \
		SLIMDIR=${SLIMDIR} \
		CONFFILES="${CONFFILES}"

pre-fetch:
.if !defined(SLIMDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define SLIMDIR to override default of 'slimserver'."
	@${ECHO_MSG} ""
.endif

SLIMDIR?=	slimserver

post-fetch:
.for _PKG in ${SLIMCPANPKGS}
	@cd ${_DISTDIR}; test -e ${_PKG} || \
	    ${FETCH_CMD} -o ${_PKG} http://svn.slimdevices.com/vendor/src/${_PKG}?view=auto
.endfor

post-patch:
	${REINPLACE_CMD} \
		-e 's|%%PERL%%|${PERL}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%TMP_SLIMDIR%%|${TMP_SLIMDIR}|' \
		-e 's|%%CPANWRKDIR%%|${CPANWRKDIR}|' \
		-e 's|%%DISTDIR%%|${_DISTDIR}|' ${WRKSRC}/Bin/build-perl-modules.pl

do-build:
	@${MKDIR} -m 0755 ${TMP_SLIMDIR}
	@cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S/$/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${TMP_SLIMDIR}
.for _CONF in ${CONFFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${_CONF} ${TMP_SLIMDIR}/${_CONF}.sample
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TMP_DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${TMP_DOCSDIR}
.endif
	${MKDIR} ${CPANWRKDIR}
	${WRKSRC}/Bin/build-perl-modules.pl

post-build:
	@${RM} -f ${PLIST}
.for _CONF in ${CONFFILES}
	@${ECHO} '@unexec if cmp -s %D/%%SLIMDIR%%/${_CONF} %D/%%SLIMDIR%%/${_CONF}.sample; then rm -f %D/%%SLIMDIR%%/${_CONF}; fi' >> ${PLIST}
.endfor
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
	@${ECHO} '@unexec rm -rf /var/db/slimserver/cache > /dev/null 2>&1 || true' >> ${PLIST}
	@${ECHO} '@dirrmtry /var/db/slimserver/playlists' >> ${PLIST}
	@${ECHO} '@dirrmtry /var/db/slimserver' >> ${PLIST}
	@${ECHO} '@unexec test -d /var/db/slimserver && (echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove /var/db/slimserver and its contents manually.")' >> ${PLIST}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${SLIMDIR}
	@${LN} -s /var/db/slimserver/cache ${PREFIX}/${SLIMDIR}/Cache
	@cd ${TMP_SLIMDIR} && \
	    ${FIND} . | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/softsqueeze.sh ${PREFIX}/bin/softsqueeze
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
