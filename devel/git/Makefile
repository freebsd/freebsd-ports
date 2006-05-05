# Ports collection makefile for:	git
# Date created:				7 Feb 2006
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Distributed source code management tool

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		cvsps:${PORTSDIR}/devel/cvsps-devel \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	cogito-0.1[012] git-4.*

MAN1=		git-add.1 \
		git-am.1 \
		git-annotate.1 \
		git-apply.1 \
		git-applymbox.1 \
		git-applypatch.1 \
		git-archimport.1 \
		git-bisect.1 \
		git-blame.1 \
		git-branch.1 \
		git-cat-file.1 \
		git-check-ref-format.1 \
		git-checkout-index.1 \
		git-checkout.1 \
		git-cherry-pick.1 \
		git-cherry.1 \
		git-clean.1 \
		git-clone-pack.1 \
		git-clone.1 \
		git-commit-tree.1 \
		git-commit.1 \
		git-convert-objects.1 \
		git-count-objects.1 \
		git-cvsexportcommit.1 \
		git-cvsimport.1 \
		git-cvsserver.1 \
		git-daemon.1 \
		git-describe.1 \
		git-diff-files.1 \
		git-diff-index.1 \
		git-diff-stages.1 \
		git-diff-tree.1 \
		git-diff.1 \
		git-fetch-pack.1 \
		git-fetch.1 \
		git-fmt-merge-msg.1 \
		git-format-patch.1 \
		git-fsck-objects.1 \
		git-get-tar-commit-id.1 \
		git-grep.1 \
		git-hash-object.1 \
		git-http-fetch.1 \
		git-http-push.1 \
		git-imap-send.1 \
		git-index-pack.1 \
		git-init-db.1 \
		git-local-fetch.1 \
		git-log.1 \
		git-lost-found.1 \
		git-ls-files.1 \
		git-ls-remote.1 \
		git-ls-tree.1 \
		git-mailinfo.1 \
		git-mailsplit.1 \
		git-merge.1 \
		git-merge-base.1 \
		git-merge-index.1 \
		git-merge-one-file.1 \
		git-merge-tree.1 \
		git-mktag.1 \
		git-mktree.1 \
		git-mv.1 \
		git-name-rev.1 \
		git-pack-objects.1 \
		git-pack-redundant.1 \
		git-parse-remote.1 \
		git-patch-id.1 \
		git-peek-remote.1 \
		git-prune-packed.1 \
		git-prune.1 \
		git-pull.1 \
		git-push.1 \
		git-read-tree.1 \
		git-rebase.1 \
		git-receive-pack.1 \
		git-relink.1 \
		git-repack.1 \
		git-repo-config.1 \
		git-request-pull.1 \
		git-rerere.1 \
		git-reset.1 \
		git-resolve.1 \
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
		git-show.1 \
		git-ssh-fetch.1 \
		git-ssh-upload.1 \
		git-status.1 \
		git-stripspace.1 \
		git-svnimport.1 \
		git-symbolic-ref.1 \
		git-tag.1 \
		git-tar-tree.1 \
		git-unpack-file.1 \
		git-unpack-objects.1 \
		git-update-index.1 \
		git-update-ref.1 \
		git-update-server-info.1 \
		git-upload-pack.1 \
		git-var.1 \
		git-verify-pack.1 \
		git-verify-tag.1 \
		git-whatchanged.1 \
		git-write-tree.1 \
		gitk.1
MAN7=		git.7

USE_PERL5=	yes
USE_PYTHON=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CURLDIR=${LOCALBASE} \
		NEEDS_LIBICONV=yes \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PYTHON_PATH=${LOCALBASE}/bin/python
MAKE_ARGS+=	prefix="${PREFIX}"

.include <bsd.port.mk>
