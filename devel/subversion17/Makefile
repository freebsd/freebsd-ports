# Created by: rooneg@electricjellyfish.net
# $FreeBSD$

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Version control system

CONFLICTS_INSTALL=	subversion-1.[6|8].[0-9]*

USE_RC_SUBR=	svnserve

MAN1=		svn.1 svnadmin.1 svnlook.1 svndumpfilter.1 svnrdump.1 \
		svnsync.1 svnversion.1
MAN5=		svnserve.conf.5
MAN8=		svnserve.8

TXT_DOCS=	BUGS CHANGES COMMITTERS INSTALL README

OPTIONS_DEFINE=	P4_STYLE_MARKERS ENHANCED_KEYWORD FREEBSD_TEMPLATE \
		MOD_DAV_SVN MOD_DONTDOTHAT SVNAUTHZ_VALIDATE \
		NEON SERF \
		SASL BDB \
		MAINTAINER_DEBUG \
		SVNSERVE_WRAPPER SVNMUCC \
		STATIC \
		GNOME_KEYRING KDE_KWALLET \
		BOOK TEST

OPTIONS_DEFAULT=P4_STYLE_MARKERS ENHANCED_KEYWORD FREEBSD_TEMPLATE NEON

BOOK_DESC=		Install the Subversion Book
ENHANCED_KEYWORD_DESC=	Enhanced svn:keyword support
FREEBSD_TEMPLATE_DESC=	FreeBSD Project log template
GNOME_KEYRING_DESC=	Build with GNOME Keyring auth support
KDE_KWALLET_DESC=	Build with KDE KWallet auth support
MAINTAINER_DEBUG_DESC=	Build debug version
MOD_DAV_SVN_DESC=	mod_dav_svn module for Apache 2.X
MOD_DONTDOTHAT_DESC=	mod_dontdothat for Apache 2.X
NEON_DESC=		WebDAV/Delta-V repo access module (neon)
P4_STYLE_MARKERS_DESC=	Perforce-style conflict markers
SERF_DESC=		WebDAV/Delta-V repo access module (serf)
STATIC_DESC=		Build static version (no shared libs)
SVNAUTHZ_VALIDATE_DESC=	install svnauthz-validate
SVNMUCC_DESC=		Install Multiple URL Command Client
SVNSERVE_WRAPPER_DESC=	Enable svnserve wrapper (umask setter)
TEST_DESC=		Run subversion test suite

.include "Makefile.common"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

SVNREPOS?=	/home/svn/repos
SVNFSTYPE?=	fsfs

SUB_FILES=	pkg-install \
		pkg-deinstall
		
BOOK_VERSION=	4515

.if make(repository)
WITH_REPOSITORY_CREATION=	yes
.endif

.if defined(WITH_REPOSITORY_CREATION)
MKREPOS_TARGET=	_mkrepos
.endif

# Patches required for use with the FreeBSD Project repository only
.if ${PORT_OPTIONS:MP4_STYLE_MARKERS}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-3way-conflict-markers
.endif
.if ${PORT_OPTIONS:MENHANCED_KEYWORD}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-enhanced-keyword
.endif
.if ${PORT_OPTIONS:MFREEBSD_TEMPLATE}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-fbsd-template
.endif

.if empty(PORT_OPTIONS:MMAINTAINER_DEBUG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in
.endif

.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
PLIST_SUB+=	SVNSERVE_WRAPPER=""
SUB_LIST+=	SVNSERVE_BIN_EXT=".bin"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-svnserve-wrapper
.else
PLIST_SUB+=	SVNSERVE_WRAPPER="@comment "
SUB_LIST+=	SVNSERVE_BIN_EXT=""
.endif

.if ${PORT_OPTIONS:MSVNMUCC}
PLIST_SUB+=	SVNMUCC=""
.else
PLIST_SUB+=	SVNMUCC="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MBOOK}
BOOK_HTML=	svn-book-html-r${BOOK_VERSION}.tar.bz2
BOOK_PDF=	svn-book-r${BOOK_VERSION}.pdf
DISTFILES+=	${BOOK_HTML}:book ${BOOK_PDF}:book
PLIST_SUB+=	BOOK=""
.else
PLIST_SUB+=	BOOK="@comment "
.endif

# testsuite will fail until PR156076 is committed
.if ${PORT_OPTIONS:MTEST}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

#.if ${PORT_OPTIONS:MASVN}
#RUN_DEPENDS+=	${LOCALBASE}/bin/gfind:${PORTSDIR}/misc/findutils
#PLIST_SUB+=	ASVN=""
#.else
PLIST_SUB+=	ASVN="@comment "
#.endif

SCRIPTS=

SCRIPTS_DATA=

.if ${PORT_OPTIONS:MSTATIC}
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext:build
.endif
.if ${PORT_OPTIONS:MBDB}
BDB_BUILD_DEPENDS=	yes
.endif
OLD_LIB_DEPENDS:=	${LIB_DEPENDS:S!^!${LOCALBASE}/lib/lib!:C!(\.[0-9]+)?:!.a:!}
BUILD_DEPENDS+=		${OLD_LIB_DEPENDS}
LIB_DEPENDS=
.endif

pre-everything::
	@${ECHO_MSG} ""
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
.if !defined(NOPORTDOCS) && ${PORT_OPTIONS:MBOOK}
	@${ECHO_MSG} "Subversion Book will be installed."
	@${ECHO_MSG} ""
.endif
.if ${PORT_OPTIONS:MSTATIC}
.if ${PORT_OPTIONS:MMOD_DAV_SVN}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! mod_dav_svn and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MSVNAUTHZ_VALIDATE}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! svnauthz_validate and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MGNOME_KEYRING}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! Gnome Keyring and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MKDE_WALLET}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! KDE Wallet and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.endif
	@${ECHO_MSG} "Static binaries will be built."
.endif
	@${ECHO_MSG} "Many useful scripts will be installed into ${DATADIR}"

pre-configure:
.if ${PORT_OPTIONS:MBDB}
	@BDB_VERSION=`${APR_APU_DIR}/${APU_CONFIG} --db-version`; \
	if [ "$${BDB_VERSION}" != "4" -a "$${BDB_VERSION}" != "5" ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You should build `'"${APR_PORT}' with Berkeley DB (4 or 5) support to use subversion with it." ; \
		${ECHO_MSG} 'Please rebuild `'"${APR_PORT}' with option "'`'"${OPT_NAME}' and try again." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Or you can disable Berkeley DB support. Only 'fs' repository backend will be available." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.endif
.if ${PORT_OPTIONS:MSTATIC}
	@if grep -q icui18n ${LOCALBASE}/lib/libsqlite3.la ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "You can not build static subversion if your SQLite3 is built with ICU enabled."; \
		${ECHO_MSG} "Please, reinstall 'devel/sqlite3' port with disabled ICU support."; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi		
.endif

# takes a long time, and will fail but gives maintainer a good oversight
.if ${PORT_OPTIONS:MTEST}
test:
	-@make check -C ${WRKSRC}
.endif

pre-install:
.if ${PORT_OPTIONS:MMOD_DAV_SVN}
# activate dav_module now in pkg-install to prevent double activation.
# workaround for apxs bug: https://issues.apache.org/bugzilla/show_bug.cgi?id=47397
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:	${MKREPOS_TARGET}
.if ${PORT_OPTIONS:MMOD_DAV_SVN}
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n dav_svn ${PREFIX}/${APACHEMODDIR}/mod_dav_svn.so
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n authz_svn ${PREFIX}/${APACHEMODDIR}/mod_authz_svn.so
. if ${PORT_OPTIONS:MMOD_DONTDOTHAT}
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n dontdothat ${PREFIX}/${APACHEMODDIR}/mod_dontdothat.so
. endif
.endif
.if ${PORT_OPTIONS:MSVNAUTHZ_VALIDATE}
	${LIBTOOL} --mode=install ${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/tools/server-side/svnauthz-validate ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/tools ; \
	  ${TAR} --exclude '*.in' --exclude '.libs' --exclude '*.o' --exclude '*.lo' --exclude '*.la' --exclude='*.slo' -cf - * | ${TAR} -C ${DATADIR} -xf -
# ugly hack to remove libtool scripts ...
	@${GREP} -R ${WRKSRC} ${DATADIR} | ${CUT} -d\: -f 1 | ${XARGS} ${RM} -f
	@${CHMOD} -R a-st,o+rX ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_MAN} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
. if ${PORT_OPTIONS:MBOOK}
	${TAR} -xof ${DISTDIR}/${DIST_SUBDIR}/${BOOK_HTML} -C ${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/${BOOK_PDF} ${DOCSDIR}/svn-book.pdf
. endif
.endif
.if ${PORT_OPTIONS:MASVN}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/client-side/asvn ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
	@${INSTALL_SCRIPT} ${FILESDIR}/svnserve.wrapper ${PREFIX}/bin/svnserve
.endif
.if ${PORT_OPTIONS:MSVNMUCC}
. if ${PORT_OPTIONS:MSTATIC}
	@${INSTALL} ${WRKSRC}/tools/client-side/svnmucc/svnmucc ${PREFIX}/bin
. else
	@${INSTALL} ${WRKSRC}/tools/client-side/svnmucc/.libs/svnmucc ${PREFIX}/bin
. endif
.endif

repository:	_mkrepos

_SVNGRPFILES=	db locks locks/db.lock locks/db-logs.lock
.if ${PORT_OPTIONS:MMOD_DAV_SVN}
_SVNGRPFILES+=	dav
.endif
SVNGRPFILES=	${_SVNGRPFILES:S,^,${SVNREPOS}/,}

_mkrepos:	.USE
.if !exists(${SVNREPOS})
.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
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
.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
.if ${PORT_OPTIONS:MMOD_DAV_SVN}
	@${MKDIR} ${SVNREPOS}/dav
.endif
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

svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	${MV} ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include <bsd.port.post.mk>
