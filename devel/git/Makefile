# Ports collection makefile for:	git
# Date created:				7 Feb 2006
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	1.6.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	software/scm/${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sign
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Distributed source code management tool

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Net/SMTP/SSL.pm:${PORTSDIR}/mail/p5-Net-SMTP-SSL
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

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
		git-merge-tree.1 \
		git-merge.1 \
		git-mergetool.1 \
		git-mktag.1 \
		git-mktree.1 \
		git-mv.1 \
		git-name-rev.1 \
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
		git-remote.1 \
		git-repack.1 \
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
		git-shell.1 \
		git-shortlog.1 \
		git-show-branch.1 \
		git-show-index.1 \
		git-show-ref.1 \
		git-show.1 \
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
MAN3=		Git.3
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
		gittutorial-2.7

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_BZIP2=	yes
USE_PERL5=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CURLDIR=${LOCALBASE} \
		NEEDS_LIBICONV=yes \
		OLD_ICONV=yes \
		PERL_PATH=${PERL} \
		LIBMD_SHA1=yes
MAKE_ARGS+=	prefix="${PREFIX}"
USE_OPENSSL=	yes
USE_RC_SUBR=	git_daemon

SHELLS=		/etc/shells

OPTIONS=	GUI "Enable building of GUI tools" on \
		SVN "Enable required dependencies for SVN tools" off \
		GITWEB "Install gitweb" off \
		P4  "Enable Perforce support" on \
		CVS "Enable CVS support" on \
		HTMLDOCS "Install additional documentation" off

.include <bsd.port.pre.mk>

.ifdef (WITH_HTMLDOCS)
RUN_DEPENDS+=	${LOCALBASE}/bin/asciidoc:${PORTSDIR}/textproc/asciidoc \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif

.if !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
USE_TK=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
MAN1+=		git-citool.1 \
		git-gui.1 \
		gitk.1
PLIST_SUB+=	GUI=""
MAKE_ENV+=	TCL_PATH=${TCLSH} TCLTK_PATH=${WISH}
.else
PLIST_SUB+=	GUI="@comment "
MAKE_ENV+=	NO_TCLTK=yes
.endif

.ifdef (WITH_SVN)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		svn:${PORTSDIR}/devel/subversion
PLIST_SUB+=	SVN=""
MAN1+=		git-svn.1
.else
PLIST_SUB+=	SVN="@comment "
.endif

.ifdef (WITH_GITWEB)
PLIST_SUB+=	GITWEB=""
.else
PLIST_SUB+=	GITWEB="@comment "
.endif

.ifdef (WITH_P4)
#USE_PYTHON=	yes
# Can't set USE_PYTHON here just yet.  See ports/89648.
# Instead we will do it this way:
.include "${PORTSDIR}/Mk/bsd.python.mk"
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
MAKE_ENV+=	PYTHON_PATH=${LOCALBASE}/bin/python
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
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sign \
		${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

post-patch:
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

post-build:
.ifdef (WITH_P4)
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/python|#!${PYTHON_CMD}|' \
		${WRKSRC}/contrib/p4import/git-p4import.py
	@${CP} ${WRKSRC}/contrib/p4import/git-p4import.py \
		${WRKSRC}/contrib/p4import/git-p4import
.endif

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/man1/${i} ${MANPREFIX}/man/man1/
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKDIR}/man5/${i} ${MANPREFIX}/man/man5/
.endfor
.for i in ${MAN7}
	${INSTALL_MAN} ${WRKDIR}/man7/${i} ${MANPREFIX}/man/man7/
.endfor

.ifdef (WITH_HTMLDOCS)
	${GMAKE} -C ${WRKSRC} install-html ${MAKE_ENV} ${MAKE_ARGS}
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

.ifdef (WITH_P4)
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/p4import/git-p4import \
		${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/fast-import/git-p4 \
		${PREFIX}/bin/
.endif

.ifdef (WITH_GITWEB)
	@${ECHO_MSG} "===> Installing gitweb files"
	${MKDIR} ${EXAMPLESDIR}/gitweb
	${INSTALL_DATA} ${WRKSRC}/gitweb/INSTALL ${EXAMPLESDIR}/gitweb/
	${INSTALL_DATA} ${WRKSRC}/gitweb/README ${EXAMPLESDIR}/gitweb/
	${INSTALL_DATA} ${WRKSRC}/gitweb/git-favicon.png ${EXAMPLESDIR}/gitweb/
	${INSTALL_DATA} ${WRKSRC}/gitweb/git-logo.png ${EXAMPLESDIR}/gitweb/
	${INSTALL_DATA} ${WRKSRC}/gitweb/gitweb.css ${EXAMPLESDIR}/gitweb/
	${INSTALL_SCRIPT} ${WRKSRC}/gitweb/gitweb.cgi ${EXAMPLESDIR}/gitweb/
.endif

	@${ECHO_MSG} "===> Updating ${SHELLS}"
	@${CP} ${SHELLS} ${SHELLS}.bak
	@(${GREP} -v ${PREFIX}/libexec/git-core/git-shell ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/libexec/git-core/git-shell) > ${SHELLS}
	@${RM} ${SHELLS}.bak

.ifdef (WITH_GITWEB)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
