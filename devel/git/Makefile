# Created by: Eric Anholt
# $FreeBSD$

PORTNAME=	git
DISTVERSION=	2.21.0
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/software/scm/git
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${DISTVERSION}${EXTRACT_SUFX}
# We manually extract the htmldocs.
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	garga@FreeBSD.org
COMMENT?=	Distributed source code management tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL?=	git-gui-[0-9]* git-subversion-[0-9]* git-lite-[0-9]*

USERS=		git_daemon
GROUPS=		git_daemon

SUB_FILES=	pkg-message gitweb.conf

GNU_CONFIGURE=	yes
USES=		autoreconf gmake iconv shebangfix ssl tar:xz
CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	DEVELOPER=
MAKE_ENV+=	V=1
USE_RC_SUBR=	git_daemon
SHEBANG_FILES=	*.perl */*.perl */*/*.perl */*.pl */*/*.pl */*/*/*.pl \
		t/*/*/pre t/*/*/post t/Git-SVN/Utils/*.t \
		git-p4.py \
		contrib/hg-to-git/hg-to-git.py \
		contrib/hooks/update-paranoid \
		contrib/hooks/multimail/post-receive.example \
		contrib/hooks/multimail/git_multimail.py \
		contrib/hooks/multimail/migrate-mailhook-config \
		contrib/fast-import/import-zips.py \
		contrib/remote-helpers/git-remote-bzr \
		contrib/remote-helpers/git-remote-hg \
		contrib/credential/netrc/git-credential-netrc \
		contrib/buildsystems/generate contrib/contacts/git-contacts \
		contrib/svn-fe/svnrdump_sim.py \
		templates/hooks--fsmonitor-watchman.sample
TEST_TARGET=	test

CONFIGURE_ARGS=	--enable-pthreads=-pthread ac_cv_header_libcharset_h=no

OPTIONS_RADIO=	PCRE_VERSION
OPTIONS_RADIO_PCRE_VERSION=	PCRE PCRE2
OPTIONS_DEFINE=	GUI SVN GITWEB CONTRIB P4 CVS HTMLDOCS PERL ICONV CURL \
		SEND_EMAIL NLS SUBTREE
OPTIONS_DEFAULT=	CONTRIB P4 CVS PERL GITWEB ICONV CURL SEND_EMAIL PCRE \
			SUBTREE
OPTIONS_SUB=	yes

GITWEB_DESC=	Install gitweb
CONTRIB_DESC=	Install contributed scripts
P4_DESC=	Enable Perforce support
PCRE2_DESC=	Use Perl Compatible Regular Expressions (v2)
CVS_DESC=	Enable CVS support
HTMLDOCS_DESC=	Install additional documentation
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

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	libpcre1

PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=	libpcre

SEND_EMAIL_IMPLIES=	PERL
SEND_EMAIL_RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
			p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

ICONV_USES=		iconv
ICONV_MAKE_ARGS_OFF=	NO_ICONV=1

CURL_MAKE_ENV=		CURLDIR=${LOCALBASE}
CURL_BUILD_DEPENDS=	curl:ftp/curl
CURL_RUN_DEPENDS=	curl:ftp/curl
CURL_LIB_DEPENDS=	libexpat.so:textproc/expat2
CURL_MAKE_ARGS_OFF=	NO_CURL=1 NO_EXPAT=1

HTMLDOCS_DISTFILES=	${PORTNAME}-htmldocs-${DISTVERSION}${EXTRACT_SUFX}

GUI_USES=		tk
GUI_MAKE_ARGS=		TCL_PATH=${TCLSH} TCLTK_PATH=${WISH}
GUI_MAKE_ARGS_OFF=	NO_TCLTK=yes

# While this port does not explicitly honor WITH_SUBVERSION_VER knob it does
# depend upon devel/p5-subversion, which does honor that knob. If you want
# to have git use devel/subversion18 it will be brought in through
# devel/p5-subversion if you set WITH_SUBVERSION_VER=18. Otherwise
# devel/subversion will be brought in.
SVN_RUN_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
			p5-subversion>=0:devel/p5-subversion

SUBTREE_BUILD_DEPENDS=	xmlto:textproc/xmlto \
			asciidoc:textproc/asciidoc \
			docbook-xml>0:textproc/docbook-xml

CVS_RUN_DEPENDS=	cvsps:devel/cvsps

.include <bsd.port.options.mk>

# This is intentionally not exposed as an option.
.if defined(STRIP) && ${STRIP} != ""
ALL_TARGET=	all strip
.endif

.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
USES+=		python
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if empty(PORT_OPTIONS:MGUI)
RMMAN1+=	git-citool.1 \
		git-gui.1 \
		gitk.1
.endif

.if empty(PORT_OPTIONS:MSVN)
RMMAN1+=	git-svn.1
.endif

.if empty(PORT_OPTIONS:MCVS)
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

post-patch-CONTRIB-on:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL}," \
		${WRKSRC}/contrib/diff-highlight/Makefile

post-patch-CVS-off:
	@${REINPLACE_CMD} -e '/git-cvsexportcommit.perl/d; \
		/git-cvsimport.perl/d; \
		/git-cvsserver.perl/d; \
		/documented,gitcvs-migration/d; \
		s/git-cvsserver//' \
		${WRKSRC}/Makefile

post-patch-SVN-off:
	@${REINPLACE_CMD} -e '/git-svn.perl/d' ${WRKSRC}/Makefile

post-patch-GITWEB-off:
	@${REINPLACE_CMD} -e '/$$(MAKE) -C gitweb install/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL}," ${WRKSRC}/t/gitweb-lib.sh

post-patch-P4-off:
	@${REINPLACE_CMD} -e '/^SCRIPT_PYTHON += git-p4.py$$/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/contrib/subtree/git-subtree.sh

.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
post-build:
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

post-build-CONTRIB-on:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/contrib/diff-highlight
	${RM} ${WRKSRC}/contrib/diff-highlight/shebang.perl

post-install:
	(cd ${WRKDIR}/man1/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKDIR}/man5/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man5)
	(cd ${WRKDIR}/man7/ && ${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man7)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git-blame.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/git/

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
		${MAKE_CMD} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} install install-doc

post-install-CONTRIB-on:
	@${ECHO_MSG} "===> Installing contributed scripts"
	${MKDIR} ${STAGEDIR}${PREFIX}/share/git-core/contrib
	${CP} -R ${WRKSRC}/contrib/* ${STAGEDIR}${PREFIX}/share/git-core/contrib
	# Symlink the completions from the contrib directory to where they
	# will be useful
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${LN} -s ../../share/git-core/contrib/completion/git-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-CONTRIB-off:
	# Install the contrib completions anyway
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/completion/git-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-P4-on:
	${INSTALL_SCRIPT} ${WRKSRC}/git-p4.py ${STAGEDIR}${PREFIX}/bin/

post-install-GITWEB-on:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/gitweb.conf \
		${STAGEDIR}${ETCDIR}/gitweb.conf.sample

.include <bsd.port.mk>
