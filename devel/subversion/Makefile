# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/tarballs/

MAINTAINER=	lev@freebsd.org
COMMENT=	Version control system

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-ssl

MAN1=		svn.1 svnadmin.1 svnlook.1 svndumpfilter.1 svnversion.1
MAN5=		svnserve.conf.5
MAN8=		svnserve.8
MANCOMPRESSED=	no

TXT_DOCS=	BUGS CHANGES COMMITTERS COPYING HACKING INSTALL README
.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS}
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		WITHOUT_GETTEXT=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		WITHOUT_GETTEXT="@comment "
.endif

.include <bsd.port.pre.mk>

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

.if !defined(WITHOUT_NEON)
LIB_DEPENDS+=	neon.24:${PORTSDIR}/www/neon
CONFIGURE_ARGS+=	--with-neon=${LOCALBASE}
PLIST_SUB+=		WITHOUT_NEON=""
.else
CONFIGURE_ARGS+=	--without-neon
PLIST_SUB+=		WITHOUT_NEON="@comment "
.endif

.if defined(WITHOUT_BDB)
CONFIGURE_ARGS+=	--without-berkeley-db
PLIST_SUB+=		WITHOUT_BDB="@comment "
.else
PLIST_SUB+=		WITHOUT_BDB=""
.endif

.if defined(WITH_PERL)
.if ${PERL_LEVEL} < 500800
IGNORE=	"Subversion\'s Perl bindings need perl 5.8.0 or greater. Upgrade your perl and try again"
.endif
SWIG_BINDINGS+=		perl
DEPENDS_ARGS+=		WANT_SWIG_PERL=yes
USE_PERL5=		yes
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
SWIG_BINDINGS+=		python
DEPENDS_ARGS+=		WANT_SWIG_PYTHON=yes
PLIST_SUB+=		WITH_PYTHON=""
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

#.if defined(WITH_JAVA)
#USE_JAVA=	yes
#JAVA_VERSION=	1.2+
#JAVA_OS=	native
#JAVA_BUILD=	yes
#JAVA_RUN=	yes
#.include "${PORTSDIR}/Mk/bsd.java.mk"
#CONFIGURE_ARGS+=	--enable-javahl --with-jdk=${JAVA_HOME} 
#PLIST_SUB+=		WITH_JAVA=""
#.else
#PLIST_SUB+=		WITH_JAVA="@comment "
#.endif

.if defined(SWIG_BINDINGS) && ${SWIG_BINDINGS} != ""
BUILD_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
DEPENDS_ARGS+=		SWIG_LANGUAGES=""
CONFIGURE_ARGS+=	--with-swig=${LOCALBASE} \
			--enable-swig-bindings=${SWIG_BINDINGS:Q:S/ /,/g:S/\\//g}
.else
CONFIGURE_ARGS+=	--without-swig --disable-swig-bindings
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
APACHE2_PORT?=	www/apache2
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE2_PORT}
RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE2_PORT}
APR_APU_DIR=	${LOCALBASE}/lib/apache2
APR_CONFIG=	apr-config
APU_CONFIG=	apu-config
APR_PORT=	www/apache2
.if !defined(WITHOUT_BDB)
DEPENDS_ARGS+=	WITH_BERKELEYDB=db4
OPT_NAME=	WITH_BERKELEYDB=(db4|db41|db42)
.endif
.else
APR_APU_DIR=	${LOCALBASE}/bin
APR_CONFIG=	apr-1-config
APU_CONFIG=	apu-1-config
.if !defined(WITHOUT_BDB)
LIB_DEPENDS+=	apr-1.0:${PORTSDIR}/devel/apr-svn
APR_PORT=	devel/apr-svn
OPT_NAME=	APR_UTIL_WITH_BERKELEY_DB=yes
.else
LIB_DEPENDS+=	apr-1.0:${PORTSDIR}/devel/apr
APR_PORT=	devel/apr
.endif
.endif
CONFIGURE_ARGS+=--with-apr=${APR_APU_DIR}/${APR_CONFIG} \
		--with-apr-util=${APR_APU_DIR}/${APU_CONFIG}

.if defined(WITH_SVNSERVE_WRAPPER)
PLIST_SUB+=	SVNSERVE_WRAPPER=""
EXTRA_PATCHES=	${PATCHDIR}/build-outputs.mk.patch
.else
PLIST_SUB+=	SVNSERVE_WRAPPER="@comment "
.endif

.if !defined(NOPORTDOCS) && defined(WITH_BOOK)
PORTDOCS+=	book
.endif

SCRIPTS=

SCRIPTS_DATA=

pre-extract:
	@${ECHO_MSG} ""
.if defined(WITHOUT_NEON)
	@${ECHO_MSG} "WebDAV/Delta-V repository access module disabled."
.else
	@${ECHO_MSG} "WebDAV/Delta-V repository access module enabled."
	@${ECHO_MSG} "To disable it define WITHOUT_NEON"
.endif
	@${ECHO_MSG} ""
.if defined(WITHOUT_BDB)
	@${ECHO_MSG} "db4 repository backend disabled."
.else
	@${ECHO_MSG} "db4 repository backend enabled."
	@${ECHO_MSG} "To disable it define WITHOUT_BDB"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_MAINTAINER_DEBUG)
	@${ECHO_MSG} "Build debug version."
.else
	@${ECHO_MSG} "You can enable debug build by defining WITH_MAINTAINER_DEBUG."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_PERL)
	@${ECHO_MSG} "Build with perl bindings."
	@${ECHO_MSG} "Be sure, that apr library and perl both uses OR not uses threads in same time."
.else
	@${ECHO_MSG} "You can enable perl bindings by defining WITH_PERL"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_PYTHON)
	@${ECHO_MSG} "Build with Python bindings."
.else
	@${ECHO_MSG} "You can enable Python bindings by defining WITH_PYTHON."
.endif
	@${ECHO_MSG} ""
#.if defined(WITH_JAVA)
#	@${ECHO_MSG} "Build with Java (JavaHL) bindings."
#.else
#	@${ECHO_MSG} "You can enable Java bindings by defining WITH_JAVA."
#	@${ECHO_MSG} "You should have apr builded with threads for Java support!"
#.endif
#	@${ECHO_MSG} ""
.if defined(WITH_MOD_DAV_SVN)
	@${ECHO_MSG} "mod_dav_svn module for Apache 2.X enabled."
.else
	@${ECHO_MSG} "You can enable the mod_dav_svn module for Apache 2.X"
	@${ECHO_MSG} "by defining WITH_MOD_DAV_SVN.  This option implies"
	@${ECHO_MSG} "the WITH_APACHE2_APR option."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_APACHE2_APR)
	@${ECHO_MSG} "Using APR from www/apache2.  If you have the devel/apr"
	@${ECHO_MSG} "port/package installed, you may need to remove it."
.else
	@${ECHO_MSG} "You can link subversion against the APR built with"
	@${ECHO_MSG} "the www/apache2 port, rather than the devel/apr port,"
	@${ECHO_MSG} "by defining WITH_APACHE2_APR."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_SVNSERVE_WRAPPER)
	@${ECHO_MSG} "svnserve wrapper enabled."
.else
	@${ECHO_MSG} "You can install the svnserve wrapper (sets umask 002)"
	@${ECHO_MSG} "by defining WITH_SVNSERVE_WRAPPER."
.endif
	@${ECHO_MSG} ""
.if defined(WITH_REPOSITORY_CREATION)
	@${ECHO_MSG} "I will create (or use, if it exists) \"${SVNGROUP}\" group."
	@${ECHO_MSG} "Make sure that all committers are its members."
.else
	@${ECHO_MSG} "You can have the repository created for you by defining"
	@${ECHO_MSG} "WITH_REPOSITORY_CREATION."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Make sure that:"
	@${ECHO_MSG} "* all your svn users are members of a common group"
	@${ECHO_MSG} "* this group is the group id of the db/ and locks/"
	@${ECHO_MSG} "  subdirectories of your repository"
	@${ECHO_MSG} "* the above subdirectories are writable by this group"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Repository will be created at '${SVNREPOS}' with group '${SVNGROUP}'."
	@${ECHO_MSG} "Type of repository will be '${SVNFSTYPE}'."
	@${ECHO_MSG} "You could change these settings by defining SVNREPOS, SVNGROUP nad SVNFSTYPE"
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} ""
.if !defined(NOPORTDOCS) && defined(WITH_BOOK)
	@${ECHO_MSG} "Subversion Book will be installed."
.else
	@${ECHO_MSG} "You can install the Subversion Book by defining WITH_BOOK."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "May useful scripts will be installed into ${PREFIX}/share/subversion"

post-extract:
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

post-patch:
.if ${PREFIX} != "/usr"
	@${REINPLACE_CMD} "s#/etc/subversion#${PREFIX}/etc/subversion#g" ${WRKSRC}/subversion/libsvn_subr/config_file.c
	@${REINPLACE_CMD} "s#/etc/subversion#${PREFIX}/etc/subversion#g" ${WRKSRC}/subversion/libsvn_subr/config_impl.h
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
		${ECHO_MSG} "Or you can disable db4 support. Only 'fs' repository backend will be availible." ; \
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
#.if defined(WITH_JAVA)
#	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes
#	cd ${WRKSRC} ; \
#	  ${MAKE} javahl
#.endif

.if defined(WITH_MOD_DAV_SVN)
pre-install:
	${APXS} -e -S LIBEXECDIR=${PREFIX}/libexec/apache2 -a -n dav libexec/apache2/mod_dav.so
.endif

post-install:	${MKREPOS_TARGET}
	@${MKDIR} ${PREFIX}/share/subversion
	cd ${WRKSRC}/tools ; \
	  tar --exclude '*.in' -cf - * | tar -C ${PREFIX}/share/subversion -xf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.if defined(WITH_BOOK)
	@${MKDIR} ${DOCSDIR}/book/images
	cd ${WRKSRC}/doc/book/book ; \
	  ${INSTALL_DATA} svn-book.html svn-book.pdf ${DOCSDIR}/book
	cd ${WRKSRC}/doc/book/book/images ; \
	  ${INSTALL_DATA} *.png ${DOCSDIR}/book/images
.endif
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
#.if defined(WITH_JAVA)
#	cd ${WRKSRC} ; \
#	  ${MAKE} install-javahl
#.endif
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
