# Created by: rooneg@electricjellyfish.net
# $FreeBSD$

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Version control system

_CONFLICTS_INSTALL=	subversion-1.[^8].[0-9]* \
			subversion1[^8]-1.[^8].[0-9]*

USE_RC_SUBR=	svnserve

PORTDOCS=	BUGS CHANGES COMMITTERS INSTALL README

OPTIONS_DEFINE=	\
		BDB		\
		DOCS		\
		FREEBSD_TEMPLATE\
		GNOME_KEYRING	\
		KDE_KWALLET	\
		MAINTAINER_DEBUG\
		MOD_DAV_SVN	\
		NLS		\
		P4_STYLE_MARKERS\
		SASL		\
		SERF		\
		STATIC		\
		SVNSERVE_WRAPPER\
		TEST		\
		TOOLS

OPTIONS_DEFAULT=P4_STYLE_MARKERS \
		FREEBSD_TEMPLATE \
		SERF

FREEBSD_TEMPLATE_DESC=	FreeBSD Project log template
GNOME_KEYRING_DESC=	Build with GNOME Keyring auth support
KDE_KWALLET_DESC=	Build with KDE KWallet auth support
MAINTAINER_DEBUG_DESC=	Build debug version
MOD_DAV_SVN_DESC=	mod_dav_svn module for Apache 2.X
P4_STYLE_MARKERS_DESC=	Perforce-style conflict markers
SERF_DESC=		WebDAV/Delta-V (HTTP/HTTPS) repo access module
STATIC_DESC=		Build static version (no shared libs)
SVNSERVE_WRAPPER_DESC=	Enable svnserve wrapper (umask setter)
TEST_DESC=		Run subversion test suite
TOOLS_DESC=		Install several tools (svnauthz-validate and mod_dontdothat are among them)

# Patches required for use with the FreeBSD Project repository only
P4_STYLE_MARKERS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-3way-conflict-markers
FREEBSD_TEMPLATE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-fbsd-template
SVNSERVE_WRAPPER_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-svnserve-wrapper

.include "Makefile.common"

SVNREPOS?=	/home/svn/repos
SVNFSTYPE?=	fsfs

SUB_FILES=	pkg-install

.if !${PORT_OPTIONS:MMAINTAINER_DEBUG}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in
.endif

.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
SUB_LIST+=	SVNSERVE_BIN_EXT=".bin"
.else
SUB_LIST+=	SVNSERVE_BIN_EXT=""
.endif

.if ${PORT_OPTIONS:MMOD_DAV_SVN}
SUB_LIST+=	MOD_DAV_SVN_INSTALL="YES"
PLIST_SUB+=	SED=${SED}
SVNGROUP?=	www
SVNUSER?=	www
.else
SUB_LIST+=	MOD_DAV_SVN_INSTALL="NO"
SVNGROUP?=	svn
SVNUSER?=	svn
.endif

.if ${PORT_OPTIONS:MTEST}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSTATIC}
.  if ${PORT_OPTIONS:MNLS}
USES+=			gettext:build
.  endif
.  if ${PORT_OPTIONS:MBDB}
BDB_BUILD_DEPENDS=	yes
.  endif
OLD_LIB_DEPENDS:=	${LIB_DEPENDS:S!^!${LOCALBASE}/lib/!:C!(\.so|\.[0-9]+)?:!.a:!}
BUILD_DEPENDS+=		${OLD_LIB_DEPENDS}
LIB_DEPENDS=
PLIST_SUB+=		DYNAMIC_ENABLED="@comment "
.else
PLIST_SUB+=		DYNAMIC_ENABLED=""
.endif

.if make(repository)
WITH_REPOSITORY_CREATION=	yes
.endif

.if defined(WITH_REPOSITORY_CREATION)
MKREPOS_TARGET=	_mkrepos
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
.if ${PORT_OPTIONS:MSTATIC}
.  if ${PORT_OPTIONS:MMOD_DAV_SVN}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! mod_dav_svn and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.  endif
.  if ${PORT_OPTIONS:MGNOME_KEYRING}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! Gnome Keyring and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.  endif
.  if ${PORT_OPTIONS:MKDE_WALLET}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!! KDE Wallet and static build are not compatible !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${FALSE}
.  endif
	@${ECHO_MSG} "Static binaries will be built."
.endif # STATIC
	@${ECHO_MSG} "Many useful scripts will be installed into ${DATADIR}"

pre-configure:
.if ${PORT_OPTIONS:MBDB}
	@BDB_VERSION=`${APR_APU_DIR}/${APU_CONFIG} --db-version`; \
	if [ "$${BDB_VERSION}" != "4" -a "$${BDB_VERSION}" != "5" ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You should build `'"devel/apr1' with Berkeley DB (4 or 5) support to use subversion with it." ; \
		${ECHO_MSG} 'Please rebuild `'"devel/apr1' with option "'`'"${OPT_NAME}' and try again." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Or you can disable Berkeley DB support. Only 'fs' repository backend will be available." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.endif
.if ${PORT_OPTIONS:MSTATIC}
	@if ${GREP} -q icui18n ${LOCALBASE}/lib/libsqlite3.la ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "You can not build static subversion if your SQLite3 is built with ICU enabled."; \
		${ECHO_MSG} "Please, reinstall 'devel/sqlite3' port with disabled ICU support."; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
.endif

post-configure:
# ugly hack: save tools directory so we don't have to cleanup before installing
	@${CP} -R ${WRKSRC}/tools ${WRKSRC}/tools.examples
	@${CHMOD} -R a-st,o+rX ${WRKSRC}/tools.examples

# takes a long time, and will fail but gives maintainer a good oversight
.if ${PORT_OPTIONS:MTEST}
test: build
	-@make check -C ${WRKSRC}
.endif

post-build:
.if ${PORT_OPTIONS:MTOOLS}
	@${MAKE} -C ${WRKSRC} tools ${MAKE_ARGS}
.endif

post-install:	${MKREPOS_TARGET}
.if ${PORT_OPTIONS:MTOOLS}
	@${MAKE} -C ${WRKSRC} install-tools ${MAKE_ARGS}
.endif
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/tools.examples && ${TAR} --exclude '*.in' -cf - * | ${TAR} -C ${STAGEDIR}${DATADIR} -xof - )

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.if ${PORT_OPTIONS:MSVNSERVE_WRAPPER}
	@${INSTALL_SCRIPT} ${FILESDIR}/svnserve.wrapper ${STAGEDIR}${PREFIX}/bin/svnserve
.endif

# ===============================================================================
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
