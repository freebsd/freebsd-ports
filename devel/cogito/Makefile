# Ports collection makefile for: cogito
# Date created:		31 May 2005
# Whom:			Michael Seyfert <michaels@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	cogito
PORTVERSION=	0.10
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/cogito/ \
		http://www.uk.kernel.org/pub/software/scm/cogito/ \
		http://www.us.kernel.org/pub/software/scm/cogito/

MAINTAINER=	michaels@sdf.lonestar.org
COMMENT=	Cogito, GIT - the content tracker

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		rsync:${PORTSDIR}/net/rsync

USE_BZIP2=	yes
USE_GMAKE=	yes

# We set HOME to PREFIX, this is the easiest way to install in
# the proper location without patching.
MAKE_ENV+=	HOME=${PREFIX} CPATH=${PREFIX}/include LIBRARY_PATH=${PREFIX}/lib
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

STRIP_FILES=	${PREFIX}/bin/git-cat-file \
		${PREFIX}/bin/git-check-files \
		${PREFIX}/bin/git-checkout-cache \
		${PREFIX}/bin/git-commit-tree \
		${PREFIX}/bin/git-convert-cache \
		${PREFIX}/bin/git-diff-cache \
		${PREFIX}/bin/git-diff-files \
		${PREFIX}/bin/git-diff-tree \
		${PREFIX}/bin/git-diff-tree-helper \
		${PREFIX}/bin/git-export \
		${PREFIX}/bin/git-fsck-cache \
		${PREFIX}/bin/git-http-pull \
		${PREFIX}/bin/git-init-db \
		${PREFIX}/bin/git-local-pull \
		${PREFIX}/bin/git-ls-files \
		${PREFIX}/bin/git-ls-tree \
		${PREFIX}/bin/git-merge-base \
		${PREFIX}/bin/git-merge-cache \
		${PREFIX}/bin/git-mktag \
		${PREFIX}/bin/git-read-tree \
		${PREFIX}/bin/git-rev-list \
		${PREFIX}/bin/git-rev-tree \
		${PREFIX}/bin/git-rpull \
		${PREFIX}/bin/git-rpush \
		${PREFIX}/bin/git-tar-tree \
		${PREFIX}/bin/git-unpack-file \
		${PREFIX}/bin/git-update-cache \
		${PREFIX}/bin/git-write-blob \
		${PREFIX}/bin/git-write-tree

post-install:
	${STRIP_CMD} ${STRIP_FILES}
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/contrib/gitfeedmaillist.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/Documentation/core-git.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
