# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Version control system

CONFLICTS_INSTALL=	subversion-devel-[0-9]* subversion-freebsd-[0-9]*

USE_RC_SUBR=	svnserve

MAN1=		svn.1 svnadmin.1 svnlook.1 svndumpfilter.1 svnsync.1 \
		svnversion.1
MAN5=		svnserve.conf.5
MAN8=		svnserve.8

TXT_DOCS=	BUGS CHANGES COMMITTERS COPYING HACKING INSTALL README

OPTIONS=	P4_STYLE_MARKERS	"Perforce-style conflict markers" on \
		ENHANCED_KEYWORD	"Enhanced svn:keyword support" on \
		FREEBSD_TEMPLATE	"FreeBSD Project log template" on \
		MOD_DAV_SVN	"mod_dav_svn module for Apache 2.X" off \
		MOD_DONTDOTHAT	"mod_dontdothat for Apache 2.X" off \
		NEON		"WebDAV/Delta-V repo access module (neon)" on \
		SERF		"WebDAV/Delta-V repo access module (serf)" off \
		SASL		"SASL2 authorization support" off \
		BDB		"Berkeley DB (4 or 5) repository backend" on \
		ASVN		"Build and install Archive SVN (asvn)" off \
		MAINTAINER_DEBUG	"Build debug version" off \
		SVNSERVE_WRAPPER	"Enable svnserve wrapper" off \
		SVNAUTHZ_VALIDATE	"install svnauthz-validate" off \
		STATIC		"Build static version (no shared libs)" off \
		GNOME_KEYRING	"Build with GNOME Keyring auth support" off \
		KDE_KWALLET	"Build with KDE KWallet auth support" off \
		BOOK		"Install the Subversion Book" off

.include "Makefile.common"

SVNREPOS?=	/home/svn/repos
SVNFSTYPE?=	fsfs

SUB_FILES=	pkg-install \
		pkg-deinstall

.if make(repository)
WITH_REPOSITORY_CREATION=	yes
.endif

.if defined(WITH_REPOSITORY_CREATION)
MKREPOS_TARGET=	_mkrepos
.endif

# Patches required for use with the FreeBSD Project repository only
.if !defined(WITHOUT_P4_STYLE_MARKERS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-3way-conflict-markers
.endif
.if !defined(WITHOUT_ENHANCED_KEYWORD)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-enhanced-keyword
.endif
.if !defined(WITHOUT_FREEBSD_TEMPLATE)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-fbsd-template
.endif

.if defined(WITH_SVNSERVE_WRAPPER)
PLIST_SUB+=	SVNSERVE_WRAPPER=""
SUB_LIST+=	SVNSERVE_BIN_EXT=".bin"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-svnserve-wrapper
.else
PLIST_SUB+=	SVNSERVE_WRAPPER="@comment "
SUB_LIST+=	SVNSERVE_BIN_EXT=""
.endif

.if !defined(NOPORTDOCS) && defined(WITH_BOOK)
BOOK_HTML=	svn-book-html.tar.bz2
BOOK_PDF=	svn-book.pdf
DISTFILES+=	${BOOK_HTML}:book ${BOOK_PDF}:book
PLIST_SUB+=	BOOK=""
.else
PLIST_SUB+=	BOOK="@comment "
.endif

.if defined(WITH_ASVN)
RUN_DEPENDS+=	${LOCALBASE}/bin/gfind:${PORTSDIR}/misc/findutils:install
PLIST_SUB+=	ASVN=""
.else
PLIST_SUB+=	ASVN="@comment "
.endif

SCRIPTS=

SCRIPTS_DATA=

pre-everything::
	@${ECHO_MSG} ""
.if defined(WITH_NEON)
	@${ECHO_MSG} "WebDAV/Delta-V repository access module enabled."
.else
	@${ECHO_MSG} "WebDAV/Delta-V repository access module disabled."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_BDB)
	@${ECHO_MSG} "Berkeley DB (4 or 5) repository backend enabled."
.else
	@${ECHO_MSG} "Berkeley DB (4 or 5) repository backend disabled."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_MAINTAINER_DEBUG)
	@${ECHO_MSG} "Build debug version."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_MOD_DAV_SVN)
.if defined(WITH_STATIC)
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! mod_dav_svn and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
	@${ECHO_MSG} "mod_dav_svn module for Apache 2.X enabled."
.else
	@${ECHO_MSG} "You can enable the mod_dav_svn module for Apache 2.X"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_MOD_DONTDOTHAT) && defined(WITH_MOD_DAV_SVN)
	@${ECHO_MSG} "mod_dontdothat module for Apache 2.X enabled."
.else
	@${ECHO_MSG} "You can enable the mod_dontdothat module for Apache 2.X"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_SVNSERVE_WRAPPER)
	@${ECHO_MSG} "svnserve wrapper enabled."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_SVNAUTHZ_VALIDATE)
.if defined(WITH_STATIC)
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! svnauthz-validate and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
	@${ECHO_MSG} "svnauthz-validate enabled."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_REPOSITORY_CREATION)
	@${ECHO_MSG} "I will create (or use, if it exists) '${SVNUSER}' user and '${SVNGROUP}' group."
	@${ECHO_MSG} "Make sure that all committers are its members."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Repository will be created at '${SVNREPOS}' with user '${SVNUSER}' and group '${SVNGROUP}'."
	@${ECHO_MSG} "Type of repository will be '${SVNFSTYPE}'."
	@${ECHO_MSG} "You could change these settings by defining SVNREPOS, SVNGROUP and SVNFSTYPE."
.else
	@${ECHO_MSG} "You can have the repository created for you by defining"
	@${ECHO_MSG} "WITH_REPOSITORY_CREATION."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Make sure that:"
	@${ECHO_MSG} "* all your svn users are members of a common group"
	@${ECHO_MSG} "* this group is the group id of the db/ and locks/"
	@${ECHO_MSG} "  subdirectories of your repository"
	@${ECHO_MSG} "* the above subdirectories are writable by this group"
.endif
	@${ECHO_MSG} ""
.if !defined(NOPORTDOCS) && defined(WITH_BOOK)
	@${ECHO_MSG} "Subversion Book will be installed."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_ASVN)
	@${ECHO_MSG} "asvn will be installed"
	@${ECHO_MSG} ""
.endif
.if defined(WITH_STATIC)
	@${ECHO_MSG} "Static binaries will be built."
.endif
	@${ECHO_MSG} "Many useful scripts will be installed into ${DATADIR}"

pre-configure:
.if !defined(WITHOUT_BDB)
	@BDB_VERSION=`${APR_APU_DIR}/${APU_CONFIG} --db-version`; \
	if [ "$${BDB_VERSION}" != "4" -a "$${BDB_VERSION}" != "5" ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You should build `'"${APR_PORT}' with Berkeley DB (4 or 5) support to use subversion with it." ; \
		${ECHO_MSG} 'Please rebuild `'"${APR_PORT}' with option "'`'"${OPT_NAME}' and try again." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Or you can disable Berkeley DB support. Only 'fs' repository backend will be available." ; \
		${ECHO_MSG} "To disable Berkeley DB support, define WITHOUT_BDB." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.endif

post-build:
.if defined(WITH_MOD_DAV_SVN) && defined(WITH_MOD_DONTDOTHAT)
	cd ${WRKSRC}/contrib/server-side/mod_dontdothat && \
		${APXS} -c -I${WRKSRC}/subversion/include -L${WRKSRC}/subversion/libsvn_subr/.libs -lsvn_subr-1 mod_dontdothat.c
.endif
.if defined(WITH_SVNAUTHZ_VALIDATE)
	# place binary in ${WRKDIR}, else we install it twice
	cd ${WRKSRC}/tools/server-side && \
		${CC} svnauthz-validate.c -o ../../svnauthz-validate -I${WRKSRC}/subversion/include -I${APR_INCLUDE_DIR} \
		-L${WRKSRC}/subversion/libsvn_repos/.libs -L${WRKSRC}/subversion/libsvn_subr/.libs -lsvn_repos-1 -lsvn_subr-1
.endif

pre-install:
.if defined(WITH_MOD_DAV_SVN)
# activate dav_module now in pkg-install to prevent double activation.
# workaround for apxs bug: https://issues.apache.org/bugzilla/show_bug.cgi?id=47397
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:	${MKREPOS_TARGET}
.if defined(WITH_MOD_DAV_SVN)
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n authz_svn ${PREFIX}/${APACHEMODDIR}/mod_authz_svn.so
.if defined(WITH_MOD_DONTDOTHAT)
	cd ${WRKSRC}/contrib/server-side/mod_dontdothat && \
		${APXS} -i -n dontdothat mod_dontdothat.la
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n dontdothat ${PREFIX}/${APACHEMODDIR}/mod_dontdothat.so
.endif
.endif
.if defined(WITH_SVNAUTHZ_VALIDATE)
	${INSTALL_PROGRAM} ${WRKSRC}/svnauthz-validate ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/tools ; \
	  ${TAR} --exclude '*.in' -cf - * | ${TAR} -C ${DATADIR} -xf -
	@${CHMOD} -R a-st,o+rX ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_MAN} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.if defined(WITH_BOOK)
	${TAR} -xof ${DISTDIR}/${DIST_SUBDIR}/${BOOK_HTML} -C ${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/${BOOK_PDF} ${DOCSDIR}
.endif
.endif
.if defined(WITH_ASVN)
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/client-side/asvn ${PREFIX}/bin
.endif
.if defined(WITH_SVNSERVE_WRAPPER)
	@${INSTALL_SCRIPT} ${FILESDIR}/svnserve.wrapper ${PREFIX}/bin/svnserve
.endif

repository:	_mkrepos

_SVNGRPFILES=	dav db locks locks/db.lock locks/db-logs.lock
SVNGRPFILES=	${_SVNGRPFILES:S,^,${SVNREPOS}/,}

_mkrepos:	.USE
.if !exists(${SVNREPOS})
.if defined(WITH_SVNSERVE_WRAPPER)
	@if /usr/sbin/pw groupshow "${SVNGROUP}" >/dev/null 2>&1; then \
	    ${ECHO_MSG} "You already have a group \"${SVNGROUP}\", so I will use it."; \
	else \
	    if /usr/sbin/pw groupadd ${SVNGROUP} -h -; \
	    then \
	        ${ECHO_MSG} "Added group \"${SVNGROUP}\"."; \
	    else \
	        ${ECHO_MSG} "Adding group \"${SVNGROUP}\" failed..."; \
	        ${ECHO_MSG} "Please create it, and try again."; \
	        ${FALSE}; \
	    fi; \
	fi
	@if /usr/sbin/pw usershow "${SVNUSER}" >/dev/null 2>&1; then \
	    ${ECHO_MSG} "You already have a user \"${SVNUSER}\", so I will use it."; \
	else \
	    if /usr/sbin/pw useradd ${SVNUSER} -h -; \
	    then \
	        ${ECHO_MSG} "Added user \"${SVNUSER}\"."; \
	    else \
	        ${ECHO_MSG} "Adding user \"${SVNUSER}\" failed..."; \
	        ${ECHO_MSG} "Please create it, and try again."; \
	        ${FALSE}; \
	    fi; \
	fi
.endif
	@${MKDIR} ${SVNREPOS}
	@${PREFIX}/bin/svnadmin create --fs-type ${SVNFSTYPE} ${SVNREPOS}
.if defined(WITH_SVNSERVE_WRAPPER)
	@${CHOWN} ${SVNUSER}:${SVNGROUP} ${SVNGRPFILES}
	@${CHMOD} g+w ${SVNGRPFILES}
	@for i in ${SVNREPOS}/db/* ; do \
	    i=$${i##*/}; \
	    case $$i in \
	    DB_CONFIG|fs-type|uuid) ;; \
	    *) ${CHOWN} -R ${SVNUSER}:${SVNGROUP} ${SVNREPOS}/db/$$i; \
	       ${CHMOD} -R g+w ${SVNREPOS}/db/$$i; \
	       ;; \
	    esac; \
	done
.endif
.endif

post-deinstall:
.if defined(WITH_MOD_DAV_SVN)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL
.endif

svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	${MV} ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include <bsd.port.post.mk>
