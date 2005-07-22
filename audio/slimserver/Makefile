# Ports collection makefile for:	slimserver
# Date created:				Wed Apr 14, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	slimserver
PORTVERSION?=	6.1.1
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.slimdevices.com/downloads/${NIGHTLY}SlimServer_v${DISTVERSION}/
DISTNAME=	SlimServer_v${DISTVERSION}
DISTFILES=	${DISTNAME}.no-cpan-arch${EXTRACT_SUFX}
DIST_SUBDIR=	slimserver

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

DISTVERSION?=	${PORTVERSION}

LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2
RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder

PKGINSTALL=	${WRKDIR}/pkg-install

USE_PERL5=	yes

.include <bsd.port.pre.mk>

SLIMCPANPKGS=	Compress-Zlib-1.33.tar.gz \
		DBI-1.46.tar.gz \
		DBD-SQLite-1.08.tar.gz \
		HTML-Parser-3.45.tar.gz \
		Template-Toolkit-2.13.tar.gz \
		Time-HiRes-1.66.tar.gz \
		XML-Parser-2.34.tar.gz

ALLFILES=	${DISTFILES} ${SLIMCPANPKGS}

.if ${PERL_LEVEL} < 500800
IGNORE=		Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	${LOCALBASE}/bin/pgrep:${PORTSDIR}/sysutils/pkill
PGREPBASE=	${LOCALBASE}
.else
PGREPBASE=	/usr
.endif

USE_RC_SUBR=	slimserver.sh
USE_REINPLACE=	yes
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
	@${ECHO} '@unexec rmdir /var/db/slimserver 2>/dev/null || (echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove /var/db/slimserver and its contents manually.")' >> ${PLIST}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${SLIMDIR}
	@${LN} -s /var/db/slimserver/cache ${PREFIX}/${SLIMDIR}/Cache
	@cd ${TMP_SLIMDIR} && \
	    ${FIND} . | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/slimserver.sh \
	    ${PREFIX}/etc/rc.d/slimserver${PKGNAMESUFFIX}.sh
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
