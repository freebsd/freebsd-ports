# Created by: Eric Anholt
# $FreeBSD$

PORTNAME=	git
PORTVERSION=	1.8.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}
# We manually extract the htmldocs.
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Distributed source code management tool

PROJECTHOST=	git-core

MAN1=		git.1 \
		git-add.1 \
		git-am.1 \
		git-annotate.1 \
		git-apply.1 \
		git-archimport.1 \
		git-archive.1 \
		git-bisect.1 \
		git-blame.1 \
		git-branch.1 \
		git-bundle.1 \
		git-cat-file.1 \
		git-check-attr.1 \
		git-check-ignore.1 \
		git-check-mailmap.1 \
		git-check-ref-format.1 \
		git-checkout-index.1 \
		git-checkout.1 \
		git-cherry-pick.1 \
		git-cherry.1 \
		git-clean.1 \
		git-clone.1 \
		git-column.1 \
		git-commit-tree.1 \
		git-commit.1 \
		git-config.1 \
		git-count-objects.1 \
		git-credential.1 \
		git-credential-cache--daemon.1 \
		git-credential-cache.1 \
		git-credential-store.1 \
		git-daemon.1 \
		git-describe.1 \
		git-diff-files.1 \
		git-diff-index.1 \
		git-difftool.1 \
		git-diff-tree.1 \
		git-diff.1 \
		git-fast-export.1 \
		git-fast-import.1 \
		git-fetch-pack.1 \
		git-fetch.1 \
		git-filter-branch.1 \
		git-fmt-merge-msg.1 \
		git-for-each-ref.1 \
		git-format-patch.1 \
		git-fsck-objects.1 \
		git-fsck.1 \
		git-gc.1 \
		git-get-tar-commit-id.1 \
		git-grep.1 \
		git-hash-object.1 \
		git-help.1 \
		git-http-backend.1 \
		git-http-fetch.1 \
		git-http-push.1 \
		git-imap-send.1 \
		git-index-pack.1 \
		git-init-db.1 \
		git-init.1 \
		git-instaweb.1 \
		git-log.1 \
		git-lost-found.1 \
		git-ls-files.1 \
		git-ls-remote.1 \
		git-ls-tree.1 \
		git-mailinfo.1 \
		git-mailsplit.1 \
		git-merge-base.1 \
		git-merge-file.1 \
		git-merge-index.1 \
		git-merge-one-file.1 \
		git-mergetool.1 \
		git-merge-tree.1 \
		git-merge.1 \
		git-mergetool--lib.1 \
		git-mktag.1 \
		git-mktree.1 \
		git-mv.1 \
		git-name-rev.1 \
		git-notes.1 \
		git-p4.1 \
		git-pack-objects.1 \
		git-pack-redundant.1 \
		git-pack-refs.1 \
		git-parse-remote.1 \
		git-patch-id.1 \
		git-peek-remote.1 \
		git-prune-packed.1 \
		git-prune.1 \
		git-pull.1 \
		git-push.1 \
		git-quiltimport.1 \
		git-read-tree.1 \
		git-rebase.1 \
		git-receive-pack.1 \
		git-reflog.1 \
		git-relink.1 \
		git-remote-ext.1 \
		git-remote-fd.1 \
		git-remote-testgit.1 \
		git-remote.1 \
		git-repack.1 \
		git-replace.1 \
		git-repo-config.1 \
		git-request-pull.1 \
		git-rerere.1 \
		git-reset.1 \
		git-rev-list.1 \
		git-rev-parse.1 \
		git-revert.1 \
		git-rm.1 \
		git-send-email.1 \
		git-send-pack.1 \
		git-sh-setup.1 \
		git-sh-i18n.1 \
		git-sh-i18n--envsubst.1 \
		git-shell.1 \
		git-shortlog.1 \
		git-show-branch.1 \
		git-show-index.1 \
		git-show-ref.1 \
		git-show.1 \
		git-stage.1 \
		git-stash.1 \
		git-status.1 \
		git-stripspace.1 \
		git-submodule.1 \
		git-symbolic-ref.1 \
		git-tag.1 \
		git-tar-tree.1 \
		git-unpack-file.1 \
		git-unpack-objects.1 \
		git-update-index.1 \
		git-update-ref.1 \
		git-update-server-info.1 \
		git-upload-archive.1 \
		git-upload-pack.1 \
		git-var.1 \
		git-verify-pack.1 \
		git-verify-tag.1 \
		git-web--browse.1 \
		git-whatchanged.1 \
		git-write-tree.1 \
		gitremote-helpers.1 \
		gitweb.1
MAN5=		gitattributes.5 \
		githooks.5 \
		gitignore.5 \
		gitmodules.5 \
		gitrepository-layout.5 \
		gitweb.conf.5
MAN7=		gitcli.7 \
		gitcredentials.7 \
		gitglossary.7 \
		gittutorial.7 \
		gitcore-tutorial.7 \
		gitdiffcore.7 \
		gittutorial-2.7 \
		gitworkflows.7 \
		gitrevisions.7 \
		gitnamespaces.7

CONFLICTS?=	git-subversion-[0-9]*

USERS=	git_daemon
GROUPS=	git_daemon

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	V=1
MAKE_ARGS+=	prefix="${PREFIX}"
USE_OPENSSL=	yes
USE_RC_SUBR=	git_daemon

CONFIGURE_ARGS=	--enable-pthreads=-pthread

OPTIONS_DEFINE=	GUI SVN GITWEB CONTRIB P4 CVS HTMLDOCS PERL ICONV CURL \
		ETCSHELLS NLS
OPTIONS_DEFAULT=	CONTRIB P4 CVS PERL ICONV CURL ETCSHELLS NLS

GITWEB_DESC=	Install gitweb
CONTRIB_DESC=	Install contributed scripts
P4_DESC=	Enable Perforce support
CVS_DESC=	Enable CVS support
HTMLDOCS_DESC=	Install additional documentation
ETCSHELLS_DESC=	Modify /etc/shells

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
MAKE_ARGS+=	NO_GETTEXT=yes
.endif

# This is intentionally not exposed as an option.
.ifndef (WITH_DEBUG)
ALL_TARGET=	all strip
.endif

.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER} PYTHON=""
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
MAKE_ENV+=	PERL_PATH=${PERL}
BUILD_DEPENDS+=	p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS+=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL
MAN3=		Git.3 \
		Git::I18N.3 \
		Git::SVN::Editor.3 \
		Git::SVN::Fetcher.3 \
		Git::SVN::Memoize::YAML.3 \
		Git::SVN::Prompt.3 \
		Git::SVN::Ra.3 \
		Git::SVN::Utils.3
PLIST_SUB+=	PERLSUB=""
.else
MAKE_ENV+=	NO_PERL=1
PLIST_SUB+=	PERLSUB="@comment "
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
MAKE_ENV+=	NEEDS_LIBICONV=yes \
		ICONVDIR=${ICONV_PREFIX}
CONFIGURE_ARGS+=	--with-iconv=${ICONV_PREFIX}
.else
MAKE_ENV+=	NO_ICONV=1
.endif

.if ${PORT_OPTIONS:MCURL}
MAKE_ENV+=	CURLDIR=${LOCALBASE}
BUILD_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
PLIST_SUB+=	CURL=""
.else
MAKE_ENV+=	NO_CURL=1 \
		NO_EXPAT=1
PLIST_SUB+=	CURL="@comment "
.endif

# Always fetch the htmldocs distfile in maintainer mode.
# Always include it when building distinfo (makesum)
.if ${PORT_OPTIONS:MHTMLDOCS} || make(makesum) || (defined(MAINTAINER_MODE) && make(fetch))
DISTFILES+=	${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MGUI}
USE_TK=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
MAN1+=		git-citool.1 \
		git-gui.1 \
		gitk.1
PLIST_SUB+=	GUI=""
MAKE_ARGS+=	TCL_PATH=${TCLSH} TCLTK_PATH=${WISH}
.else
RMMAN1+=	git-citool.1 \
		git-gui.1 \
		gitk.1
PLIST_SUB+=	GUI="@comment "
MAKE_ARGS+=	NO_TCLTK=yes
.endif

# While this port does not explicity honor WITH_SUBVERSION_VER knob it does
# depend upon devel/p5-subversion, which does honor that knob. If you want
# to have git use devel/subversion16 it will be brought in through
# devel/p5-subversion if you set WITH_SUBVERSION_VER=16. Otherwise
# devel/subversion will be brought in.
.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion
PLIST_SUB+=	SVN=""
MAN1+=		git-svn.1
.else
PLIST_SUB+=	SVN="@comment "
RMMAN1+=	git-svn.1
.endif

.if ${PORT_OPTIONS:MGITWEB}
PLIST_SUB+=	GITWEB=""
.else
PLIST_SUB+=	GITWEB="@comment "
.endif

.if ${PORT_OPTIONS:MGITWEB} && empty(PORT_OPTIONS:MPERL)
IGNORE=	using GITWEB support requires PERL support
.endif

.if ${PORT_OPTIONS:MCONTRIB}
PLIST_SUB+=	CONTRIB=""
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
		asciidoc:${PORTSDIR}/textproc/asciidoc \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450
MAN1+=		git-subtree.1
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.if ${PORT_OPTIONS:MP4}
PLIST_SUB+=	P4=""
.else
PLIST_SUB+=	P4="@comment "
.endif

.if ${PORT_OPTIONS:MCVS}
MAN1+=		git-cvsimport.1 git-cvsexportcommit.1 git-cvsserver.1
MAN7+=		gitcvs-migration.7
PLIST_SUB+=	CVS=""
RUN_DEPENDS+=	cvsps:${PORTSDIR}/devel/cvsps
.else
PLIST_SUB+=	CVS="@comment "
RMMAN1+=	git-cvsimport.1 git-cvsexportcommit.1 git-cvsserver.1
RMMAN7+=	gitcvs-migration.7
.endif

.if ${PORT_OPTIONS:METCSHELLS}
SHELLS=		/etc/shells
PLIST_SUB+=	ETCSHELLS=""
.else
PLIST_SUB+=	ETCSHELLS="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MHTMLDOCS}
	@${MKDIR} ${WRKDIR}/htmldocs
	@cd ${WRKDIR}/htmldocs && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS}
.endif

post-patch:
.for FILE in ${RMMAN1}
	@${RM} ${WRKDIR}/man1/${FILE}
.endfor
.for FILE in ${RMMAN7}
	@${RM} ${WRKDIR}/man7/${FILE}
.endfor
	@${REINPLACE_CMD} -e 's|share/man/man3|man/man3|' ${WRKSRC}/perl/Makefile.PL
.if empty(PORT_OPTIONS:MCVS)
	@${REINPLACE_CMD} -e '/git-cvsexportcommit.perl/d; \
		/git-cvsimport.perl/d; \
		/git-cvsserver.perl/d; \
		/documented,gitcvs-migration/d; \
		s/git-cvsserver//' \
		${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MSVN)
	@${REINPLACE_CMD} -e '/git-svn.perl/d' ${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MGITWEB)
	@${REINPLACE_CMD} -e '/$$(MAKE) -C gitweb install/d' ${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MP4)
	@${REINPLACE_CMD} -e '/^SCRIPT_PYTHON += git-p4.py$$/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/contrib/subtree/git-subtree.sh
.endif

post-build:
.if ${PORT_OPTIONS:MP4} || ${PORT_OPTIONS:MCONTRIB}
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/python|#!${PYTHON_CMD}|' \
		${WRKSRC}/contrib/p4import/git-p4import.py
	@${CP} ${WRKSRC}/contrib/p4import/git-p4import.py \
		${WRKSRC}/contrib/p4import/git-p4import
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

post-install:
	(cd ${WRKDIR}/man1/ && ${COPYTREE_SHARE} \* ${MANPREFIX}/man/man1)
	(cd ${WRKDIR}/man5/ && ${COPYTREE_SHARE} \* ${MANPREFIX}/man/man5)
	(cd ${WRKDIR}/man7/ && ${COPYTREE_SHARE} \* ${MANPREFIX}/man/man7)
.if ${PORT_OPTIONS:MHTMLDOCS}
	# Manually remove the index.html symlink before installing, and then
	# recreate it after. This is necessary because the distfile is
	# extracted with --no-same-owner. If the distfile is extracted as a
	# non-root user then the symlink will have the incorrect owner.
	${RM} -f ${WRKDIR}/htmldocs/index.html
	${MKDIR} ${DOCSDIR}
	(cd ${WRKDIR}/htmldocs/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
	${LN} -s ${DOCSDIR}/git.html ${DOCSDIR}/index.html
.endif
	-${RM} -f ${PREFIX}/lib/perl5/${PERL_VER}/mach/perllocal.pod
	${MKDIR} ${PREFIX}/share/emacs/site-lisp/git
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp/git
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git.el \
		${PREFIX}/share/emacs/site-lisp/git/
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git-blame.el \
		${PREFIX}/share/emacs/site-lisp/git/
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/git.el    \
		${PREFIX}/lib/xemacs/site-lisp/git/git.el
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/git-blame.el \
		${PREFIX}/lib/xemacs/site-lisp/git/git-blame.el
.if ${PORT_OPTIONS:MCONTRIB}
	@${ECHO_MSG} "===> Installing contributed scripts"
	${MKDIR} ${PREFIX}/share/git-core/contrib
	${CP} -R ${WRKSRC}/contrib/* ${PREFIX}/share/git-core/contrib
	cd ${WRKSRC}/contrib/subtree && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} install install-doc
.endif
.if ${PORT_OPTIONS:MP4}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/p4import/git-p4import ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/git-p4.py ${PREFIX}/bin/
.endif
.if ${PORT_OPTIONS:METCSHELLS}
	@${ECHO_MSG} "===> Updating ${SHELLS}"
	@${CP} ${SHELLS} ${SHELLS}.bak
	@(${GREP} -v ${PREFIX}/libexec/git-core/git-shell ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/libexec/git-core/git-shell) > ${SHELLS}
	@${RM} ${SHELLS}.bak
.endif
.if ${PORT_OPTIONS:MGITWEB} || ${PORT_OPTIONS:MCONTRIB}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
