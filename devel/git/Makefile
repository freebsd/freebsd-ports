# Ports collection makefile for:	git
# Date created:				7 Feb 2006
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	1.7.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	git-core
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}
# We manually extract the htmldocs.
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Distributed source code management tool

MAKE_JOBS_SAFE=	yes

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
		git-check-ref-format.1 \
		git-checkout-index.1 \
		git-checkout.1 \
		git-cherry-pick.1 \
		git-cherry.1 \
		git-clean.1 \
		git-clone.1 \
		git-commit-tree.1 \
		git-commit.1 \
		git-config.1 \
		git-count-objects.1 \
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
		git-remote-helpers.1 \
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
		git-write-tree.1
MAN5=		gitattributes.5 \
		githooks.5 \
		gitignore.5 \
		gitmodules.5 \
		gitrepository-layout.5
MAN7=		gitcli.7 \
		gitglossary.7 \
		gittutorial.7 \
		gitcore-tutorial.7 \
		gitdiffcore.7 \
		gittutorial-2.7 \
		gitworkflows.7 \
		gitrevisions.7 \
		gitnamespaces.7

CONFLICTS?=	git-subversion-[0-9]*

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LIBMD_SHA1=yes \
		V=1
MAKE_ARGS+=	prefix="${PREFIX}"
USE_OPENSSL=	yes
USE_RC_SUBR=	git_daemon
WANT_PERL=	yes

CONFIGURE_ARGS=	--enable-pthreads=${PTHREAD_LIBS}

OPTIONS=	GUI "Enable building of GUI tools" off \
		SVN "Enable required dependencies for SVN tools" off \
		GITWEB "Install gitweb" off \
		CONTRIB "Install contributed scripts" on \
		P4 "Enable Perforce support" on \
		CVS "Enable CVS support" on \
		HTMLDOCS "Install additional documentation" off \
		PERL "Build perl based git tools" on \
		ICONV "Support for multiple character encodings" on \
		CURL "Support HTTP push and pull" on \
		ETCSHELLS "Modify /etc/shells" on

.include <bsd.port.options.mk>

.ifndef (WITH_DEBUG)
ALL_TARGET=	all strip
.endif

.ifdef (WITH_P4) || defined (WITH_CONTRIB)
USE_PYTHON=	yes
PLIST_SUB=	PYTHON_VER=${PYTHON_VER} PYTHON=""
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}/bin/python
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.ifdef (WITH_PERL)
USE_PERL5=	yes
MAKE_ENV+=	PERL_PATH=${PERL}
BUILD_DEPENDS+=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS+=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Net/SMTP/SSL.pm:${PORTSDIR}/mail/p5-Net-SMTP-SSL
MAN3=		Git.3
PLIST_SUB+=	PERLSUB=""
.else
MAKE_ENV+=	NO_PERL=1
PLIST_SUB+=	PERLSUB="@comment "
.endif

.ifdef (WITH_ICONV)
USE_ICONV=	yes
MAKE_ENV+=	NEEDS_LIBICONV=yes \
		ICONVDIR=${LOCALBASE}
.else
MAKE_ENV+=	NO_ICONV=1
.endif

.ifdef (WITH_CURL)
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

.ifdef (WITH_HTMLDOCS)
DISTFILES+=	${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif

.ifdef (WITH_GUI)
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

.ifdef (WITH_SVN)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion
PLIST_SUB+=	SVN=""
MAN1+=		git-svn.1
.else
PLIST_SUB+=	SVN="@comment "
RMMAN1+=	git-svn.1
.endif

.ifdef (WITH_GITWEB)
PLIST_SUB+=	GITWEB=""
.else
PLIST_SUB+=	GITWEB="@comment "
.endif

.ifdef (WITH_GITWEB) && !defined (WITH_PERL)
IGNORE=	using GITWEB support requires PERL support
.endif

.ifdef (WITH_CONTRIB)
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

.ifdef (WITH_P4)
PLIST_SUB+=	P4=""
.else
PLIST_SUB+=	P4="@comment "
.endif

.ifdef (WITH_CVS)
MAN1+=		git-cvsimport.1 git-cvsexportcommit.1 git-cvsserver.1
MAN7+=		gitcvs-migration.7
PLIST_SUB+=	CVS=""
RUN_DEPENDS+=	cvsps:${PORTSDIR}/devel/cvsps
.else
PLIST_SUB+=	CVS="@comment "
RMMAN1+=	git-cvsimport.1 git-cvsexportcommit.1 git-cvsserver.1
RMMAN7+=	gitcvs-migration.7
.endif

.ifdef (WITH_ETCSHELLS)
SHELLS=		/etc/shells
PLIST_SUB+=	ETCSHELLS=""
.else
PLIST_SUB+=	ETCSHELLS="@comment "
.endif

.if defined (MAINTAINER_MODE)
DISTFILES+=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sign \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}.sign
.if defined (WITH_HTMLDOCS)
DISTFILES+=	${PORTNAME}-htmldocs-${PORTVERSION}${EXTRACT_SUFX}.sign
.endif
verify: fetch
.for FILE in ${DISTFILES:N*.sign}
	@${ECHO_MSG} "Checking ${FILE}${EXTRACT_SUFX}"
	@gpg --verify ${DISTDIR}/${FILE}${EXTRACT_SUFX}.sign ${DISTDIR}/${FILE}${EXTRACT_SUFX} 2>/dev/null || ${ECHO_MSG} "Bad signature!"
.endfor
.endif

post-extract:
.if defined (WITH_HTMLDOCS)
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
.ifndef (WITH_CVS)
	@${REINPLACE_CMD} -e '/git-cvsexportcommit.perl/d; \
		/git-cvsimport.perl/d; \
		/git-cvsserver.perl/d; \
		/documented,gitcvs-migration/d; \
		s/git-cvsserver//' \
		${WRKSRC}/Makefile
.endif
.ifndef (WITH_SVN)
	@${REINPLACE_CMD} -e '/git-svn.perl/d' ${WRKSRC}/Makefile
.endif
.ifndef (WITH_GITWEB)
	@${REINPLACE_CMD} -e '/$$(MAKE) -C gitweb install/d' ${WRKSRC}/Makefile
.endif

post-build:
.ifdef (WITH_P4) || defined (WITH_CONTRIB)
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
.if defined (WITH_HTMLDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKDIR}/htmldocs/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	-${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/mach/perllocal.pod
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
.ifdef (WITH_CONTRIB)
	@${ECHO_MSG} "===> Installing contributed scripts"
	${MKDIR} ${PREFIX}/share/git-core/contrib
	(cd ${WRKSRC}/contrib/ && \
		${COPYTREE_SHARE} \* ${PREFIX}/share/git-core/contrib)
.endif
.ifdef (WITH_P4)
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/p4import/git-p4import ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/fast-import/git-p4 ${PREFIX}/bin/
.endif
.ifdef (WITH_ETCSHELLS)
	@${ECHO_MSG} "===> Updating ${SHELLS}"
	@${CP} ${SHELLS} ${SHELLS}.bak
	@(${GREP} -v ${PREFIX}/libexec/git-core/git-shell ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/libexec/git-core/git-shell) > ${SHELLS}
	@${RM} ${SHELLS}.bak
.endif
.ifdef (WITH_GITWEB) || defined (WITH_CONTRIB)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
