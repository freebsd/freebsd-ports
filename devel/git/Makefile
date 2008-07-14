# Ports collection makefile for:	git
# Date created:				7 Feb 2006
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	1.5.6.2
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-manpages-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Distributed source code management tool

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		cvsps:${PORTSDIR}/devel/cvsps-devel \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Net/SMTP/SSL.pm:${PORTSDIR}/mail/p5-Net-SMTP-SSL
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	cogito-0.1[012] git-4.*

MAN1=		git-add.1 \
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
		git-cvsexportcommit.1 \
		git-cvsimport.1 \
		git-cvsserver.1 \
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
		git-svn.1 \
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
		gitignore.5 \
		gitmodules.5

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_BZIP2=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CURLDIR=${LOCALBASE} \
		NEEDS_LIBICONV=yes \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PYTHON_PATH=${LOCALBASE}/bin/python \
		PERL_PATH=${PERL} \
		LIBMD_SHA1=yes
MAKE_ARGS+=	prefix="${PREFIX}"
USE_OPENSSL=	yes
USE_RC_SUBR=	git_daemon

SHELLS=		/etc/shells

OPTIONS=	GUI "Enable building of GUI tools" on \
		SVN "Enable required dependencies for SVN tools" off \
		GITWEB "Install gitweb" off

.include <bsd.port.pre.mk>

.ifndef (WITHOUT_GUI)
MAN1+=		git-citool.1 \
		git-gui.1 \
		gitk.1
PLIST_SUB+=	GUI=""
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
MAKE_ENV+=	TCL_PATH=tclsh8.4 TCLTK_PATH=wish8.4
.else
PLIST_SUB+=	GUI="@comment "
MAKE_ENV+=	NO_TCLTK=yes
.endif

.ifdef (WITH_SVN)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		svn:${PORTSDIR}/devel/subversion
.endif

.ifdef (WITH_GITWEB)
PLIST_SUB+=	GITWEB=""
.else
PLIST_SUB+=	GITWEB="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|OPENSSLDIR|OPENSSLBASE|g' ${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man3|man/man3|' ${WRKSRC}/perl/Makefile.PL

post-build:
	@${SED} -e'1s|#!/usr/bin/python|#!${PYTHON_CMD}|' \
		${WRKSRC}/contrib/p4import/git-p4import.py > \
		${WRKSRC}/contrib/p4import/git-p4import

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

	-${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/mach/perllocal.pod
	${MKDIR} ${PREFIX}/share/emacs/site-lisp/git
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp/git
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/git.el \
		${PREFIX}/share/emacs/site-lisp/git/
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/vc-git.el \
		${PREFIX}/share/emacs/site-lisp/git/
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/git.el    \
		${PREFIX}/lib/xemacs/site-lisp/git/git.el
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/git/vc-git.el \
		${PREFIX}/lib/xemacs/site-lisp/git/vc-git.el

	${INSTALL_SCRIPT} ${WRKSRC}/contrib/p4import/git-p4import \
		${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/fast-import/git-p4 \
		${PREFIX}/bin/
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
	@(${GREP} -v ${PREFIX}/bin/git-shell ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/git-shell) > ${SHELLS}
	@${RM} ${SHELLS}.bak

.ifdef (WITH_GITWEB)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
