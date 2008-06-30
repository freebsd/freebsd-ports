# New ports collection makefile for:	subversion-devel
# Date created:				29 May 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	subversion
DISTVERSION=	1.5.0
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/downloads/
PKGNAMESUFFIX?=	-devel
DIST_SUBDIR=	subversion

MAINTAINER=	lev@freebsd.org
COMMENT?=	Prerelease version of the Subversion version control system

NO_PACKAGE=	No binary packages of release candidates

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS?=	subversion-[0-9]* subversion-freebsd-[0-9]*

USE_LDCONFIG=	yes

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-ssl
WANT_PERL=	yes

USE_RC_SUBR=	svnserve

MAN1=		svn.1 svnadmin.1 svnlook.1 svndumpfilter.1 svnsync.1 svnversion.1
MAN5=		svnserve.conf.5
MAN8=		svnserve.8

TXT_DOCS=	BUGS CHANGES COMMITTERS COPYING HACKING INSTALL README

OPTIONS=	NEON	"WebDAV/Delta-V repo access via libneon" on \
		SERF	"Experimental WebDAV/Delta-V via libserf" off \
		ASVN		"Build and install Archive SVN (asvn)" off \
		PERL		"Perl bindings" off \
		PYTHON		"Python bindings" off \
		RUBY		"Ruby bindings" off \
		JAVA		"Java (JavaHL) bindings" off \
		BDB		"db4 repository backend" off \
		MOD_DAV_SVN	"mod_dav_svn module for Apache 2.X" off \
		APACHE2_APR	"Use APR from Apache 2.X" off \
		SVNSERVE_WRAPPER	"Enable svnserve wrapper" off \
		MAINTAINER_DEBUG	"Build debug version" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		WITHOUT_GETTEXT=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		WITHOUT_GETTEXT="@comment "
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fpic -DPIC
.endif

SVNREPOS?=	/home/svn/repos
SVNFSTYPE?=	fsfs

.if make(repository)
WITH_REPOSITORY_CREATION=	yes
.endif

.if defined(WITH_REPOSITORY_CREATION)
MKREPOS_TARGET=	_mkrepos
.endif

.if defined(WITH_MAINTAINER_DEBUG)
CONFIGURE_ARGS+=--enable-maintainer-mode \
		--enable-debug
CFLAGS+=	-g
.endif

.if defined(WITH_NEON)
LIB_DEPENDS+=		neon.26:${PORTSDIR}/www/neon26
CONFIGURE_ARGS+=	--with-neon=${LOCALBASE}
PLIST_SUB+=		NEON="" SERF="@comment "
.elif defined(WITH_SERF)
LIB_DEPENDS+=		serf-0.0:${PORTSDIR}/www/serf
CONFIGURE_ARGS+=	--with-serf=${LOCALBASE} --without-neon
PLIST_SUB+=		NEON="@comment " SERF=""
.endif

.if defined(WITHOUT_BDB)
CONFIGURE_ARGS+=	--without-berkeley-db
PLIST_SUB+=		WITHOUT_BDB="@comment "
.else
PLIST_SUB+=		WITHOUT_BDB=""
.endif

.if defined(WITH_PERL)
USE_PERL5=		5.8.0+
SWIG_BINDINGS+=		yes
PLIST_SUB+=		WITH_PERL=""
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=			SVN::Base.3 \
			SVN::Client.3 \
			SVN::Core.3 \
			SVN::Delta.3 \
			SVN::Fs.3 \
			SVN::Ra.3 \
			SVN::Repos.3 \
			SVN::Wc.3
.else
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
SWIG_BINDINGS+=		yes
PLIST_SUB+=		WITH_PYTHON=""
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
USE_RUBY=		yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
SWIG_BINDINGS+=		yes
PLIST_SUB+=		WITH_RUBY=""
.else
PLIST_SUB+=		WITH_RUBY="@comment "
.endif

.if defined(WITH_JAVA)
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
JAVA_BUILD=	yes
JAVA_RUN=	yes
.include "${PORTSDIR}/Mk/bsd.java.mk"
CONFIGURE_ARGS+=	--enable-javahl --with-jdk=${JAVA_HOME}
PLIST_SUB+=		WITH_JAVA=""
.else
PLIST_SUB+=		WITH_JAVA="@comment "
.endif

.if defined(WITH_JAVA) && ${OSVERSION} < 503000
BROKEN="Java bindings are supported only on FreeBSD 5.3 or newer"
.endif

.if !defined(SWIG_BINDINGS)
CONFIGURE_ARGS+=	--without-swig
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
.if !defined(WITHOUT_BDB)
DEPENDS_ARGS+=	WITH_BERKELEYDB=db4
OPT_NAME=	WITH_BERKELEYDB=(db4|db41|db42)
.endif
.else
APR_APU_DIR=	${LOCALBASE}/bin
APR_CONFIG=	apr-1-config
APU_CONFIG=	apu-1-config
.if !defined(WITHOUT_BDB)
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

post-extract:
	@${RM} -rf ${WRKSRC}/neon
	@${RM} -rf ${WRKSRC}/apr
	@${RM} -rf ${WRKSRC}/apr-util

post-patch:
.if ${PREFIX} != "/usr"
	@${REINPLACE_CMD} "s#/etc/subversion#${ETCDIR}#g" ${WRKSRC}/subversion/libsvn_subr/config_file.c
	@${REINPLACE_CMD} "s#/etc/subversion#${ETCDIR}#g" ${WRKSRC}/subversion/libsvn_subr/config_impl.h
.endif
	@${REINPLACE_CMD} "s#^swig_pydir =.*#swig_pydir = ${PYTHON_SITELIBDIR}/libsvn#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} "s#^swig_pydir_extra =.*#swig_pydir_extra = ${PYTHON_SITELIBDIR}/svn#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} "s#^LIBTOOL =.*#LIBTOOL = ${LIBTOOL}#" ${WRKSRC}/Makefile.in

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

post-build:
.if defined(WITH_PERL)
	cd ${WRKSRC} ; \
	  ${MAKE} swig-pl
.endif
.if defined(WITH_PYTHON)
	cd ${WRKSRC} ; \
	  ${MAKE} swig-py
.endif
.if defined(WITH_RUBY)
	cd ${WRKSRC} ; \
	  ${MAKE} swig-rb
.endif
.if defined(WITH_JAVA)
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes
	cd ${WRKSRC} ; \
	  ${MAKE} javahl
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
.if defined(WITH_PERL)
	cd ${WRKSRC} ; \
	${REINPLACE_CMD} '/SWIG_PL_DIR/s, install$$, all pure_install,g' ${WRKSRC}/Makefile ; \
	  ${MAKE} install-swig-pl
.endif
.if defined(WITH_PYTHON)
	cd ${WRKSRC} ; \
	  ${MAKE} install-swig-py
.endif
.if defined(WITH_RUBY)
	cd ${WRKSRC} ; \
	  ${MAKE} install-swig-rb
.endif
.if defined(WITH_JAVA)
	cd ${WRKSRC} ; \
	  ${MAKE} install-javahl
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

.include <bsd.port.post.mk>
