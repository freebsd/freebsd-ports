# Ports collection makefile for:	slimserver
# Date created:				Wed Apr 14, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	slimserver
PORTVERSION?=	5.4.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.slimdevices.com/downloads/${NIGHTLY}SlimServer_v${DISTVERSION}/
DISTNAME=	SlimServer_v${DISTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

DISTVERSION?=	${PORTVERSION}


RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder

.include <bsd.port.pre.mk>

SLIM_CPAN_DEPS!= cut -f 2 -d, ${FILESDIR}/pm2port | grep -v ^_builtin
RUN_DEPENDS+=	${SLIM_CPAN_DEPS:S|^|${SITE_PERL}/|:S|:|:${PORTSDIR}/|}

.if ${PERL_LEVEL} < 500800
IGNORE=	"Perl 5.8 or newer required. Install lang/perl5.8 and try again."
.endif

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
		CPAN/File/.exists \
		CPAN/MP3/.exists
EXCEPTDIRS=	Bin \
		CPAN/arch

CPIOARGS=	--quiet -pdum -R
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	SLIMDIR=${SLIMDIR}

SED_SCRIPT+=	-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
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
	@${SED} ${SED_SCRIPT} <${FILESDIR}/softsqueeze.sh >${WRKDIR}/softsqueeze.sh

SLIMDIR?=	slimserver

do-build:
	@${MKDIR} -m 0755 ${TMP_SLIMDIR}
	@cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S/$/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${TMP_SLIMDIR}
	@cd ${TMP_SLIMDIR}/CPAN && \
	    for pm in `egrep -v ,$$ ${FILESDIR}/pm2port | cut -f 1 -d,`; do \
		grep "$${pm}:" ${FILESDIR}/CPANfiles | cut -f2 -d: | xargs rm; \
	    done
	@find ${TMP_SLIMDIR}/CPAN -depth -type d -empty -delete
.if defined(PORTDEV)
	@echo "Checking for unexpected files in CPAN"
	@cd ${TMP_SLIMDIR}/CPAN && \
	    for file in `find . -type f | sed -e 's|^\./||'`; do \
		egrep -q ":$${file}\$$" ${FILESDIR}/CPANfiles || \
		    echo $${file} ; \
	    done
	@echo
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TMP_DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${TMP_DOCSDIR}
.endif
	@${ECHO} "etc/rc.d/slimserver${PKGNAMESUFFIX}.sh" > ${PLIST}
	@${ECHO} "bin/softsqueeze" >> ${PLIST}
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
