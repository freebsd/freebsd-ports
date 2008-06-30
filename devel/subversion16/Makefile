# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

MAINTAINER=	lev@freebsd.org
COMMENT=	Version control system

CONFLICTS?=	subversion-devel-[0-9]* subversion-freebsd-[0-9]*

USE_RC_SUBR=	svnserve

MAN1=		svn.1 svnadmin.1 svnlook.1 svndumpfilter.1 svnsync.1 svnversion.1
MAN5=		svnserve.conf.5
MAN8=		svnserve.8

TXT_DOCS=	BUGS CHANGES COMMITTERS COPYING HACKING INSTALL README

OPTIONS=	MOD_DAV_SVN	"mod_dav_svn module for Apache 2.X" off \
		APACHE2_APR	"Use APR from Apache 2.X" off \
		NEON		"WebDAV/Delta-V repo access module (neon)" on \
		SERF		"WebDAV/Delta-V repo access module (serf)" off \
		SASL		"SASL2 authorization support" off \
		BDB		"db4 repository backend" on \
		ASVN		"Build and install Archive SVN (asvn)" off \
		MAINTAINER_DEBUG	"Build debug version" off \
		SVNSERVE_WRAPPER	"Enable svnserve wrapper" off \
		BOOK		"Install the Subversion Book" off

.include "${.CURDIR}/../../devel/subversion/Makefile.common"

SVNREPOS?=	/home/svn/repos
SVNFSTYPE?=	fsfs

.if make(repository)
WITH_REPOSITORY_CREATION=	yes
.endif

.if defined(WITH_REPOSITORY_CREATION)
MKREPOS_TARGET=	_mkrepos
.endif

CONFIGURE_ARGS+=	--without-swig

.if defined(WITH_NEON)
LIB_DEPENDS+=	neon.28:${PORTSDIR}/www/neon28
CONFIGURE_ARGS+=	--with-neon=${LOCALBASE}
PLIST_SUB+=		NEON=""
.else
CONFIGURE_ARGS+=	--without-neon
PLIST_SUB+=		NEON="@comment "
.endif

.if defined(WITH_SERF)
LIB_DEPENDS+=	serf-0.0:${PORTSDIR}/www/serf
CONFIGURE_ARGS+=	--with-serf=${LOCALBASE}
PLIST_SUB+=		SERF=""
.else
PLIST_SUB+=		SERF="@comment "
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
PLIST_SUB+=		SASL=""
.else
PLIST_SUB+=		SASL="@comment "
.endif

.if defined(WITH_BDB)
PLIST_SUB+=		BDB=""
.else
CONFIGURE_ARGS+=	--without-berkeley-db
PLIST_SUB+=		BDB="@comment "
.endif

.if defined(WITH_MOD_DAV_SVN)
WITH_APACHE2_APR=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=	MOD_DAV_SVN=""
SVNGROUP?=	www
.else
PLIST_SUB+=	MOD_DAV_SVN="@comment "
PKGDEINSTALL=	NONEXISTENT
SVNGROUP?=	svn
.endif

.if defined(WITH_APACHE2_APR)
USE_APACHE=	2.0+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.if ${APACHE_VERSION} >= 21
APR_APU_DIR=	${LOCALBASE}/bin
APR_CONFIG=	apr-1-config
APU_CONFIG=	apu-1-config
.else
APR_APU_DIR=	${LOCALBASE}/lib/apache2
APR_CONFIG=	apr-config
APU_CONFIG=	apu-config
.endif
APR_PORT=	${APACHE_PORT}
.if defined(WITH_BDB)
DEPENDS_ARGS+=	WITH_BERKELEYDB=db4
OPT_NAME=	WITH_BERKELEYDB=(db4|db41|db42)
.endif
.else
APR_APU_DIR=	${LOCALBASE}/bin
APR_CONFIG=	apr-1-config
APU_CONFIG=	apu-1-config
.if defined(WITH_BDB)
LIB_DEPENDS+=	apr-1.2:${PORTSDIR}/devel/apr-svn
APR_PORT=	devel/apr-svn
OPT_NAME=	APR_UTIL_WITH_BERKELEY_DB=yes
.else
LIB_DEPENDS+=	apr-1.2:${PORTSDIR}/devel/apr
APR_PORT=	devel/apr
.endif
.endif
CONFIGURE_ARGS+=--with-apr=${APR_APU_DIR}/${APR_CONFIG} \
		--with-apr-util=${APR_APU_DIR}/${APU_CONFIG}

.if defined(WITH_SVNSERVE_WRAPPER)
PLIST_SUB+=	SVNSERVE_WRAPPER=""
SUB_LIST+=	SVNSERVE_BIN_EXT=".bin"
EXTRA_PATCHES=	${PATCHDIR}/build-outputs.mk.patch
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
RUN_DEPENDS=	${LOCALBASE}/bin/gfind:${PORTSDIR}/misc/findutils:install
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
	@${ECHO_MSG} "db4 repository backend enabled."
.else
	@${ECHO_MSG} "db4 repository backend disabled."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_MAINTAINER_DEBUG)
	@${ECHO_MSG} "Build debug version."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_MOD_DAV_SVN)
	@${ECHO_MSG} "mod_dav_svn module for Apache 2.X enabled."
	@${ECHO_MSG} "This option implies the WITH_APACHE2_APR option."
.else
	@${ECHO_MSG} "You can enable the mod_dav_svn module for Apache 2.X"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_APACHE2_APR)
	@${ECHO_MSG} "Using APR from ${APACHE_PORT}.  If you have the devel/apr"
	@${ECHO_MSG} "port/package installed, you may need to remove it."
.else
	@${ECHO_MSG} "You can link subversion against the APR built with"
	@${ECHO_MSG} "the ${APACHE_PORT} port, rather than the devel/apr port."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_SVNSERVE_WRAPPER)
	@${ECHO_MSG} "svnserve wrapper enabled."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_REPOSITORY_CREATION)
	@${ECHO_MSG} "I will create (or use, if it exists) \"${SVNGROUP}\" group."
	@${ECHO_MSG} "Make sure that all committers are its members."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Repository will be created at '${SVNREPOS}' with group '${SVNGROUP}'."
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
	@${ECHO_MSG} "Many useful scripts will be installed into ${DATADIR}}"

pre-configure:
	@if [ ! -x ${APR_APU_DIR}/${APR_CONFIG} -o ! -x ${APR_APU_DIR}/${APU_CONFIG} ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You selected to use`'"${APR_PORT}' for apr library." ; \
		${ECHO_MSG} 'It seems that `'"${APR_PORT}' is not properly installed." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.if !defined(WITHOUT_BDB)
	@if [ `${APR_APU_DIR}/${APU_CONFIG} --db-version` != "4" ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You should build `'"${APR_PORT}' with db4 support to use subversion with it." ; \
		${ECHO_MSG} 'Please rebuild `'"${APR_PORT}' with option "'`'"${OPT_NAME}' and try again." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Or you can disable db4 support. Only 'fs' repository backend will be available." ; \
		${ECHO_MSG} "To disable db4 support, define WITHOUT_BDB." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.endif

.if defined(WITH_MOD_DAV_SVN)
pre-install:
	${APXS} -e -S LIBEXECDIR=${PREFIX}/${APACHEMODDIR} -a -n dav ${PREFIX}/${APACHEMODDIR}/mod_dav.so
.endif

post-install:	${MKREPOS_TARGET}
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
.endif
	@${MKDIR} ${SVNREPOS}
	@${PREFIX}/bin/svnadmin create --fs-type ${SVNFSTYPE} ${SVNREPOS}
.if defined(WITH_SVNSERVE_WRAPPER)
	@${CHGRP} ${SVNGROUP} ${SVNGRPFILES}
	@${CHMOD} g+w ${SVNGRPFILES}
	@for i in ${SVNREPOS}/db/* ; do \
	    i=$${i##*/}; \
	    case $$i in \
	    DB_CONFIG|fs-type|uuid) ;; \
	    *) ${CHGRP} -R ${SVNGROUP} ${SVNREPOS}/db/$$i; \
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
