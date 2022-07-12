# Created by: Eric Anholt

PORTNAME=	git
DISTVERSION=	2.37.1
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/software/scm/git
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${DISTVERSION}${EXTRACT_SUFX}
# We manually extract the htmldocs.
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${DISTVERSION}${EXTRACT_SUFX}

# these patches are required for gitlab (gitaly)
# without the patches repositories got broken
PATCH_SITES=	https://gitlab.com/gitlab-org/gitaly/-/raw/master/_support/git-patches/v2.36.0.gl1/
PATCHFILES=	0001-refs-extract-packed_refs_delete_refs-to-allow-contro.patch \
		0002-refs-allow-passing-flags-when-beginning-transactions.patch \
		0003-refs-allow-skipping-the-reference-transaction-hook.patch \
		0004-refs-demonstrate-excessive-execution-of-the-referenc.patch \
		0005-refs-do-not-execute-reference-transaction-hook-on-pa.patch \
		0006-refs-skip-hooks-when-deleting-uncovered-packed-refs.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	garga@FreeBSD.org
COMMENT?=	Distributed source code management tool ${COMMENT_${FLAVOR}}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

SUBPORT?=	core

.if ${SUBPORT} != core
PKGNAMESUFFIX=	-${SUBPORT}
.endif

.if ${SUBPORT} == core
FLAVORS=	default lite tiny
default_CONFLICTS_INSTALL=	git-lite git-tiny
lite_CONFLICTS_INSTALL=		git git-tiny
lite_DESCR=			${.CURDIR}/pkg-descr-lite
lite_PKGNAMESUFFIX=		-lite
tiny_CONFLICTS_INSTALL=		git git-lite
tiny_DESCR=			${.CURDIR}/pkg-descr-tiny
tiny_PKGNAMESUFFIX=		-tiny
.endif

USES=		autoreconf cpe gmake iconv shebangfix tar:xz
CPE_VENDOR=	git-scm

.if ${SUBPORT} == core
USES+=		ssl
COMMENT_lite=	(lite flavor)
COMMENT_tiny=	(tiny flavor)

USERS=		git_daemon
GROUPS=		git_daemon
.endif

SUB_FILES=	pkg-message gitweb.conf

GNU_CONFIGURE=	yes
CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	DEVELOPER= NO_TCLTK=yes
MAKE_ENV+=	V=1
.if ${SUBPORT} == core
USE_RC_SUBR=	git_daemon
.endif
SHEBANG_FILES=	*.perl */*.perl */*/*.perl */*.pl */*/*.pl */*/*/*.pl \
		t/*/*/pre t/*/*/post t/Git-SVN/Utils/*.t \
		git-p4.py \
		contrib/hg-to-git/hg-to-git.py \
		contrib/hooks/update-paranoid \
		contrib/fast-import/import-zips.py \
		contrib/remote-helpers/git-remote-bzr \
		contrib/remote-helpers/git-remote-hg \
		contrib/credential/netrc/git-credential-netrc.perl \
		contrib/buildsystems/generate contrib/contacts/git-contacts \
		templates/hooks--fsmonitor-watchman.sample
TEST_TARGET=	test

CONFIGURE_ARGS=	--enable-pthreads=-pthread ac_cv_header_libcharset_h=no

.if ${SUBPORT} == core

OPTIONS_DEFINE=	CONTRIB CURL GITWEB HTMLDOCS ICONV NLS PCRE2 PERL SEND_EMAIL \
		SUBTREE
OPTIONS_DEFAULT=CONTRIB CURL GITWEB ICONV PCRE2 PERL SEND_EMAIL SUBTREE

. if ${FLAVOR:U} == lite
OPTIONS_EXCLUDE+=	GITWEB CONTRIB PERL
. elif ${FLAVOR:U} == tiny
OPTIONS_EXCLUDE:=	${OPTIONS_DEFINE:NCURL}
OPTIONS_SLAVE=		CURL
. endif

OPTIONS_SUB=	yes

. if !empty(FLAVOR) && ${FLAVOR:U} != default
OPTIONS_FILE=		${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options
. endif

CONTRIB_DESC=	Install contributed scripts
CURL_DESC=	Install curl support (provides HTTPS transport)
GITWEB_DESC=	Install gitweb
HTMLDOCS_DESC=	Install additional documentation
PCRE2_DESC=	Use Perl Compatible Regular Expressions (v2)
SEND_EMAIL_DESC=Enable the git-send-email(1) script
SUBTREE_DESC=	Install git-subtree

NLS_USES=		gettext
NLS_MAKE_ARGS_OFF=	NO_GETTEXT=yes

PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl=${PERL}
PERL_BUILD_DEPENDS=	p5-Error>=0:lang/p5-Error
PERL_RUN_DEPENDS=	p5-Error>=0:lang/p5-Error
PERL_MAKE_ARGS_OFF=	NO_PERL=1

GITWEB_IMPLIES=		PERL
GITWEB_RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI

PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=	libpcre

SEND_EMAIL_IMPLIES=	PERL
SEND_EMAIL_RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
			p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

ICONV_MAKE_ARGS_OFF=	NO_ICONV=1

CURL_MAKE_ENV=		CURLDIR=${LOCALBASE}
CURL_BUILD_DEPENDS=	curl:ftp/curl
CURL_RUN_DEPENDS=	curl:ftp/curl
CURL_LIB_DEPENDS=	libexpat.so:textproc/expat2
CURL_MAKE_ARGS_OFF=	NO_CURL=1 NO_EXPAT=1

HTMLDOCS_DISTFILES=	${PORTNAME}-htmldocs-${DISTVERSION}${EXTRACT_SUFX}

SUBTREE_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor\
			xmlto:textproc/xmlto

.else

NO_ARCH=	yes
MAKE_ENV+=	V=1
MAKE_ARGS=	NO_GETTEXT=yes
. if ${SUBPORT} != gui
MAKE_ARGS+=	NO_TCLTK=yes
. endif

RUN_DEPENDS+=	git=${PKGVERSION}:devel/git

. if ${SUBPORT} == cvs
RUN_DEPENDS+=	cvsps:devel/cvsps
. elif ${SUBPORT} == gui
USES+=		tk
MAKE_ARGS+=	TCL_PATH=${TCLSH} TCLTK_PATH=${WISH}
. elif ${SUBPORT} == svn
RUN_DEPENDS+=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
.  if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	p5-subversion-lts>=0:devel/p5-subversion
.  else
RUN_DEPENDS+=	p5-subversion>=0:devel/p5-subversion
.  endif
. endif
.endif

.include <bsd.port.options.mk>

# This is intentionally not exposed as an option.
.if defined(STRIP) && ${STRIP} != ""
ALL_TARGET=	all strip
.endif

.if ${SUBPORT} == p4 || ${PORT_OPTIONS:MCONTRIB}
USES+=		python
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if ${SUBPORT} != gui
RMMAN1+=	git-citool.1 \
		git-gui.1 \
		gitk.1
.endif

.if ${SUBPORT} != p4
RMMAN1+=	git-p4.1
.endif

.if ${SUBPORT} != svn
RMMAN1+=	git-svn.1
.endif

.if ${SUBPORT} != cvs
RMMAN1+=	git-cvsimport.1 \
		git-cvsexportcommit.1 \
		git-cvsserver.1
RMMAN7+=	gitcvs-migration.7
.endif

post-extract-HTMLDOCS-on:
	@${MKDIR} ${WRKDIR}/htmldocs
	@cd ${WRKDIR}/htmldocs && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${PORTNAME}-htmldocs-${DISTVERSION}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS}

post-patch:
.for FILE in ${RMMAN1}
	@${RM} ${WRKDIR}/man1/${FILE}
.endfor
.for FILE in ${RMMAN7}
	@${RM} ${WRKDIR}/man7/${FILE}
.endfor
	@${REINPLACE_CMD} -e "s,%%SITE_PERL%%,${SITE_PERL},g" ${WRKSRC}/Makefile
.if ${SUBPORT} != cvs
	@${REINPLACE_CMD} -e '/git-cvsexportcommit.perl/d; \
		/git-cvsimport.perl/d; \
		/git-cvsserver.perl/d; \
		/documented,gitcvs-migration/d; \
		s/git-cvsserver//' \
		${WRKSRC}/Makefile
.endif
.if ${SUBPORT} != p4
	@${REINPLACE_CMD} -e '/^SCRIPT_PYTHON += git-p4.py$$/d' \
		${WRKSRC}/Makefile
.endif
.if ${SUBPORT} != svn
	@${REINPLACE_CMD} -e '/git-svn.perl/d' ${WRKSRC}/Makefile
.endif
.if ${SUBPORT} == gui
	@${REINPLACE_CMD} -e "/exec wish/s,wish,${WISH}," \
		${WRKSRC}/gitk-git/gitk \
		${WRKSRC}/git-gui/git-gui--askpass
.endif

post-patch-CONTRIB-on:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL}," \
		${WRKSRC}/contrib/diff-highlight/Makefile

post-patch-GITWEB-off:
	@${REINPLACE_CMD} -e '/$$(MAKE) -C gitweb install/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL}," \
		${WRKSRC}/t/lib-gitweb.sh

.if ${SUBPORT} == p4 || ${PORT_OPTIONS:MCONTRIB}
post-build:
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

.if ${SUBPORT} == core
post-build-CONTRIB-on:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/contrib/diff-highlight
	${RM} ${WRKSRC}/contrib/diff-highlight/shebang.perl

post-install:
	(cd ${WRKDIR}/man1/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKDIR}/man5/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man5)
	(cd ${WRKDIR}/man7/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man7)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git-blame.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/completion/git-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-HTMLDOCS-on:
	# Manually remove the index.html symlink before installing, and then
	# recreate it after. This is necessary because the distfile is
	# extracted with --no-same-owner. If the distfile is extracted as a
	# non-root user then the symlink will have the incorrect owner.
	${RM} ${WRKDIR}/htmldocs/index.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/htmldocs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${LN} -s git.html ${STAGEDIR}${DOCSDIR}/index.html

post-install-SUBTREE-on:
	cd ${WRKSRC}/contrib/subtree && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} Makefile USE_ASCIIDOCTOR=1 \
		${MAKE_ARGS} install install-doc

post-install-CONTRIB-on:
	@${ECHO_MSG} "===> Installing contributed scripts"
	${MKDIR} ${STAGEDIR}${PREFIX}/share/git-core/contrib
	${RM} ${WRKSRC}/contrib/credential/netrc/test.netrc.gpg
	${CP} -R ${WRKSRC}/contrib/* ${STAGEDIR}${PREFIX}/share/git-core/contrib

post-install-GITWEB-on:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/gitweb.conf \
		${STAGEDIR}${ETCDIR}/gitweb.conf.sample

.elif ${SUBPORT} == gui

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/git-core \
		 ${STAGEDIR}${PREFIX}/share/git-gui/lib/msgs \
		 ${STAGEDIR}${PREFIX}/share/gitk/lib/msgs
	${INSTALL_SCRIPT} ${WRKSRC}/gitk-git/gitk \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/git-gui/git-gui \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${LN} ${STAGEDIR}${PREFIX}/libexec/git-core/git-gui \
		${STAGEDIR}${PREFIX}/libexec/git-core/git-citool
	${INSTALL_SCRIPT} ${WRKSRC}/git-gui/git-gui--askpass \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${INSTALL_DATA} ${WRKSRC}/git-gui/lib/tclIndex \
		${STAGEDIR}${PREFIX}/share/git-gui/lib/
	${INSTALL_DATA} ${WRKSRC}/git-gui/lib/*.ico \
		${STAGEDIR}${PREFIX}/share/git-gui/lib/
	${INSTALL_DATA} ${WRKSRC}/git-gui/lib/*.js \
		${STAGEDIR}${PREFIX}/share/git-gui/lib/
	${INSTALL_DATA} ${WRKSRC}/git-gui/lib/*.tcl \
		${STAGEDIR}${PREFIX}/share/git-gui/lib/
	${INSTALL_DATA} ${WRKSRC}/git-gui/po/*.msg \
		${STAGEDIR}${PREFIX}/share/git-gui/lib/msgs/
	${INSTALL_DATA} ${WRKSRC}/gitk-git/po/*.msg \
		${STAGEDIR}${PREFIX}/share/gitk/lib/msgs/
	${INSTALL_DATA} ${WRKDIR}/man1/git-citool.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/man1/git-gui.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/man1/gitk.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

.elif ${SUBPORT} == cvs

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/git-core
	${INSTALL_SCRIPT} ${WRKSRC}/git-cvsserver ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/git-cvsexportcommit \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${INSTALL_SCRIPT} ${WRKSRC}/git-cvsimport \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${INSTALL_SCRIPT} ${WRKSRC}/git-cvsserver \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${INSTALL_DATA} ${WRKDIR}/man1/git-cvsimport.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/man1/git-cvsexportcommit.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/man1/git-cvsserver.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/man7/gitcvs-migration.7 \
		${STAGEDIR}${MANPREFIX}/man/man7/

.elif ${SUBPORT} == p4

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/git-core
	${INSTALL_SCRIPT} ${WRKSRC}/git-p4.py \
		${STAGEDIR}${PREFIX}/libexec/git-core/git-p4
	${INSTALL_DATA} ${WRKDIR}/man1/git-p4.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

.elif ${SUBPORT} == svn

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/git-core
	${INSTALL_SCRIPT} ${WRKSRC}/git-svn \
		${STAGEDIR}${PREFIX}/libexec/git-core/
	${INSTALL_DATA} ${WRKDIR}/man1/git-svn.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
.endif

.include <bsd.port.mk>
