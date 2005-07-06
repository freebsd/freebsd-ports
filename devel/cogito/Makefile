# Ports collection makefile for: cogito
# Date created:		31 May 2005
# Whom:			Michael Seyfert <michaels@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	cogito
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/cogito/ \
		http://www.uk.kernel.org/pub/software/scm/cogito/ \
		http://www.us.kernel.org/pub/software/scm/cogito/ \
		http://www.jp.kernel.org/pub/software/scm/cogito/

MAINTAINER=	michaels@sdf.lonestar.org
COMMENT=	The Cogito Version Control System

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		rsync:${PORTSDIR}/net/rsync

USE_BZIP2=	yes
USE_GMAKE=	yes

# We set HOME to PREFIX. This will install the files in the proper location.
MAKE_ENV+=	HOME=${PREFIX} CPATH=${PREFIX}/include LIBRARY_PATH=${PREFIX}/lib
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

STRIP_FILES=	${PREFIX}/bin/git-apply \
		${PREFIX}/bin/git-cat-file \
		${PREFIX}/bin/git-check-files \
		${PREFIX}/bin/git-checkout-cache \
		${PREFIX}/bin/git-commit-tree \
		${PREFIX}/bin/git-convert-cache \
		${PREFIX}/bin/git-cvs2git \
		${PREFIX}/bin/git-diff-cache \
		${PREFIX}/bin/git-diff-files \
		${PREFIX}/bin/git-diff-helper \
		${PREFIX}/bin/git-diff-stages \
		${PREFIX}/bin/git-diff-tree \
		${PREFIX}/bin/git-export \
		${PREFIX}/bin/git-fsck-cache \
		${PREFIX}/bin/git-get-tar-commit-id \
		${PREFIX}/bin/git-http-pull \
		${PREFIX}/bin/git-init-db \
		${PREFIX}/bin/git-local-pull \
		${PREFIX}/bin/git-ls-files \
		${PREFIX}/bin/git-ls-tree \
		${PREFIX}/bin/git-merge-base \
		${PREFIX}/bin/git-merge-cache \
		${PREFIX}/bin/git-mktag \
		${PREFIX}/bin/git-pack-objects \
		${PREFIX}/bin/git-patch-id \
		${PREFIX}/bin/git-prune-packed \
		${PREFIX}/bin/git-read-tree \
		${PREFIX}/bin/git-receive-pack \
		${PREFIX}/bin/git-rev-list \
		${PREFIX}/bin/git-rev-parse \
		${PREFIX}/bin/git-rev-tree \
		${PREFIX}/bin/git-send-pack \
		${PREFIX}/bin/git-ssh-pull \
		${PREFIX}/bin/git-ssh-push \
		${PREFIX}/bin/git-stripspace \
		${PREFIX}/bin/git-tar-tree \
		${PREFIX}/bin/git-unpack-file \
		${PREFIX}/bin/git-unpack-objects \
		${PREFIX}/bin/git-update-cache \
		${PREFIX}/bin/git-verify-pack \
		${PREFIX}/bin/git-write-blob \
		${PREFIX}/bin/git-write-tree

CONTRIB_FILES=	${WRKDIR}/${DISTNAME}/contrib/gitfeedmaillist.sh \
		${WRKDIR}/${DISTNAME}/contrib/ciabot.pl

DOC_FILES=	${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/Documentation/diff-format.txt \
		${WRKDIR}/${DISTNAME}/Documentation/cvs-migration.txt \
		${WRKDIR}/${DISTNAME}/Documentation/diff-format.txt \
		${WRKDIR}/${DISTNAME}/Documentation/diffcore.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-apply-patch-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-apply.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-cat-file.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-check-files.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-checkout-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-commit-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-convert-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-diff-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-diff-files.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-diff-helper.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-diff-stages.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-diff-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-export.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-fsck-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-http-pull.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-init-db.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-local-pull.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-ls-files.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-ls-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-merge-base.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-merge-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-merge-one-file-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-mktag.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-prune-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-pull-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-read-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-resolve-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-rev-list.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-rev-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-ssh-pull.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-ssh-push.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-tag-script.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-tar-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-unpack-file.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-update-cache.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-verify-pack.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-write-blob.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git-write-tree.txt \
		${WRKDIR}/${DISTNAME}/Documentation/git.txt \
		${WRKDIR}/${DISTNAME}/Documentation/tutorial.txt

post-install:
	${STRIP_CMD} ${STRIP_FILES}
	${INSTALL_SCRIPT} ${CONTRIB_FILES} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOC_FILES} ${DOCSDIR}
.endif

.include <bsd.port.mk>
