# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/tarballs/

MAINTAINER=	lev@freebsd.org
COMMENT=	Version control system

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes

USE_SIZE=	yes
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

.include <bsd.port.pre.mk>

SVNREPOS?=	/home/svn/repos

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

.if defined(WITH_PERL)
.if ${PERL_LEVEL} < 500800
IGNORE=	"Subversion\'s Perl bindings need perl 5.8.0 or greater. Upgrade your perl and try again"
.endif
SWIG_BINDINGS+=		perl
USE_PERL5=		yes
PLIST_SUB+=		WITH_PERL=""
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=			SVN::Base.3 \
			SVN::Client.3 \
			SVN::Core.3 \
			SVN::Delta.3 \
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
PLIST_SUB+=		WITH_PYTHON=""
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(SWIG_BINDINGS) && ${SWIG_BINDINGS} != ""
BUILD_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
DEPENDS_ARGS+=		SWIG_LANGUAGES='${SWIG_BINDINGS}'
CONFIGURE_ARGS+=	--with-swig=${LOCALBASE} \
			--enable-swig-bindings=${SWIG_BINDINGS:Q:S/ /,/g:S/\\//g}
.else
CONFIGURE_ARGS+=	--with-swig=no
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
DEPENDS_ARGS+=	WITH_BERKELEYDB=db4
CONFIGURE_ARGS+=--with-apr=${LOCALBASE}/lib/apache2/apr-config \
		--with-apr-util=${LOCALBASE}/lib/apache2/apu-config
APR_APU_DIR=	${LOCALBASE}/lib/apache2
APR_PORT=	www/apache2
OPT_NAME=	WITH_BERKELEYDB=(db4|db41|db42)
.else
LIB_DEPENDS+=	apr-0.9:${PORTSDIR}/devel/apr-svn
CONFIGURE_ARGS+=--with-apr=${LOCALBASE} \
		--with-apr-util=${LOCALBASE}
APR_APU_DIR=	${LOCALBASE}/bin
APR_PORT=	devel/apr
OPT_NAME=	APR_UTIL_WITH_BERKELEY_DB=yes
.endif

.if defined(WITH_SVNSERVE_WRAPPER)
PLIST_SUB+=	SVNSERVE_WRAPPER=""
EXTRA_PATCHES=	${PATCHDIR}/build-outputs.mk.patch
.else
PLIST_SUB+=	SVNSERVE_WRAPPER="@comment "
.endif

.if defined(WITH_BOOK_HTML)
PORTDOCS+=	book
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

pre-extract:
	@${ECHO_MSG} ""
.if defined(WITHOUT_NEON)
	@${ECHO_MSG} "WebDAV/Delta-V repository access module disabled."
.else
	@${ECHO_MSG} "WebDAV/Delta-V repository access module enabled."
	@${ECHO_MSG} "To disable it define WITHOUT_NEON"
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
	@${ECHO_MSG} "Repository will be created at '${SVNREPOS}' with group '${SVNGROUP}'"
	@${ECHO_MSG} "You could change these settings by defining SVNREPOS and SVNGROUP"
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} ""
.if defined(WITH_BOOK_HTML)
	@${ECHO_MSG} "Subversion Book (HTML) enabled."
.else
	@${ECHO_MSG} "You can install the Subversion Book (HTML) by defining"
	@${ECHO_MSG} "WITH_BOOK_HTML."
.endif
	@${ECHO_MSG} ""

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
	@if [ ! -x ${APR_APU_DIR}/apr-config -o ! -x ${APR_APU_DIR}/apu-config ] ; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} 'You select to use`'"${APR_PORT}' for apr library." ; \
		${ECHO_MSG} 'It seems that `'"${APR_PORT}' is not properly installed." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi
	@if [ `${APR_APU_DIR}/apu-config --db-version` != "4" ] ; then \
		${ECHO_MSG} "" ; \
 		${ECHO_MSG} 'You should build `'"${APR_PORT}' with db4 support to use subversion with it." ; \
 		${ECHO_MSG} 'Please, rebuild `'"${APR_PORT}' with option "'`'"${OPT_NAME}' and try again." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi

post-build:
.if defined(WITH_PERL)
	cd ${WRKSRC} ; \
	  ${MAKE} swig-pl-lib
	cd ${WRKSRC}/subversion/bindings/swig/perl ; \
	  ${SETENV} APR_CONFIG="${APR_APU_DIR}/apr-config" APU_CONFIG="${APR_APU_DIR}/apu-config" \
	    CCFLAGS="${CCFLAGS}" CC="${CC}" \
	    ${PERL} Makefile.PL PREFIX="${PREFIX}" \
	    INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib" ; \
	  ${MAKE} all
.endif
.if defined(WITH_PYTHON)
	cd ${WRKSRC} ; \
	  ${MAKE} swig-py
.endif
.if defined(WITH_BOOK_HTML)
	cd ${WRKSRC}/doc/book/tools/ ; \
	  ${LN} -s ${PREFIX}/share/xsl/docbook xsl
	cd ${WRKSRC}/doc/book ; \
	  ${MAKE} all-html
.endif

.if defined(WITH_MOD_DAV_SVN)
pre-install:
	${APXS} -e -S LIBEXECDIR=${PREFIX}/libexec/apache2 -a -n dav libexec/apache2/mod_dav.so
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.if defined(WITH_BOOK_HTML)
	cd ${WRKSRC}/doc/book ; \
	  ${MAKE} install-book-html install-book-html-chunk INSTALL_DIR=${DOCSDIR}
.endif
.endif
.if defined(WITH_PERL)
	cd ${WRKSRC} ; \
	  ${MAKE} install-swig-pl-lib
	cd ${WRKSRC}/subversion/bindings/swig/perl ; \
	  ${MAKE} install
.endif
.if defined(WITH_PYTHON)
	cd ${WRKSRC} ; \
	  ${MAKE} install-swig-py
.endif
.if defined(WITH_SVNSERVE_WRAPPER)
	@${INSTALL_SCRIPT} ${FILESDIR}/svnserve.wrapper ${PREFIX}/bin/svnserve
.endif
.if defined(WITH_REPOSITORY_CREATION) && !exists(${SVNREPOS})
. if defined(WITH_SVNSERVE_WRAPPER)
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
. endif
	@${MKDIR} ${SVNREPOS}
	@${PREFIX}/bin/svnadmin create ${SVNREPOS}
	@${CHGRP} ${SVNGROUP} ${SVNREPOS}/db ${SVNREPOS}/locks/db.lock ${SVNREPOS}/dav
	@${CHMOD} g+w ${SVNREPOS}/db ${SVNREPOS}/locks/db.lock ${SVNREPOS}/dav
	@for i in ${SVNREPOS}/db/* ; do \
	    i=$${i##*/}; \
	    case $$i in \
	    DB_CONFIG) ;; \
	    *) ${CHGRP} ${SVNGROUP} ${SVNREPOS}/db/$$i; \
	       ${CHMOD} g+w ${SVNREPOS}/db/$$i; \
	       ;; \
	    esac; \
	done
.endif

post-deinstall:
.if defined(WITH_MOD_DAV_SVN)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL
.endif

.include <bsd.port.post.mk>
